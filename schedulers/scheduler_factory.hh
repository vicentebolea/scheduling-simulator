#pragma once
#include <string>

namespace scheduler_simulator {

class Scheduler;
class Options;

//
//
Scheduler* scheduler_factory(Options*);

}
