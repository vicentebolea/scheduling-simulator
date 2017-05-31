#pragma once
#include <options.hh>

namespace scheduler_simulator {

//class Options;
class Reader;

Reader* reader_factory(Options*);

}
