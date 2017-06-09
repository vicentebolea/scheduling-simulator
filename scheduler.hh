#pragma once
#include <vector>
#include <string>
#include <queue>

namespace scheduler_simulator {

class Scheduler {
  public:
    Scheduler () = default;

    // This method will schedule the next proccess.
    //
    // It is intended to be inherited and override for each
    // kind of scheduling algorithm.
    //
    // @arg in is a vector of string which represents a new process,
    //      If no vector is passed it will reschedule its previous process.
    virtual bool schedule() = 0;

    // Returns whether the scheduler is done.
    // @returns false if all its processes has terminated
    virtual bool is_next() = 0;

    void parse_line(std::vector<std::string> in) {
      input_lines.push(in);
    }

  protected:
    virtual ~Scheduler () = default; 
    uint32_t time = 0;
    
    std::queue<std::vector<std::string>> input_lines;
};

}
