#pragma once
#include "../scheduler.hh"
#include <map>
#include <list>
#include <utility>
#include <memory>

namespace scheduler_simulator {

class Options;

class SchedulerEDF : public Scheduler {
  public:
    SchedulerEDF (Options*);
    virtual ~SchedulerEDF () override = default;

    virtual bool schedule() override;
    virtual bool is_next() override;

  private:
    void initialize();
    void schedule_proc();

    struct Proc {
      int id = 0;
      int period = 0;
      int cpu_time = 0;
      int last_scheduled_time = 0;
      int consumed_cpu = 0;
    };

    std::list<std::shared_ptr<Proc>> ready_list;
    std::list<std::shared_ptr<Proc>> proc_list;
    std::shared_ptr<Proc> scheduled_proc;

    uint32_t end_time = 0;
    bool deadly_end = false;
};

}
