#pragma once
#include "reader.hh"

namespace scheduler_simulator {

class StdinReader: public Reader {
  public:
    StdinReader ();
    virtual ~StdinReader () = default;

    //! Check whether there is more data to be 
    //! read from stdin
    virtual bool is_next() override;

    //! Read the next line from stdin
    virtual std::vector<std::string> next() override;
};

}
