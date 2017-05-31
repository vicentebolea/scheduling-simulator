#pragma once
#include <string>

namespace scheduler_simulator {

class Options {
  public:
    Options () = default;
    virtual ~Options () = default;

    virtual std::string get_str(std::string) = 0;
};
}
