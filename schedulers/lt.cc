#include "lt.hh"
#include <iostream>
#include <algorithm>
#include "../options.hh"

using namespace scheduler_simulator;
using namespace std;

SchedulerLT::SchedulerLT (Options* opt) {
  quantum = stoi(opt->get_str("-q"));
  current_quantum = quantum;
}

bool SchedulerLT::is_next() {
  return !ready_list.empty() || (scheduled_proc and scheduled_proc->cpu_time >= 0) || !input_lines.empty();
}

std::shared_ptr<SchedulerLT::Proc> SchedulerLT::schedule_proc() {
  auto it = max_element(ready_list.begin(), ready_list.end(), [] (auto& a, auto& b) {
      return (a->number_tickets < b->number_tickets);
  });
  auto proc = *it;
  ready_list.erase(it);

  return proc;
}

bool SchedulerLT::schedule() {
  if (time == 0) {
    input_lines.sort([] (auto& a, auto& b) { return stoi(a[1]) < stoi(b[1]); });
  }

  while (is_next_line()) {
    auto in = input_lines.front();
    input_lines.pop_front();

    auto proc = make_shared<Proc>();
    proc->id  = stoi(in[0]);
    proc->cpu_time = stoi(in[2]);
    proc->number_tickets  = stoi(in[3]);
    if (in.size() == 5) {
      proc->resource = stoi(in[4]);
    }

    ready_list.emplace_back(proc);
  }
  bool change_process = !scheduled_proc;

  if (scheduled_proc) {
    if (scheduled_proc->cpu_time == 0 or current_quantum == quantum) {

      if (scheduled_proc->cpu_time == 0) {
        cout << time << ": terminate P" << scheduled_proc->id << endl;
        scheduled_proc.reset();
        change_process = true;

      } else if (current_quantum == quantum and scheduled_proc->cpu_time > 0) {
        ready_list.push_back(scheduled_proc);
        change_process = true;
      }
    }
  }


  if (change_process and !ready_list.empty()) {
    auto next_proc = schedule_proc();

    // Re-schedule new process
    scheduled_proc = next_proc;
    cout << time << ": schedule P" << scheduled_proc->id << endl;
    current_quantum = 0;
  }

  if (scheduled_proc) {
    scheduled_proc->cpu_time--;
    current_quantum++;
  }

  time++;

  return true;
}
