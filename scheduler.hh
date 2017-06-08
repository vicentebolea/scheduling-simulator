#pragma once
#include <vector>
#include <string>

namespace scheduler_simulator {

class Scheduler {
  public:
    Scheduler () = default;
    virtual ~Scheduler () = default; 

    virtual bool schedule(std::vector<std::string> in = std::vector<std::string>()) = 0;
    virtual bool is_next() = 0;
};
}
