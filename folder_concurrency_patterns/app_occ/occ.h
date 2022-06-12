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

namespace cds::patterns::app::occ {
    const int data_num = 5;

    typedef struct Node Node_t;
    typedef struct Data Data_t;

    struct Node {
        Node_t *prev, *next;
        Data_t *data;
    };

    struct Data {
        int read_len;
        int *read_idxs;

        int *read_vals;
        int *read_time;

        int write_len;
        int *write_idxs;

        int *write_vals_next;
        int write_time_next;

        Data();
        Data(const Data &that);
        void print_data();
    };

    class Validator {
    private:
        Node *head;
        int vals[data_num], vals_time[data_num];
        int timestamp;
        std::unordered_map<int, bool> results;
        std::queue<Data_t *> q;
        std::mutex mut;
        std::condition_variable cv;
        static void clean_data(Data_t *);

    public:
        Validator();
        ~Validator();
        bool read(Data_t *);
        bool write(Data_t *);
        void process_data();
        void print_data();
    };

    void ValidatorRunner(Validator &);
}
namespace cpac = cds::patterns::app::occ;