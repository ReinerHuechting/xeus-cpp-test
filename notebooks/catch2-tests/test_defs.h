#ifndef TEST_DEFS_H
#define TEST_DEFS_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

template <typename T>
std::string format(std::vector<T> vec) {
  std::ostringstream oss;
  oss << "[";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    oss << *it;
    if (it + 1 != vec.end()) {
      oss << ", ";
    }
  }
  oss << "]";
  return oss.str();
}

template <typename T, typename U>
std::string message_neq(std::vector<T> left, std::vector<U> right) {
  std::ostringstream oss;
  oss << "Vectors are not equal: " << std::endl;
  oss << "  Left:  " << format(left) << std::endl;
  oss << "  Right: " << format(right) << std::endl;
  return oss.str();
}

template <typename T, typename U>
std::string message_neq(T left, U right) {
  std::ostringstream oss;
  oss << "Values are not equal: " << std::endl;
  oss << "  " << left << " != " << right << std::endl;
  return oss.str();
}

std::string message_ok() {
  std::ostringstream oss;
  oss << "OK" << std::endl;
  return oss.str();
}

template <typename L, typename R>
bool assert_eq(std::vector<L> left, std::vector<R> right) {
  if (left.size() != right.size()) {
    std::cout << message_neq(left, right);
    return false;
  }
  for (int i = 0; i < left.size(); i++) {
    if (left[i] != right[i]) {
      std::cout << message_neq(left, right);
      return false;
    }
  }
  std::cout << message_ok();
  return true;
}

template <typename L, typename R>
bool assert_eq(L left, R right) {
  if (left != right) {
    std::cout << message_neq(left, right);
    return false;
  }
  std::cout << message_ok();
  return true;
}

#endif
