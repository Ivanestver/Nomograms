#include "iodata.h"
#include <algorithm>

namespace utils
{
  IOData::IOData() = default;
  IOData::~IOData() = default;

  void IOData::SetUnitAndValue(const Unit &unit, double value)
  {
    if (std::find(axisUnits.begin(), axisUnits.end(), std::make_pair(unit, value)) == axisUnits.end())
      axisUnits.push_back({unit, value});
  }

  double IOData::GetValueByUnit(const Unit &unit) const
  {
    auto found = std::find_if(axisUnits.begin(), axisUnits.end(), [unit](const TUnitValue& pair) { return pair.first == unit;});
    return found == axisUnits.end() ? 0.0 : found->second;
  }

  void IOData::ForEach(const std::function<void (const TUnitValue&)>& callback) const
  {
    for(const auto& pair : axisUnits)
      callback(pair);
  }

}
