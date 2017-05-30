#include "reader_factory.hh"
#include "text_reader.hh"

using namespace scheduler_simulator;

Reader* reader_factory(Options* ops) {
  return new TextReader(ops);
}
