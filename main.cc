#include "launcher.hh"
#include "cli_options.hh"
#include "scheduler_factory.hh"
#include "reader_factory.hh"

#include <memory>

using std::make_unique;

int main(int argc, char** argv) {
  auto options   = make_unique<CLIOptions>(argc, argv);
  auto reader    = reader_factory(options.get());
  auto scheduler = scheduler_factory(options.get());
  
  Launcher launcher(reader.get(), scheduler.get());

  launcher.run();

  return EXIT_SUCCESS;
}
