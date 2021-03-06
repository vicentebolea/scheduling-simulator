#pragma once
#include <vector>
#include <string>
#include <list>

namespace scheduler_simulator {

class Scheduler {
  //friend scheduler_factory;
  public:
    Scheduler () = default;

    virtual ~Scheduler () = default; 

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
      input_lines.push_back(in);
    }

  protected:
    uint32_t time = 0;
    
    std::list<std::vector<std::string>> input_lines;
};

}
