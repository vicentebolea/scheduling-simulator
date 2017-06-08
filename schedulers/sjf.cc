#include "sjf.hh"
#include <iostream>
#include <algorithm>

using namespace scheduler_simulator;
using namespace std;

bool SchedulerSJF::is_next() {
  return any_of(remaining_times.begin(), remaining_times.end(), [](auto& a) { 
        return a.second > 0; 
      });
}

bool SchedulerSJF::schedule(std::vector<std::string> in) {
  if (remaining_times.size() + in.size() == 0) return true;

  if (in.size() != 0) {
    int proc_id = atoi(in[0].c_str());
    int burst_time = atoi(in[2].c_str());
    remaining_times.insert({proc_id, burst_time});
  }

  auto shortest = min_element(remaining_times.begin(), remaining_times.end(), [](auto& a, auto& b) {
        return a.second < b.second; 
      });

  if (scheduled_proc == shortest->first) {
    shortest->second--;

    int remaining_burst_time = shortest->second;
    if (remaining_burst_time <= 0) {
      cout << time << ": terminate P" << shortest->first << endl;
      remaining_times.erase(shortest->first);
    }

  } else {

    scheduled_proc = shortest->first;
    cout << time << ": schedule P" << shortest->first << endl;
  }

  this->time++;

  return true;
}
