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

  while (reader->is_next()) {
    auto input = reader->next(); 
    scheduler->parse_line(input);
  }

  while (scheduler->is_next()) {
    scheduler->schedule();
  }
}
