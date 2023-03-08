#ifndef TWODGRAPHVIEW_H
#define TWODGRAPHVIEW_H

#include "GraphView.h"


namespace utils
{
  class TwoDGraphView : public BaseGraphView
  {
    // BaseGraphView interface
    QWidget* CreateGraph(const ParametersStorage &Storage) override;
  };
}


#endif // TWODGRAPHVIEW_H
