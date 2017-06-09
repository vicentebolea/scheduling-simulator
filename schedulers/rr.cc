#include "rr.hh"
#include <iostream>
#include <algorithm>
#include "../options.hh"

using namespace scheduler_simulator;
using namespace std;

SchedulerRR::SchedulerRR (Options* opt) {
  quantum = atoi(opt->get_str("-q").c_str());
  current_quantum = quantum;
}

bool SchedulerRR::is_next() {
  return !fifo_queue.empty() || scheduled_proc.second >= 0;
}

bool SchedulerRR::schedule(std::vector<std::string> in) {
  if (!is_next() && in.size() == 0) return true;

  if (in.size() != 0) {
    int proc_id = atoi(in[0].c_str());
    int burst_time = atoi(in[2].c_str());
    fifo_queue.push({proc_id, burst_time});
  }

  // Reschedule
  if (current_quantum == quantum) {
    current_quantum = 0;

    if (!fifo_queue.empty()) {
      auto next_proc = fifo_queue.front();

      // Re-schedule new process
      if (scheduled_proc.first != next_proc.first) {

        // Readd previously scheduled proccess
        if (scheduled_proc.second > 0) {
          fifo_queue.push(scheduled_proc);
        }

        scheduled_proc = next_proc;
        cout << time << ": schedule P" << scheduled_proc.first << endl;
        fifo_queue.pop();
      }
    }
  }

  if (scheduled_proc.second == 0) {
    cout << time << ": terminate P" << scheduled_proc.first << endl;
  }

  scheduled_proc.second--;
  current_quantum++;
  this->time++;

  return true;
}
