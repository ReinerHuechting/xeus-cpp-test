#ifndef TEST_DEFS_H
#define TEST_DEFS_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace test_utils {
namespace {

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

}  // namespace

namespace message {

template <typename T, typename U>
std::string neq(std::vector<T> left, std::vector<U> right) {
  std::ostringstream oss;
  oss << "[FAILURE]" << std::endl;
  oss << "  Left:  " << format(left) << std::endl;
  oss << "  Right: " << format(right) << std::endl;
  return oss.str();
}

template <typename T, typename U>
std::string neq(T left, U right) {
  std::ostringstream oss;
  oss << "[FAILURE] " << "  " << left << " != " << right << std::endl;
  return oss.str();
}

std::string ok() {
  std::ostringstream oss;
  oss << "OK" << std::endl;
  return oss.str();
}

}  // namespace message

namespace assert {

template <typename L, typename R>
bool eq(std::string test_case, std::vector<L> left, std::vector<R> right) {
  std::cout << "TEST CASE: " << test_case << ": ";
  if (left.size() != right.size()) {
    std::cout << message::neq(left, right);
    return false;
  }
  for (int i = 0; i < left.size(); i++) {
    if (left[i] != right[i]) {
      std::cout << message::neq(left, right);
      return false;
    }
  }
  std::cout << message::ok();
  return true;
}

template <typename L, typename R>
bool eq(std::string test_case, L left, R right) {
  std::cout << "TEST CASE: " << test_case << ": ";
  if (left != right) {
    std::cout << message::neq(left, right);
    return false;
  }
  std::cout << message::ok();
  return true;
}

}  // namespace assert

}  // namespace test_utils

#define ASSERT_EQ(left, right)                      \
  {                                                 \
    std::ostringstream oss;                         \
    oss << #left << " == " << #right;               \
    test_utils::assert::eq(oss.str(), left, right); \
  }

#endif
