#ifndef THREEDGRAPHVIEW_H
#define THREEDGRAPHVIEW_H

#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/QSurfaceDataProxy>
#include <QtDataVisualization/QHeightMapSurfaceDataProxy>
#include <QtDataVisualization/QSurface3DSeries>
#include "GraphView.h"
#include "qobjectdefs.h"

#include <QObject>
#include <memory>

using namespace QtDataVisualization;

namespace utils
{
  class ThreeDGraphView : public BaseGraphView
  {
      Q_OBJECT;
  public:
    explicit ThreeDGraphView();
    ~ThreeDGraphView() override;

    QWidget* CreateGraph(const ParametersStorage &Storage) override;

  private:
      void createGraph(const ParametersStorage& Storage);
      void showGraph();

  private:
      Q3DSurface* graph;
      QSurfaceDataProxy* proxy;
      QSurface3DSeries* series;
  };
}
#endif// 3DGRAPHVIEW_H
