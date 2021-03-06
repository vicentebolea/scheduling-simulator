#pragma once
#include "interactive_scheduler.hh"
#include <map>
#include <queue>
#include <utility>

namespace scheduler_simulator {

class Options;

class SchedulerRR : public InteractiveScheduler {
  public:
    SchedulerRR (Options*);
    virtual ~SchedulerRR () override = default;

    // Schedule next process using RR algorithm
    virtual bool schedule() override;

    // Whether there are more process to be executed.
    virtual bool is_next() override;

  private:
    //! Represents ready_queue.
    std::queue<std::pair<int, int>> proc_queue;

    //! Current scheduled process.
    //! @note sentinel value {0,-1}
    std::pair<int, int> scheduled_proc = {0,-1};

    uint32_t quantum = 0;
    uint32_t current_quantum = 0;
};

}
