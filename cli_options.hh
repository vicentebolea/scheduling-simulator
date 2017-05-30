#pragma once
#include "options.hh"
#include <memory>
#include <map>
#include <string>

namespace scheduler_simulator {

class CLIOptions: public Options {
  public:
    CLIOptions(int argc, char** argv);
    ~CLIOptions();

    virtual std::string get_str(std::string) override;

  private:
    std::map<std::string, std::string> options;
};
