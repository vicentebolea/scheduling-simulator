#include "reader_factory.hh"
#include "text_reader.hh"
#include "stdin_reader.hh"

using namespace scheduler_simulator;
Reader* scheduler_simulator::reader_factory(Options* ops) {
  if(ops->get_str("-i") == "-")
    return new StdinReader();

  return new TextReader(ops);
}
