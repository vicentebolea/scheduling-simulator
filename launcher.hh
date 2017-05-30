#pragma once

namespace scheduler_simulator {

class Reader;
class Scheduler;

class Launcher {
  public:
    Launcher (Reader*, Scheduler*);
    ~Launcher () = default;

    void run();

  private:
    Reader* reader;
    Scheduler* scheduler;
};

}
