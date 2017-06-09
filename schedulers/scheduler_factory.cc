#include "scheduler_factory.hh"
#include "../options.hh"
#include "sjf.hh"
#include "rr.hh"
#include "rm.hh"

using namespace scheduler_simulator;
  
#define SCHEDULER_TYPE(X, ...)    \
  if (type == #X) {             \
    return new Scheduler##X(__VA_ARGS__); \
  }
  
//
//
//
//
Scheduler* scheduler_simulator::scheduler_factory(Options* ops) {
  std::string type = ops->get_str("-s");
  SCHEDULER_TYPE(SJF);
  SCHEDULER_TYPE(RR, ops);
  SCHEDULER_TYPE(RM, ops);
  /*
  SCHEDULER_TYPE(EDF);
  SCHEDULER_TYPE(LT);
*/
  return nullptr;
}
