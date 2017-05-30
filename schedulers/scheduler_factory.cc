#include "scheduler_factory.hh"
#include "sjf.hh"

#define SCHEDULER_TYPE(X)     \
  if (type == #X) {         \
    return new SchedulerX(); \
  }

using namespace scheduler_simulator;

//
//
//
//
scheduler* scheduler_factory(std::string type) {
  SCHEDULER_TYPE(SJF);
/*
  SCHEDULER_TYPE(SJF);
  SCHEDULER_TYPE(EDF);
  SCHEDULER_TYPE(LT);
  SCHEDULER_TYPE(RR);
  SCHEDULER_TYPE(RM);
*/
}
