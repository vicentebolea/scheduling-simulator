#include "launcher.hh"

using namespace scheduler_simulator;

Launcher::Launcher(Reader* r, Scheduler* s) : reader(r), scheduler(s) { }

void Launcher::run() {
  while(reader.is_next())
    scheduler.scheduler(reader.next());
}
