#pragma once
#include <vector>
#include <string>

namespace scheduler_simulator {

class Scheduler {
  protected:
    virtual ~Scheduler () = default; 

  public:
    Scheduler () = default;

    // This method will schedule the next proccess.
    //
    // It is intended to be inherited and override for each
    // kind of scheduling algorithm.
    //
    // @arg in is a vector of string which represents a new process,
    //      If no vector is passed it will reschedule its previous process.
    virtual bool schedule(std::vector<std::string> in = std::vector<std::string>()) = 0;

    // Returns whether the scheduler is done.
    // @returns false if all its processes has terminated
    virtual bool is_next() = 0;
};

}
