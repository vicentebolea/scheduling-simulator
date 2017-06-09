#include "rm.hh"
#include <iostream>
#include <algorithm>
#include "../options.hh"

using namespace scheduler_simulator;
using namespace std;

SchedulerRM::SchedulerRM (Options* opt) {
  end_time = atoi(opt->get_str("-e").c_str());
}

bool SchedulerRM::is_next() {
  return !deadly_end && time <= end_time;
}

bool SchedulerRM::can_it_be_scheduled() {
  double total_cpu_utilization = .0;

  for (auto& proc : proc_list) {
    double cpu_utilization = (double) proc.cpu_time / (double) proc.period;
    total_cpu_utilization += cpu_utilization;
  }

  return total_cpu_utilization < 1.0L;
}

bool SchedulerRM::schedule() {

  // At the first call
  if (time == 0) {
    while (!input_lines.empty()) {
      auto line = input_lines.front();
      SchedulerRM::Proc proc;
      proc.id     = atoi(line[0].c_str());
      proc.period = atoi(line[1].c_str());
      proc.cpu_time   = atoi(line[2].c_str());
      proc.last_scheduled_time = -1;
      proc_list.push_back(proc);
      input_lines.pop();
    }

    if (!can_it_be_scheduled()) {
      cout << "Violate deadline of P4" << endl;
      deadly_end = true;
      return false;
    }

    scheduled_proc = &*min_element(proc_list.begin(), proc_list.end(), [](auto& a, auto&b ) {
          return a.period < b.period;
        });

    scheduled_proc->last_scheduled_time = time;
    current_proc_time = 0;
    cout << time << ": schedule P" << scheduled_proc->id << endl;

  // General case 
  } else {

    // Is it proc finished, terminate
    if (current_proc_time == scheduled_proc->cpu_time) {
      cout << time << ": terminate P" << scheduled_proc->id<< endl;
    }

    // Check emergency situation; Reschedule
    auto it = find_if(proc_list.begin(), proc_list.end(), [this] (auto& p) {
        return ((int)time - p.last_scheduled_time) >= p.period;
      });

    if (it != proc_list.end()) {
      scheduled_proc = &*it;
      scheduled_proc->last_scheduled_time = time;
      current_proc_time = 0;
      cout << time << ": schedule P" << scheduled_proc->id << endl;

    } else if (current_proc_time == scheduled_proc->cpu_time) {
      std::list<Proc> tmp_list(proc_list.size());
      int id = scheduled_proc->id;
      auto it = copy_if(proc_list.begin(), proc_list.end(), tmp_list.begin(), [id] (auto& p){
            return p.id != id;
          });
      tmp_list.resize(std::distance(tmp_list.begin(), it));
      scheduled_proc = &*min_element(tmp_list.begin(), tmp_list.end(), [](auto& a, auto&b ) {
            return a.period < b.period;
          });

      scheduled_proc->last_scheduled_time = time;
      current_proc_time = 0;
      cout << time << ": schedule P" << scheduled_proc->id << endl;
    }

  }

  current_proc_time++;
  time++;
  return true;
}
