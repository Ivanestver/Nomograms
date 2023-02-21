#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <vector>
#include "enums.h"
#include "unit.h"

namespace utils
{
  using TAxisUnitPair = std::pair<std::pair<AxisType, Unit>, std::vector<double>>;
  using TUnitValues = std::pair<Unit, std::vector<double>>;
  using TUnitValue = std::pair<Unit, double>;
}
#endif // TYPEDEFS_H
