#pragma once
#include "interactive_scheduler.hh"
#include <map>
#include <queue>
#include <utility>
#include <memory>

namespace scheduler_simulator {

class Options;

class SchedulerLT : public InteractiveScheduler {
  public:
    SchedulerLT (Options*);
    virtual ~SchedulerLT () override = default;

    virtual bool schedule() override;
    virtual bool is_next() override;

  private:
    struct Proc {
      int id = 0;
      int cpu_time = 0;
      int number_tickets = 0;
      int borrowed_tickets = 0;
      std::shared_ptr<Proc> borrowed_proc;
      int resource = -1;
    };

    std::shared_ptr<Proc> schedule_proc();

    std::list<std::shared_ptr<Proc>> ready_list;
    std::list<std::shared_ptr<Proc>> locked_list;
    std::map<int,std::shared_ptr<Proc>> resources_used;
    std::map<int,int> boost_list;
    std::shared_ptr<Proc> scheduled_proc;

    uint32_t quantum = 0, current_quantum = 0;
    uint32_t total_tickets = 0;
};

}
