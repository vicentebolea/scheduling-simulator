#pragma once
#include <memory>

namespace scheduler_simulator {

class Options;
class Reader;

//! @relates Reader
std::shared_ptr<Reader> reader_factory(Options*);

}
