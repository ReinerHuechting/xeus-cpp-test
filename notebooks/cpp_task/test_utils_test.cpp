#include "test_utils.h"

#include <iostream>
#include <string>
#include <vector>

int foo() { return 42; }

std::vector<int> bar() { return {1, 2, 3}; }

int main() {
  std::vector<int> correct = {1, 2, 3};
  std::vector<int> wrong = {4, 5, 6};

  ASSERT(foo() == 3);
  ASSERT_EQUAL(foo(), 3);
  ASSERT(foo() == 42);
  ASSERT_EQUAL(foo(), 42);

  ASSERT(bar() == wrong);
  ASSERT_EQUAL(bar(), wrong);
  ASSERT(bar() == correct);
  ASSERT_EQUAL(bar(), correct);

  ASSERT(bar() == (std::vector<int>{1, 5, 9}));
  ASSERT_EQUAL(bar(), (std::vector<int>{1, 5, 9}));

  return 0;
}
