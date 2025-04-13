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

template <typename T>
std::string format(T value) {
  std::ostringstream oss;
  oss << value;
  return oss.str();
}
}  // namespace

namespace message {

std::string failed() { return "[FAILED] "; }
std::string ok() { return "[OK]     "; }

template <typename T, typename U>
std::string neq(T left, U right) {
  std::ostringstream oss;
  oss << " (" << format(left) << " != " << format(right) << ")";
  return oss.str();
}

}  // namespace message

namespace check {

template <typename L, typename R>
bool eq(std::vector<L> left, std::vector<R> right) {
  if (left.size() != right.size()) {
    return false;
  }
  for (int i = 0; i < left.size(); i++) {
    if (left[i] != right[i]) {
      return false;
    }
  }
  return true;
}

template <typename L, typename R>
bool eq(L left, R right) {
  if (left != right) {
    return false;
  }
  return true;
}

}  // namespace check

}  // namespace test_utils

#define ASSERT_EQ(left, right)                      \
  {                                                 \
    std::ostringstream oss;                         \
    oss << #left << " == " << #right;               \
    test_utils::assert::eq(oss.str(), left, right); \
  }

#define ASSERT(e)               \
  {                             \
    if (!(e)) {                 \
      std::cout << "[FAILED] "; \
      std::cout << #e;          \
      std::cout << std::endl;   \
    } else {                    \
      std::cout << "[OK]     "; \
      std::cout << #e;          \
      std::cout << std::endl;   \
    }                           \
  }

#define ASSERT_EQUAL(left, right)                         \
  {                                                       \
    if (!test_utils::check::eq(left, right)) {            \
      std::cout << test_utils::message::failed();         \
      std::cout << #left << " == " << #right;             \
      std::cout << test_utils::message::neq(left, right); \
      std::cout << std::endl;                             \
    } else {                                              \
      std::cout << test_utils::message::ok();             \
      std::cout << #left << " == " << #right;             \
      std::cout << std::endl;                             \
    }                                                     \
  }

#endif
