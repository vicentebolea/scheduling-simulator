#include "text_reader.hh"
#include <sstream>

using namespace scheduler_simulator;
using namespace std;

TextReader::TextReader(Options* ops) {
  string file_name = ops->get_str("input_path");
  ifs.open(file_name);
}

bool TextReader::is_next() {
  return ifs.good();
}

std::vector<std::string> TextReader::next() {
  char line [256];
  ifs.readline(line, 256);
  
  stringstream ss(line);

  vector<string> output;
  string token;
  while (ss >> token)
    output.push_back(token);

  return output;
}
