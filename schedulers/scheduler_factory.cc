#include "scheduler_factory.hh"
#include "../scheduler.hh"
#include "../options.hh"
#include "sjf.hh"
#include "rr.hh"
#include "rm.hh"
#include "edf.hh"
#include "lt.hh"

using namespace scheduler_simulator;
  
#define SCHEDULER_TYPE(X, ...)    \
  if (type == #X) {             \
    return std::make_shared<Scheduler##X>(__VA_ARGS__); \
  }
  
// It uses the metaprogramming SCHEDULE_TYPE macro to inject
// the objects into the function.
// @returns the specific scheduler given the options.
std::shared_ptr<Scheduler> scheduler_simulator::scheduler_factory(Options* ops) {
  std::string type = ops->get_str("-s");
  SCHEDULER_TYPE(SJF);
  SCHEDULER_TYPE(RR, ops);
  SCHEDULER_TYPE(RM, ops);
  SCHEDULER_TYPE(EDF, ops);
  SCHEDULER_TYPE(LT, ops);
  return nullptr;
}
