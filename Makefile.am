AM_CXXFLAGS = -std=c++14 -Wall -Werror -g $(CXXFLAGS)
AM_CPPFLAGS = -std=c++14 -include ./config.h $(CPPFLAGS)

bin_PROGRAMS = scheduler_sim

scheduler_sim_SOURCES = main.cc              \
                        launcher.cc          \
                        cli_options.cc       \
                        reader_factory.cc    \
                        text_reader.cc       \
                        stdin_reader.cc      \
                        schedulers/rr.cc     \
                        schedulers/sjf.cc    \
                        schedulers/rm.cc     \
                        schedulers/lt.cc     \
                        schedulers/edf.cc    \
                        schedulers/scheduler_factory.cc \
                        schedulers/interactive_scheduler.cc

check_SCRIPTS = tests/integration-test-runner.py scheduler_sim

TESTS = tests/integration-test-runner.py

AM_TESTS_ENVIRONMENT = \
                      export TEST_BINARY=./scheduler_sim; \
                      export TEST_CONFIG=$(top_srcdir)/tests/test-config.yaml;


tests/integration-test-runner.py:
	chmod +x ./tests/integration-test-runner.py


EXTRA_DIST = tests/integration-test-runner.py   \
             tests/test-config.yaml             \
						 schedulers/rr.hh     \
						 schedulers/sjf.hh    \
						 schedulers/rm.hh     \
						 schedulers/lt.hh     \
						 schedulers/edf.hh    \
						 schedulers/scheduler_factory.hh \
						 schedulers/interactive_scheduler.hh \
						 launcher.hh          \
						 cli_options.hh       \
						 options.hh           \
						 reader.hh            \
						 text_reader.hh       \
						 stdin_reader.hh      \
						 reader_factory.hh    \
						 scheduler.hh

