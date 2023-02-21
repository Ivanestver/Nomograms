#ifndef NDIMGRAPH_H
#define NDIMGRAPH_H

#include <vector>
#include <functional>
#include <utils/parametersstorage.h>
#include "utils/enums.h"
#include "utils/unit.h"
#include "utils/TypeDefs.h"
#include "utils/iodata.h"
#include "basegraph.h"

namespace graphs
{
  using namespace utils;
  class NDimGraph : public BaseGraph
  {
  public:
    explicit NDimGraph(const ParametersStorage& storage);
    ~NDimGraph();

    int GetDimention() const;
    const std::vector<std::pair<AxisType, Unit> > GetAxises() const;
    void ForEach(const std::function<void(TAxisUnitPair)>& callBack) const;

    // BaseGraph interface
    bool Calculate(const IOData &input, IOData &output) override;

  private:
    std::vector<TAxisUnitPair>::const_iterator find(AxisType axisType, const Unit& unit) const;
    const std::pair<AxisType, Unit> getOutputAxisTypeUnit(const IOData& Data) const;

  private:
    std::vector<utils::TAxisUnitPair> axisType_Unit;

  };
}

#endif // NDIMGRAPH_H
