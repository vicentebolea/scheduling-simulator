#pragma once
#include <vector>
#include <string>

namespace scheduler_simulator {

class Reader {
  public:
    Reader () = default;
    virtual ~Reader () = 0;

    virtual bool is_next() = 0;
    virtual std::vector<std::string> next() = 0;
};

}
