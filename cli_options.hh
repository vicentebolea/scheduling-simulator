#pragma once
#include "options.hh"
#include <memory>
#include <map>
#include <string>

namespace scheduler_simulator {

class CLIOptions: public Options {
  public:
    CLIOptions(int argc, char** argv);
    ~CLIOptions() = default; 

    // It returns the value corresponding to the given key
    virtual std::string get_str(std::string) override;

  private:
    std::map<std::string, std::string> options;
};
}
