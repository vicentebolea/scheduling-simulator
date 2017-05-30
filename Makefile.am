AM_CXXFLAGS = -std=c++14 ${CXXFLAGS}

bin_PROGRAM = scheduler_sim

scheduler_sim_SOURCES = main.cc              \
                        launcher.cc          \
                        cli_options.cc       \
                        reader_factory.cc    \
                        text_reader.cc       \
                        schedulers/rr.cc     \
                        schedulers/sjf.cc    \
                        schedulers/rm.cc     \
                        schedulers/lt.cc     \
                        schedulers/edf.cc    \
                        schedulers/scheduler_factory.cc
