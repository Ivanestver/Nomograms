#include "dlgaddnewgraph.h"
#include "ui_dlgaddnewgraph.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

#include <utils/parametersstorage.h>

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
}

void DlgAddNewGraph::onChooseFileBtnClicked()
{
  try {
    QString filePath = QFileDialog::getOpenFileName(this);
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

    auto* scene = ui->graphicsPreview->scene();
    for (size_t i = 1; i < storage.x.size(); i++)
    {
        scene->addLine(storage.x[i-1], storage.y[i-1], storage.x[i], storage.y[i]);
    }
  }
  catch (std::invalid_argument& e)
  {
    QMessageBox box(this);
    box.setText(e.what());
  }
}
