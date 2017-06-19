#include "rm.hh"
#include <iostream>
#include <algorithm>
#include <memory>
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
    double cpu_utilization = (double) proc->cpu_time / (double) proc->period;
    total_cpu_utilization += cpu_utilization;
  }

  return total_cpu_utilization < 1.0L;
}

void SchedulerRM::initialize() {
    while (!input_lines.empty()) {
      auto line = input_lines.front();
      auto proc = make_shared<Proc>();
      proc->id         = stoi(line[0]);
      proc->period     = stoi(line[1]);
      proc->cpu_time   = stoi(line[2]);
      proc_list.emplace_back(proc);
      input_lines.pop();
    }

    std::copy(proc_list.begin(), proc_list.end(), back_inserter(ready_list));
}

void SchedulerRM::schedule_proc() {
  if (ready_list.empty())
    return;

  auto scheduled_proc_it = min_element(ready_list.begin(), ready_list.end(), [](auto& a, auto&b ) {
      return a->period < b->period;
      });

  scheduled_proc = *scheduled_proc_it;
  ready_list.erase(scheduled_proc_it);

  scheduled_proc->last_scheduled_time = time;
  cout << time << ": schedule P" << scheduled_proc->id << endl;
}

bool SchedulerRM::schedule() {

  // At the first call
  if (time == 0) {
    initialize();

    if (!can_it_be_scheduled()) {
      cout << "Violate deadline of P4" << endl;
      deadly_end = true;
      return false;
    }

    schedule_proc();

  // General case 
  } else {
    // Reenter processes in ready list
    std::copy_if(proc_list.begin(), proc_list.end(), back_inserter(ready_list) , [this] (auto& p) {
        return time % p->period == 0 and time != 0;
      });


    if (scheduled_proc) {
    //cout << "Looping time "<< time << endl;
      scheduled_proc->consumed_cpu++;

      // Is it proc finished, terminate
      if (scheduled_proc->consumed_cpu == scheduled_proc->cpu_time) {
        cout << time << ": terminate P" << scheduled_proc->id<< endl;
        scheduled_proc->consumed_cpu = 0;
        schedule_proc();

      } else if (!ready_list.empty()) {
        auto scheduled_proc_it = min_element(ready_list.begin(), ready_list.end(), [](auto& a, auto&b ) {
            return a->period < b->period;
            });

        if ((*scheduled_proc_it)->id != scheduled_proc->id 
            and (*scheduled_proc_it)->period < scheduled_proc->period) {
          ready_list.push_back(scheduled_proc);
          schedule_proc();
        }

      }
    }
  }

  time++;
  return true;
}
