#include <iostream>
#include <thread>
#include <vector>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <mutex>
#include <condition_variable>
#include <string>
#include <random>
#include "occ.h"

namespace cds::patterns::app::occ {

    void Data::print_data() {
        std::printf("read_len: %d\n", read_len);
        for (int i = 0; i < read_len; i++) {
            std::printf("idx: %d val: %d time %d\n", read_idxs[i], read_vals[i], read_time[i]);
        }
        std::printf("write_len: %d\n", write_len);
        for (int i = 0; i < write_len; i++) {
            std::printf("idx: %d val: %d time %d\n", write_idxs[i], write_vals_next[i], write_time_next);
        }
    }

    Data::Data() : 
    // write_vals_prev{}, write_time_prev{}, 
    read_len{}, read_time{}, read_idxs{}, read_vals{}, write_idxs{}, write_len{}, write_vals_next{}, write_time_next{} {}

    Data::Data(const Data &that) {
        read_len = that.read_len;
        read_idxs = new int[read_len];
        std::copy(that.read_idxs, that.read_idxs + read_len, read_idxs);

        read_vals = new int[read_len];
        std::copy(that.read_vals, that.read_vals + read_len, read_vals);
        read_time = new int[read_len];
        std::copy(that.read_time, that.read_time + read_len, read_time);

        write_len = that.write_len;
        write_idxs = new int[write_len];
        std::copy(that.write_idxs, that.write_idxs + write_len, write_idxs);

        // write_vals_prev = new int [write_len];
        // write_time_prev = new int [write_len];

        write_vals_next = new int[write_len];
        std::copy(that.write_vals_next, that.write_vals_next + write_len, write_vals_next);
        write_time_next = that.write_time_next;
    }

    Validator::Validator(): 
    mut{}, cv{}, vals{}, vals_time{}, timestamp{1} {
        auto *p_node = new Node_t{};
        auto *p_data = new Data_t{};
        p_data->read_len = data_num;
        p_data->read_idxs = new int[data_num]{};

        p_data->read_time = new int[data_num]{};
        p_data->read_vals = new int[data_num]{};

        p_data->write_len = data_num;
        p_data->write_idxs = new int[data_num]{};

        p_data->write_vals_next = new int[data_num]{};
        p_data->write_time_next = 0;

        p_node->data = p_data;
        p_node->next = p_node->prev = p_node;
        head = p_node;
    }

    bool Validator::read(Data_t *p_data) {
        std::unique_lock<std::mutex> ul(mut);

        // For each idx of data requested, load data and last modified into struct
        for (int i = 0; i < p_data->read_len; i++) {
            int curr_idx = p_data->read_idxs[i];
            p_data->read_vals[i] = vals[curr_idx];
            p_data->read_time[i] = vals_time[curr_idx];
        }
        p_data->write_time_next = timestamp;

        // Increment counter
        timestamp++;

        // TODO: Add input validation
        return true;
    }

    bool Validator::write(Data_t *p_data) {
        // Assumption: writes are a subset of reads
        std::unique_lock<std::mutex> ul(mut);

        // Copy data to a new struct
        int id = p_data->write_time_next;
        auto *p_data_cpy = new Data_t(*p_data);

        // Store in queue (to be processed)
        q.push(p_data_cpy);

        // Wait for write to be approved/rejected
        cv.wait(ul);

        return results[id];
        // return true;
    }

