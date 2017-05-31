#include "stdin_reader.hh"
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace scheduler_simulator;
using namespace std;

StdinReader::StdinReader() {
  fseek(stdin, 0L, SEEK_SET);
}

bool StdinReader::is_next() {
  char c = fgetc(stdin);
  if (c == EOF)
    return false;
  else {
    ungetc(c, stdin);
    return true;
  }
}

std::vector<std::string> StdinReader::next() {
  char line [256];
  fgets(line, 256, stdin);
  stringstream ss(line);

  vector<string> output;
  string token;
  while (ss >> token)
    output.push_back(token);

  return output;
}
