#include "graphicseditorwindow.h"
#include "mainwindow.h"
#include "surface.h"
#include "ui_mainwindow.h"
#include <Q3DSurface>
#include <QStringListModel>
#include <QWidget>
#include <memory>

using namespace QtDataVisualization;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->graphsEditorBtn, &QPushButton::clicked, this, &MainWindow::onGraphicsButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onGraphicsButtonClicked()
{
    auto dialog = std::make_unique<GraphicsEditorWindow>(this);
    dialog->exec();
}
