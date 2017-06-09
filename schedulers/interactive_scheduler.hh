#pragma once
#include "../scheduler.hh"
#include <iostream>
#include <algorithm>

namespace scheduler_simulator {

class InteractiveScheduler : public Scheduler {
  public:
    InteractiveScheduler () = default;
    virtual ~InteractiveScheduler () = default;

    virtual bool schedule() = 0;
    virtual bool is_next()  = 0;

  protected:
    bool is_next_line();
};

}
