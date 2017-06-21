#include "rr.hh"
#include <iostream>
#include <algorithm>
#include "../options.hh"

using namespace scheduler_simulator;
using namespace std;

SchedulerRR::SchedulerRR (Options* opt) {
  quantum = stoi(opt->get_str("-q"));
  current_quantum = quantum;
}

//! @return true if more proccess remains or current process
//!         did not finish its cpu bursts.
bool SchedulerRR::is_next() {
  return !proc_queue.empty() || scheduled_proc.second >= 0 || !input_lines.empty();
}

//! Algorithm high-level description:
//!   1. At time 0, it sorts the input.
//!   2. If the scheduled proccess needs to be changed
//!
//!      1. Terminate it if it needs no more cpu.
//!      2. Push it back to the proc_queue.
//!
//!   3. Try to get new processes from the input list.
//!   4. Schedule next process from the proc_queue.
bool SchedulerRR::schedule() {
  if (time == 0) {
    input_lines.sort([] (auto& a, auto& b) { return stoi(a[1]) < stoi(b[1]); });
  }

  bool queue_was_empty = false;

  // If we need to schedule a new process.
  if (scheduled_proc.second == 0 or current_quantum == quantum) {

    // Process is terminated
    if (scheduled_proc.second == 0) {
      cout << time << ": terminate P" << scheduled_proc.first << endl;

    // Its quantum is over
    } else if (current_quantum == quantum and scheduled_proc.second > 0) {
      proc_queue.push(scheduled_proc);
    }

    queue_was_empty = proc_queue.empty();

    // Try to get more processes from the input and
    // add them to the proc_queue
    if (proc_queue.empty()) {
      while (is_next_line()) {
        auto in = input_lines.front();
        input_lines.pop_front();

        int proc_id    = stoi(in[0]);
        int burst_time = stoi(in[2]);
        proc_queue.push({proc_id, burst_time});
      }
    }

    // If we got new process from the input, try to re-schedule
    if (!proc_queue.empty()) {
      auto next_proc = proc_queue.front();
      proc_queue.pop();

      // Re-schedule new process
      if (scheduled_proc.first != next_proc.first) {
        scheduled_proc = next_proc;
        cout << time << ": schedule P" << scheduled_proc.first << endl;
      } 
    }
    current_quantum = 0; // Initialize current quantum.
  }

  //Try to get more processes from the input.
  if (!queue_was_empty) {
    while (is_next_line()) {
      auto in = input_lines.front();
      input_lines.pop_front();

      int proc_id = stoi(in[0]);
      int burst_time = stoi(in[2]);
      proc_queue.push({proc_id, burst_time});
    }
  }

  // Increment quantum if proccess is scheduled
  scheduled_proc.second--;
  if (scheduled_proc.second < 0)
    current_quantum = quantum;
  else
    current_quantum++;
  time++;

  return true;
}
