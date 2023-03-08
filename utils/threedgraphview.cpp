#include "threedgraphview.h"
#include <QtDataVisualization/QValue3DAxis>
#include <QtDataVisualization/Q3DTheme>
#include <QWidget>
#include <algorithm>

using namespace QtDataVisualization;

float minSample = -8.0f;
float maxSample = 8.0f;

namespace utils
{
  ThreeDGraphView::ThreeDGraphView() = default;

  ThreeDGraphView::~ThreeDGraphView()
  {
    //delete series;
    //delete graph;
  }

  QWidget* ThreeDGraphView::CreateGraph(const ParametersStorage& Storage)
  {
    this->graph = new Q3DSurface();
    graph->setAxisX(new QValue3DAxis());
    graph->setAxisY(new QValue3DAxis());
    graph->setAxisZ(new QValue3DAxis());

    proxy = new QSurfaceDataProxy();
    series = new QSurface3DSeries(proxy);
    createGraph(Storage);
    showGraph();

    QWidget* widget = QWidget::createWindowContainer(graph);

    return widget;
  }

  void ThreeDGraphView::createGraph(const ParametersStorage& Storage)
  {
      /*float stepX = (maxSample - minSample) / float(sampleCountX - 1);
      float stepZ = (maxSample - minSample) / float(sampleCountZ - 1);

      auto* dataArray = new QSurfaceDataArray();
      for (int i = 0; i < sampleCountX; i++)
      {
          auto* row = new QSurfaceDataRow(sampleCountX);
          float x = qMin(maxSample, i*stepX + minSample);
          int idx = 0;
          for (int j = 0; j < sampleCountZ; j++)
          {
              float z = qMin(maxSample, j*stepZ + minSample);
              float y = ((x*x)/(a*a) + (z*z)/(b*b))/2;
              (*row)[idx++].setPosition(QVector3D(x, y, z));
          }
          *dataArray << row;
      }
      proxy->resetArray(dataArray);*/

    auto minmax = std::minmax_element(Storage.x.begin(), Storage.x.end());
    minSample = *minmax.first;
    maxSample = *minmax.second;

    auto* dataArray = new QSurfaceDataArray();
    QVector<QSurfaceDataItem> v;
    int previousValue = std::numeric_limits<int>::min();
    QSurfaceDataRow* row = nullptr;
    for (size_t i = 0; i < Storage.x.size(); i++)
    {
        if (previousValue != Storage.x[i])
        {
            if (row)
              *dataArray << row;
            previousValue = Storage.x[i];
            row = new QSurfaceDataRow();
        }

        QSurfaceDataItem dataItem(QVector3D(Storage.x[i], Storage.y[i], Storage.params[i][0]));
        row->append(dataItem);
    }
    *dataArray << row;
    proxy->resetArray(dataArray);
  }

  void ThreeDGraphView::showGraph()
  {
      series->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
      series->setFlatShadingEnabled(true);

      graph->axisX()->setLabelFormat("%.2f");
      graph->axisZ()->setLabelFormat("%.2f");
      graph->axisX()->setRange(minSample, maxSample);
      graph->axisY()->setRange(minSample, maxSample);
      graph->axisZ()->setRange(minSample, maxSample);
      graph->axisX()->setLabelAutoRotation(30);
      graph->axisY()->setLabelAutoRotation(90);
      graph->axisZ()->setLabelAutoRotation(30);

      graph->addSeries(series);
  }

}
