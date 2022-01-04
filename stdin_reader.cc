#include "stdin_reader.hh"

#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

using namespace scheduler_simulator;

StdinReader::StdinReader() { }

//! Interesting method to find if we are about to reach EOF
bool StdinReader::is_next() {
  return EOF != std::cin.peek();
}

//! Read the next line from stdin
std::vector<std::string> StdinReader::next() {
  std::stringstream s;
  std::cin.get(*s.rdbuf()).ignore();

  return {std::istream_iterator<std::string>(s),
    std::istream_iterator<std::string>()};
}
