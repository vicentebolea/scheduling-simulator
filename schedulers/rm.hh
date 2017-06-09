#pragma once
#include "../scheduler.hh"
#include <map>
#include <list>
#include <utility>

namespace scheduler_simulator {

class Options;

class SchedulerRM : public Scheduler {
  public:
    SchedulerRM (Options*);
    virtual ~SchedulerRM () override = default;

    virtual bool schedule() override;
    virtual bool is_next() override;

  private:
    bool can_it_be_scheduled();

    struct Proc {
      int id = 0;
      int period = 0;
      int cpu_time = 0;
      int last_scheduled_time = 0;
    };

    std::list<Proc> proc_list;
    Proc* scheduled_proc;

    int current_proc_time = 0;
    uint32_t end_time = 0;
    bool deadly_end = false;
};

}
