#pragma once
#include <memory>

namespace scheduler_simulator {

// Pay for what you need
class Scheduler;
class Options;

//! Factory method inmplemented using a non-member non-static function. 
//! @relates Scheduler
std::shared_ptr<Scheduler> scheduler_factory(Options*);

}
