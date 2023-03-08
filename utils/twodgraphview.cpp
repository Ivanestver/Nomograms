#include "twodgraphview.h"

#include <QChart>
#include <QChartView>
#include <QMessageBox>
#include <QSplineSeries>
#include <QValueAxis>
#include <QPointF>
#include <memory>

using namespace QtCharts;

namespace utils
{
  QWidget* TwoDGraphView::CreateGraph(const ParametersStorage &Storage)
  {
    try
    {
      QChart* chart = new QChart();

      QValueAxis* axisX = new QValueAxis(chart);
      QValueAxis* axisY = new QValueAxis(chart);

      QSplineSeries* series = new QSplineSeries();
      for (size_t i = 0; i < Storage.x.size(); i++)
      {
          *series << QPointF(Storage.x[i], Storage.y[i]);
      }

      chart->addSeries(series);
      series->attachAxis(axisX);
      series->attachAxis(axisY);

      QChartView* chartView = new QChartView(chart);
      chartView->setRenderHint(QPainter::Antialiasing);
      return chartView;
    }
    catch (const std::exception& e)
    {
      QMessageBox::warning(nullptr, "Warning", e.what());
      return nullptr;
    }
  }
}


