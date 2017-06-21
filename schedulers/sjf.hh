#pragma once
#include "interactive_scheduler.hh"
#include <map>

namespace scheduler_simulator {

class SchedulerSJF: public InteractiveScheduler {
  public:
    SchedulerSJF () = default;
    virtual ~SchedulerSJF () = default;

    //! At every call finds the shortest job and schedule it.
    virtual bool schedule() override;

    //! Returns whether the scheduler is done.
    virtual bool is_next() override;

  private:
    //! Map containing all the alive processes.
    std::map<int, int> remaining_times;

    //! -1 is the sentinel value for no-op
    int scheduled_proc = -1; 
};

}
