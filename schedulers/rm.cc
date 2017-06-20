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

void SchedulerRM::initialize() {
    while (!input_lines.empty()) {
      auto line = input_lines.front();
      input_lines.pop_front();
      auto proc = make_shared<Proc>();
      proc->id         = stoi(line[0]);
      proc->period     = stoi(line[1]);
      proc->cpu_time   = stoi(line[2]);
      proc_list.emplace_back(proc);
    }

    std::copy(proc_list.begin(), proc_list.end(), back_inserter(ready_list));
}

void SchedulerRM::schedule_proc() {
  if (ready_list.empty())
    return;

  auto scheduled_proc_it = min_element(ready_list.begin(), ready_list.end(), [](auto& a, auto&b) {
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
    schedule_proc();

  // General case 
  } else {

    // Check for violations
    auto proc = std::find_if(ready_list.begin(), ready_list.end(), [this] (auto& proc){
        return time % proc->period == 0 and time != 0 and proc->consumed_cpu < proc->cpu_time;
        }) ;

    if (proc != ready_list.end()) {
      cout << "Violate deadline of P" << (*proc)->id << endl;
      deadly_end = true;
      return false;
    }

    // Reenter processes in ready list
    std::copy_if(proc_list.begin(), proc_list.end(), back_inserter(ready_list) , [this] (auto& p) {
        return time % p->period == 0 and time != 0;
      });


    if (scheduled_proc) {
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
