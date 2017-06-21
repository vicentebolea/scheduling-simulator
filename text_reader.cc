#include "text_reader.hh"
#include "options.hh"
#include <sstream>
#include <string.h>

using namespace scheduler_simulator;
using namespace std;

TextReader::TextReader(Options* ops) {
  string file_name = ops->get_str("-i");
  ifs.open(file_name);
}

bool TextReader::is_next() {
  return !(ifs.peek() == EOF);
}

//! 
std::vector<std::string> TextReader::next() {
  char line [SCHEDULER_SIMULATOR_INPUT_LINE_LENGTH];
  ifs.getline(line, SCHEDULER_SIMULATOR_INPUT_LINE_LENGTH);
  
  stringstream ss(line);

  vector<string> output;
  string token;
  while (ss >> token)
    output.push_back(token);

  return output;
}
