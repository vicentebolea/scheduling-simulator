#include "sjf.hh"
#include <iostream>
#include <algorithm>

using namespace scheduler_simulator;
using std::any_of;
using std::min_element;
using std::cout;
using std::endl;

/// Anonymous namespace to avoid namespace collision
namespace {

//! Finds the shortest process in the map
template <typename T>
typename T::iterator min_element_all(T& container) {
    return (min_element(container.begin(), container.end(), 
          [](auto& a, auto& b) { 
            return a.second < b.second; 
          }));
}

}

//! @return false if all its processes has terminated
bool SchedulerSJF::is_next() {
  return !remaining_times.empty() || !input_lines.empty();
}


//! 1. It read all the arrival processes at the given time.
//! 2. If there are proccesses in the ready list, find the shortest one.
//! 3. If that process has finished remove it from ready list and schedule next sjf
//! @note At time 0, it sorts the input.
//! @see SJF_IWYOO_INPUT_FIX
bool SchedulerSJF::schedule() {
  if (time == 0) {
    input_lines.sort([] (auto& a, auto& b) { return stoi(a[1]) < stoi(b[1]); });
  }

  while (is_next_line()) {
    auto in = input_lines.front();
    input_lines.pop_front();

    int proc_id    = stoi(in[0]);
    int burst_time = stoi(in[2]);
    remaining_times.insert({proc_id, burst_time});
  }

  // If there is any proccess to schedule
  if (!remaining_times.empty()) {
    auto shortest = min_element_all(remaining_times); 

/// @ref 
#ifdef SJF_IWYOO_INPUT_FIX
    // Needed for the case that the current proccess and a new comming proccess
    // has the same remaining time. The project requirements does not specify about it.
     bool is_unique_proc = scheduled_proc == -1 or 
       !(shortest->second == remaining_times[scheduled_proc] and scheduled_proc != shortest->first);

    if (!is_unique_proc)
      shortest = remaining_times.find(scheduled_proc);
#endif

    // Current schedule proc is still the shortest job
    if (scheduled_proc == shortest->first) {
      if (shortest->second <= 0) {
        cout << time << ": terminate P" << shortest->first << endl;
        remaining_times.erase(shortest->first);

        // It might be empty now 
        if (!remaining_times.empty()) {
          shortest = min_element_all(remaining_times); 
          scheduled_proc = shortest->first;
          cout << time << ": schedule P" << shortest->first << endl;

        } else {
          scheduled_proc = -1;
        }
      }

    // New proc is now the shortest job
    } else {
      scheduled_proc = shortest->first;
      cout << time << ": schedule P" << shortest->first << endl;
    }
    shortest->second--;
  }
  this->time++;

  return true;
}
