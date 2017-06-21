#pragma once
#include <vector>
#include <string>

namespace scheduler_simulator {

class Reader {
  public:
    Reader () = default;
    virtual ~Reader () = default;

    //! Wether more lines can be read from this source
    virtual bool is_next() = 0;

    //! Get the next line
    virtual std::vector<std::string> next() = 0;
};

}
