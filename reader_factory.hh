#pragma once

namespace scheduler_simulator {

class Options;
class Reader;

Reader* reader_factory(Options*);

}
