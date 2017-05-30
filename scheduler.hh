#pragma once

namespace scheduler_simulator {

class Scheduler {
  public:
    Scheduler () = default;
    virtual ~Scheduler (); 

    virtual bool schedule(input&) = 0;
};
}
