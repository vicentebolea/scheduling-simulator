#pragma once
#include "reader.hh"

namespace scheduler_simulator {

class StdinReader: public Reader {
  public:
    StdinReader ();
    virtual ~StdinReader () = default;

    virtual bool is_next() override;
    virtual std::vector<std::string> next() override;
};

}
