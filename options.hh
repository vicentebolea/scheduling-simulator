#pragma once
#include <string>

namespace scheduler_simulator {

class Options {
  public:
    Options () = default;
    virtual ~Options () = default;

    // It returns the value corresponding to the given key
    virtual std::string get_str(std::string) = 0;
};
}
