#include "dlgaddnewgraph.h"
#include "ui_dlgaddnewgraph.h"

#include <QMessageBox>
#include <QTextStream>
#include <Q3DSurface>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>

#include <utils/parametersstorage.h>

QT_CHARTS_USE_NAMESPACE

DlgAddNewGraph::DlgAddNewGraph(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::DlgAddNewGraph)
{
  ui->setupUi(this);
  connect(ui->chooseFileBtn, &QPushButton::clicked, this, &DlgAddNewGraph::onChooseFileBtnClicked);

  auto* scene = new QGraphicsScene();
  ui->graphicsPreview->setScene(scene);
}

DlgAddNewGraph::~DlgAddNewGraph()
{
  delete ui;
  if (dlg)
    delete dlg;
}

void DlgAddNewGraph::onChooseFileBtnClicked()
{
  if (dlg)
    delete dlg;

  dlg = new QFileDialog(this);
  connect(dlg, &QFileDialog::fileSelected, this, &DlgAddNewGraph::onFilePathReceived);
  dlg->show();
}

void DlgAddNewGraph::showCoordinateAxises()
{
  auto* scene = ui->graphicsPreview->scene();

  auto startX = ui->graphicsPreview->mapToScene(-ui->graphicsPreview->width() / 2, 0);
  auto endX = ui->graphicsPreview->mapToScene(ui->graphicsPreview->width() / 2, 0);
  scene->addLine(startX.x(), startX.y(), endX.x(), endX.y(), QPen(Qt::red));

  auto startY = ui->graphicsPreview->mapToScene(0, -ui->graphicsPreview->height() / 2);
  auto endY = ui->graphicsPreview->mapToScene(0, ui->graphicsPreview->height() / 2);
  scene->addLine(startY.x(), startY.y(), endY.x(), endY.y(), QPen(Qt::blue));
}

void DlgAddNewGraph::onFilePathReceived()
{
  disconnect(dlg, &QFileDialog::fileSelected, this, &DlgAddNewGraph::onFilePathReceived);
  dlg->close();
  try {
    QString filePath = dlg->selectedFiles().at(0);
    ui->pathToFileLabel->setText(filePath);

    QFile file(filePath);
    if (!file.exists())
      return;

    file.open(QIODevice::OpenModeFlag::ReadOnly);
    QTextStream in(&file);
    in.reset();
    utils::ParametersStorage storage;
    int rowsCount = 0;
    while (!in.atEnd())
    {
        QString s = in.readLine();
        auto params = s.split(' ');
        if (params.size() < 2)
          throw std::invalid_argument("В какой-то момент количество параметров меньше 2");

        storage.x.push_back(params[0].toDouble());
        storage.y.push_back(params[1].toDouble());
        for (int i = 2; i < params.size(); i++)
          storage.params[rowsCount].push_back(params[i].toDouble());
        rowsCount++;
    }

    auto* charts = new QChart();
    charts->legend()->hide();
    auto* axisX = new QValueAxis(charts);
    axisX->setTickCount(10);
    auto* axisY = new QValueAxis(charts);
    axisY->setTickCount(10);
    //charts->addAxis(axisX, Qt::AlignHCenter);
    //charts->addAxis(axisY, Qt::AlignVCenter);
    auto* series = new QSplineSeries();
    for (size_t i = 0; i < storage.x.size(); i++)
      *series << QPointF(storage.x[i], storage.y[i]);

    series->attachAxis(axisX);
    series->attachAxis(axisY);

    charts->addSeries(series);

    QChartView* chartView = new QChartView(charts);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout->addWidget(chartView);

  }
  catch (std::invalid_argument& e)
  {
    QMessageBox box(this);
    box.setText(e.what());
    box.exec();
  }
  catch(std::exception& e)
  {
    QMessageBox box(this);
    box.setText(e.what());
    box.exec();
  }
}
