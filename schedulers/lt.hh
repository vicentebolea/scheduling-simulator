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

    //! Whether there are remaining elements to schedule.
    virtual bool is_next() override;

  private:
    //! Proccess abstraction
    struct Proc {
      int id = 0;
      int cpu_time = 0;
      int number_tickets = 0;
      int borrowed_tickets = 0;
      std::shared_ptr<Proc> borrowed_proc;
      int resource = -1;
    };

    //! Get the proccess with the max amout of tickets
    std::shared_ptr<Proc> schedule_proc();

    // Proccesses lists
    std::list<std::shared_ptr<Proc>> ready_list;
    std::list<std::shared_ptr<Proc>> locked_list;
    std::shared_ptr<Proc> scheduled_proc;

    //! Resources map (Solves priority inversion)
    std::map<int, std::shared_ptr<Proc>> resources_used;
    
    //! Boost list, it enables ticket compesation
    std::map<int, int> boost_list;

    uint32_t quantum = 0, current_quantum = 0;
    uint32_t total_tickets = 0;
};

}
