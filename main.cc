#include "launcher.hh"
#include "reader.hh"
#include "options.hh"
#include "cli_options.hh"
#include "schedulers/scheduler_factory.hh"
#include "reader_factory.hh"

#include <memory>

using std::make_unique;
using namespace scheduler_simulator;

int main(int argc, char** argv) {
  auto options   = make_unique<CLIOptions>(argc, argv);
  Reader* reader    = reader_factory(static_cast<Options*>(options.get()));
  Scheduler* scheduler = scheduler_factory(options.get());
  
  Launcher launcher(reader, scheduler);

  launcher.run();

  return EXIT_SUCCESS;
}
