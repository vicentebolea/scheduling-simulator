#include "scheduler_factory.hh"
#include "../options.hh"
#include "sjf.hh"

using namespace scheduler_simulator;
  
#define SCHEDULER_TYPE(X, Y)    \
  if (type == #X) {             \
    return new Scheduler##X(Y); \
  }
  
//
//
//
//
Scheduler* scheduler_simulator::scheduler_factory(Options* ops) {
  std::string type = ops->get_str("-s");
//  return new SchedulerSJF();
  SCHEDULER_TYPE(SJF, );
/*
  SCHEDULER_TYPE(SJF);
  SCHEDULER_TYPE(EDF);
  SCHEDULER_TYPE(LT);
  SCHEDULER_TYPE(RR);
  SCHEDULER_TYPE(RM);
*/
  return nullptr;
}
