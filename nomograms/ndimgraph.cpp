#include "ndimgraph.h"
#include <algorithm>
#include <set>
#include <vector>

namespace graphs
{
    NDimGraph::NDimGraph(const ParametersStorage& storage)
    {
      axisType_Unit.push_back({{ AxisType::Axis_X, Unit("") }, storage.x});
      axisType_Unit.push_back({{ AxisType::Axis_Y, Unit("") }, storage.y});
      for (size_t i = 0; i < storage.params.size(); i++)
      {
          std::vector<double> params = storage.params[i];
          auto pair = std::make_pair<std::pair<AxisType, Unit>, std::vector<double>>({AxisType::Axis_P, Unit("")}, std::move(params));
          axisType_Unit.push_back(pair);
      }
    }

    NDimGraph::~NDimGraph() = default;

    int NDimGraph::GetDimention() const
    {
        return static_cast<int>(axisType_Unit.size());
    }

    const std::vector<std::pair<utils::AxisType, utils::Unit> > NDimGraph::GetAxises() const
    {
        std::vector<std::pair<utils::AxisType, utils::Unit> > axises;
        std::for_each(axisType_Unit.begin(), axisType_Unit.end(), [&axises](const utils::TAxisUnitPair& pair)
        {
            axises.push_back(pair.first);
        });

        return axises;
    }

    void NDimGraph::ForEach(const std::function<void (utils::TAxisUnitPair)>& callBack) const
    {
        for (const auto& pair : axisType_Unit)
            callBack(pair);
    }

    bool NDimGraph::Calculate(const IOData& input, IOData& output)
    {
      Q_UNUSED(input);
      Q_UNUSED(output);
      return true;
    }

    std::vector<utils::TAxisUnitPair>::const_iterator NDimGraph::find(utils::AxisType axisType, const utils::Unit& unit) const
    {
        return std::find_if(axisType_Unit.begin(), axisType_Unit.end(), [&axisType, &unit](const utils::TAxisUnitPair& pair) -> bool
        {
            return pair.first.first == axisType && pair.first.second == unit;
        });
    }

    const std::pair<AxisType, Unit> NDimGraph::getOutputAxisTypeUnit(const IOData& Data) const
    {
      std::vector<Unit> s1;
      Data.ForEach([&s1](const TUnitValue& pair)
      {
          s1.push_back(pair.first);
      });

      std::vector<Unit> s2;
      ForEach([&s2](const TAxisUnitPair& pair)
      {
          s2.push_back(pair.first.second);
      });

      std::vector<Unit> diff;
      std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),diff.begin());
      if (diff.empty())
        return std::make_pair(AxisType::Count_Axises, Unit(""));

      AxisType axis;
      for (const auto& pair : axisType_Unit)
      {
          if (pair.first.second == *diff.begin())
          {
              axis = pair.first.first;
              break;
          }
      }

      return std::make_pair(axis, *diff.begin());
    }
}

