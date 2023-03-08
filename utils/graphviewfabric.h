#ifndef GRAPHVIEWFABRIC_H
#define GRAPHVIEWFABRIC_H

#include "GraphView.h"
#include <memory>

namespace utils
{
  class GraphViewFabric
  {
  public:
    const static GraphViewFabric* Instance();

    ~GraphViewFabric() = default;

    std::shared_ptr<BaseGraphView> GetGraphView(size_t ParamsCount) const;

  private:
    GraphViewFabric() = default;
  };
}

#endif // GRAPHVIEWFABRIC_H
