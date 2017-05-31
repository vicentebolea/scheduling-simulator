#include "launcher.hh"
#include "reader.hh"
#include "scheduler.hh"
#include <vector>
#include <string>

using namespace scheduler_simulator;
using std::vector;
using std::string;

Launcher::Launcher(Reader* r, Scheduler* s) : reader(r), scheduler(s) { }

void Launcher::run() {
  int time = 0;
  vector<string> input;
  while (true) {
    if (reader->is_next()) 
      input = reader->next(); 

    int next_time = atoi(input[1].c_str());
    int diff_time = next_time - time;

    do {
      scheduler->schedule(input);
    } while (--diff_time > 0);

    if (!reader->is_next() && !scheduler->is_next())
      break;

    time++;
  }
}
