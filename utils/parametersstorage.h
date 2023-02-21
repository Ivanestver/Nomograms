#ifndef PARAMETERSSTORAGE_H
#define PARAMETERSSTORAGE_H

#include <vector>

namespace utils
{
  struct ParametersStorage
  {
    std::vector<double> x;
    std::vector<double> y;
    std::vector<std::vector<double> > params;
  };
}
#endif // PARAMETERSSTORAGE_H
