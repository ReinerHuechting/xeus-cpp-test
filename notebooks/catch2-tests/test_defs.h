#ifndef TEST_DEFS_H
#define TEST_DEFS_H

#include <iostream>

template <typename L, typename R>
bool assert_eq(L left, R right) {
  if (left != right) {
    std::cout << "Assertion failed: " << left << " == " << right << std::endl;
    return false;
  }
  std::cout << "OK" << std::endl;
  return true;
}

#endif
