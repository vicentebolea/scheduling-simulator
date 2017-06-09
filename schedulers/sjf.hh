#pragma once
#include "interactive_scheduler.hh"
#include <map>

namespace scheduler_simulator {

class SchedulerSJF : public InteractiveScheduler {
  public:
    SchedulerSJF () = default;
    virtual ~SchedulerSJF () = default;

    virtual bool schedule() override;
    virtual bool is_next() override;

  private:

    std::map<int, int> remaining_times;
    int scheduled_proc;
};

}
