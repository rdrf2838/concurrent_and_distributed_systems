#define BOOST_TEST_MODULE test module name
#include <boost/test/unit_test.hpp>

#include "occ.h"

BOOST_AUTO_TEST_CASE(first_test)
{
  int i = 1;
  BOOST_TEST(i);
  BOOST_TEST(i == 2);
}

BOOST_AUTO_TEST_CASE(second_test)
{
  cds::patterns::app::occ::Validator validator{};
  validator.print_data();
  BOOST_TEST(true);
}