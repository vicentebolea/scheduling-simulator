#include "launcher.hh"
#include "reader.hh"
#include "scheduler.hh"
#include <vector>
#include <string>
#include <iostream>

using namespace scheduler_simulator;
using namespace std;
using std::vector;
using std::string;

Launcher::Launcher(Reader* r, Scheduler* s) : reader(r), scheduler(s) { }

void Launcher::run() {
  int time = 0;
  vector<string> input;
  while (true) {
    int next_time = time;
    if (reader->is_next()) {
      input = reader->next(); 
      next_time = atoi(input[1].c_str());
    }

    int diff_time = next_time - time;
    time = next_time;

    while (--diff_time >= 0) {
      scheduler->schedule();
    }
    scheduler->schedule(input);

    if (!reader->is_next()) {
      while (scheduler->is_next()){
        scheduler->schedule();
      }
      break;
    }

    //time++;
  }
}
