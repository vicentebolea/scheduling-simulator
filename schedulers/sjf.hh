#pragma once
#include "../scheduler.hh"
#include <map>

namespace scheduler_simulator {

class SchedulerSJF : public Scheduler {
  public:
    SchedulerSJF () = default;
    virtual ~SchedulerSJF () = default;

    virtual bool schedule(std::vector<std::string> in) override;
    virtual bool is_next() override;

  private:
    std::map<int, int> remaining_times;
    int scheduled_proc;
    uint32_t time = 0;
};

}
