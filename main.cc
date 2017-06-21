#include "launcher.hh"
#include "reader.hh"
#include "cli_options.hh"
#include "schedulers/scheduler_factory.hh"
#include "reader_factory.hh"

using std::make_unique;
using namespace scheduler_simulator;

int main(int argc, char** argv) {
  auto options   = make_unique<CLIOptions>(argc, argv);
  auto reader    = reader_factory(options.get());
  auto scheduler = scheduler_factory(options.get());
  
  Launcher launcher(reader.get(), scheduler.get());

  launcher.run();

  return EXIT_SUCCESS;
}
