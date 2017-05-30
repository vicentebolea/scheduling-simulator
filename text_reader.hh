#pragma once
#include "reader.hh"
#include <ifstream>

namespace scheduler_simulator {

class TextReader: public Reader {
  public:
    TextReader (Options*);
    virtual ~TextReader () = 0;

    virtual bool is_next() override;
    virtual std::vector<std::string> next() override;

  private:
    std::ifstream ifs;
};

}
