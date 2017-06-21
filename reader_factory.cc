#include "reader_factory.hh"
#include "text_reader.hh"
#include "stdin_reader.hh"
#include "options.hh"

using namespace scheduler_simulator;

std::shared_ptr<Reader> scheduler_simulator::reader_factory(Options* ops) {
  if(ops->get_str("-i") == "-")
    return std::make_shared<StdinReader>();

  return std::make_shared<TextReader>(ops);
}