    void Validator::process_data() {
        std::unique_lock<std::mutex> ul(mut);

        // For each proposed write to data (i.e. node to insert)
        while (!q.empty()) {
            Data_t *p_data = q.front();
            q.pop();
            Node_t *curr = head->prev;

            // Initialise a copy of current data
            int temp_vals[data_num]{}, temp_time[data_num]{};
            std::copy(vals, vals + data_num, temp_vals);
            std::copy(vals_time, vals_time + data_num, temp_time);
            while (true) {
                bool is_valid_snapshot = true;

                // Check if proposed write to data has a valid read
                for (int i = 0; i < p_data->read_len; i++) {
                    int curr_idx = p_data->read_idxs[i];
                    if (temp_time[curr_idx] != p_data->read_time[i]) {
                        is_valid_snapshot = false;
                        break;
                    }
                }

                if (is_valid_snapshot) {
                    // If valid read, break as we found a possible location to insert data
                    break;
                } else {

                    // Otherwise, we need to check an earlier node
                    // Update our copied data with the earlier modification times as well
                    Data_t *p_data_snap = curr->data;

                    for (int i = 0; i < p_data_snap->read_len; i++) {
                        int curr_idx = p_data_snap->read_idxs[i];
                        temp_time[curr_idx] = p_data_snap->read_time[i];
                        temp_vals[curr_idx] = p_data_snap->read_vals[i];
                    }
                    curr = curr->prev;
                }
            }

            // Node before the correct position to insert new data
            Node_t *insert_pos = curr;

            // Set of all modified values in proposed write
            std::unordered_set<int> modified_idxs(p_data->write_idxs, p_data->write_idxs + p_data->write_len);
            bool is_successful = true;

            // For each following node, check that none of its reads and writes clash with later node entries
            while (true) {
                curr = curr->next;
                if (curr == head) {
                    break;
                } else {

                    // Check clashes with reads
                    bool is_valid = true;
                    Data_t *data_p_curr = curr->data;
                    for (int i = 0; i < data_p_curr->read_len; i++) {
                        int curr_idx = data_p_curr->read_idxs[i];
                        if (modified_idxs.find(curr_idx) != modified_idxs.end()) {
                            is_valid = false;
                            break;
                        }
                    }

                    // Check clashes with writes
                    for (int i = 0; i < data_p_curr->write_len; i++) {
                        int curr_idx = data_p_curr->write_idxs[i];
                        if (modified_idxs.find(curr_idx) != modified_idxs.end()) {
                            is_valid = false;
                            break;
                        }
                    }
                    if (!is_valid) {
                        is_successful = false;
                        break;
                    }
                }
            }
            int id = p_data->write_time_next;

            if (is_successful) {
                // If successful, update results and insert node at position
                results[id] = true;
                auto *p_node_new = new Node_t{};
                p_node_new->data = p_data;
                Node_t *tmp = insert_pos->next;
                insert_pos->next = p_node_new;
                p_node_new->prev = insert_pos;
                p_node_new->next = tmp;
                tmp->prev = p_node_new;
                for (int i = 0; i < p_data->write_len; i++) {
                    int curr_idx = p_data->write_idxs[i];
                    // p_data->write_vals_prev[i] = vals[curr_idx];
                    vals[curr_idx] = p_data->write_vals_next[i];
                    // p_data->write_time_prev[i] = vals_time[curr_idx];
                    vals_time[curr_idx] = p_data->write_time_next;
                }
            } else {
                // If unsuccessful, update results and free allocated data
                results[id] = false;
                clean_data(p_data);
            }
        }

        // Unlock and notify waiting threads
        ul.unlock();
        cv.notify_all();
    }

    Validator::~Validator() {
        // Iterate through linked list and free everything
        Node_t s{};
        s.next = head;
        head->prev->next = &s;
        Node_t *curr = head;
        while (curr != &s) {
            Node_t *tmp = curr->next;
            clean_data(curr->data);
            delete curr;
            curr = tmp;
        }
    }

    void Validator::clean_data(Data_t *data) {
        delete[] data->read_idxs;

        delete[] data->read_time;
        delete[] data->read_vals;

        delete[] data->write_idxs;

        // delete[] data->write_vals_prev;
        // delete[] data->write_time_prev;

        delete[] data->write_vals_next;

        delete data;
    }

    void Validator::print_data() {
        std::unique_lock<std::mutex> ul(mut);
        int temp_vals[data_num]{}, temp_time[data_num]{};
        Node_t *curr = head;
        while (true) {
            Data_t *p_data = curr->data;
            std::printf("t: %5d\n", p_data->write_time_next);
            std::printf("READS:\n");
            std::printf("      IDXS:");
            for (int i = 0; i < p_data->read_len; i++) {
                int curr_idx = p_data->read_idxs[i];
                std::printf(" %5d", curr_idx);
            }
            std::printf("\n     TIMES:");
            for (int i = 0; i < p_data->read_len; i++) {
                // int curr_idx = p_data->read_idxs[i];
                std::printf(" %5d", p_data->read_time[i]);
            }
            std::printf("\n      VALS:");
            for (int i = 0; i < p_data->read_len; i++) {
                // int curr_idx = p_data->read_idxs[i];
                std::printf(" %5d", p_data->read_vals[i]);
            }
            std::printf("\nWRITES:\n      IDXS:");
            for (int i = 0; i < p_data->write_len; i++) {
                int curr_idx = p_data->write_idxs[i];
                std::printf(" %5d", curr_idx);
            }
            std::printf("\n  TIME_NEW:");
            for (int i = 0; i < p_data->write_len; i++) {
                int curr_idx = p_data->write_idxs[i];
                temp_time[curr_idx] = p_data->write_time_next;
                std::printf(" %5d", temp_time[curr_idx]);
            }
            std::printf("\n  VALS_NEW:");
            for (int i = 0; i < p_data->write_len; i++) {
                int curr_idx = p_data->write_idxs[i];
                temp_vals[curr_idx] = p_data->write_vals_next[i];
                std::printf(" %5d", temp_vals[curr_idx]);
            }
            std::printf("\n\nIDXS:");
            for (int i = 0; i < data_num; i++) {
                std::printf(" %5d", i);
            }
            std::printf("\nTIME:");
            for (int i = 0; i < data_num; i++) {
                std::printf(" %5d", temp_time[i]);
            }
            std::printf("\nDATA:");
            for (int i = 0; i < data_num; i++) {
                std::printf(" %5d", temp_vals[i]);
            }
            std::printf("\n\n");
            if (curr == head->prev) {
                break;
            } else {
                curr = curr->next;
            }
        }
    }

    void ValidatorRunner(Validator &validator) {
        // Main thread for validator, keep processing data
        for (int i = 0; i < 10; i++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            validator.process_data();
            // validator.print_data();
       }
        validator.print_data();
    }
}
