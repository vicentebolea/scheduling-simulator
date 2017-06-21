#pragma once
#include "reader.hh"
#include <fstream>

namespace scheduler_simulator {

class Options;

class TextReader: public Reader {
  public:
    TextReader (Options*);
    virtual ~TextReader () = default;

    //! Whether there is more data to be read
    virtual bool is_next() override;

    //! Get the next line of the file
    virtual std::vector<std::string> next() override;

  private:
    std::ifstream ifs;
};

}
