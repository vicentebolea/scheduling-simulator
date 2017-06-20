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

bool SchedulerRR::is_next() {
  return !fifo_queue.empty() || scheduled_proc.second >= 0 || !input_lines.empty();
}

bool SchedulerRR::schedule() {
  if (time == 0) {
    input_lines.sort([] (auto& a, auto& b) { return stoi(a[1]) < stoi(b[1]); });
  }

  bool was_empty = false;
  if (scheduled_proc.second == 0 or current_quantum == quantum) {
    if (scheduled_proc.second == 0) {
      cout << time << ": terminate P" << scheduled_proc.first << endl;

    } else if (current_quantum == quantum and scheduled_proc.second > 0) {
      fifo_queue.push(scheduled_proc);
    }

    was_empty = fifo_queue.empty();
    if (fifo_queue.empty()) {
      while (is_next_line()) {
        auto in = input_lines.front();
        input_lines.pop_front();

        int proc_id = stoi(in[0]);
        int burst_time = stoi(in[2]);
        fifo_queue.push({proc_id, burst_time});
      }
    }

    if (!fifo_queue.empty()) {
      auto next_proc = fifo_queue.front();
      fifo_queue.pop();

      // Re-schedule new process
      if (scheduled_proc.first != next_proc.first) {
        scheduled_proc = next_proc;
        cout << time << ": schedule P" << scheduled_proc.first << endl;
      } 
    }
    current_quantum = 0;
  }

  if (!was_empty) {
    while (is_next_line()) {
      auto in = input_lines.front();
      input_lines.pop_front();

      int proc_id = stoi(in[0]);
      int burst_time = stoi(in[2]);
      fifo_queue.push({proc_id, burst_time});
    }
  }

  scheduled_proc.second--;
  if (scheduled_proc.second < 0)
    current_quantum = quantum;
  else
    current_quantum++;
  time++;

  return true;
}
