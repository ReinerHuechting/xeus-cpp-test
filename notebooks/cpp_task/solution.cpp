#include "task.h"

int count_char(std::string const& str, char c) {
  int count = 0;
  for (char ch : str) {
    if (ch == c) {
      ++count;
    }
  }
  return count;
}
