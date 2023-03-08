#include "graphviewfabric.h"
#include "threedgraphview.h"
#include "twodgraphview.h"

namespace utils
{
  const GraphViewFabric *GraphViewFabric::Instance()
  {
    static GraphViewFabric instance;
    return &instance;
  }

  std::shared_ptr<BaseGraphView> GraphViewFabric::GetGraphView(size_t ParamsCount) const
  {
    if (ParamsCount > 2)
      return std::shared_ptr<BaseGraphView>(new ThreeDGraphView());

    return std::shared_ptr<BaseGraphView>(new TwoDGraphView());
  }
}
