#include "cli_options.hh"

using namespace scheduler_simulator;

CLIOptions::CLIOptions(int argc, char** argv) {

  for (int i = 1; i < argc; i += 2)
    options.insert({argv[i], argv[i+1]});
}

std::string CLIOptions::get_str(std::string key) {
  return options[key];
}
