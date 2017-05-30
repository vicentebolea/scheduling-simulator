#pragma once
#include <string>

namespace scheduler_simulator {

class Options {
  public:
    Options ();
    virtual ~Options () = 0;

    virtual std::string get_str(std::string) = 0;
};
}
