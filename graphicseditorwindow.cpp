#include "dlgaddnewgraph.h"
#include "graphicseditorwindow.h"
#include "utils/threedgraphview.h"
#include "ui_graphicseditorwindow.h"

#include <QMenuBar>

GraphicsEditorWindow::GraphicsEditorWindow(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::GraphicsEditorWindow)
{
    ui->setupUi(this);
    createMenu();

    /*Q3DSurface* s = new Q3DSurface();
    ui->verticalLayout->addWidget(widget);
    ui->verticalLayout->setStretch(0, 1);
    ui->verticalLayout->setStretch(1, 2);*/
}

GraphicsEditorWindow::~GraphicsEditorWindow()
{
    delete ui;
    //delete surface;
}

void GraphicsEditorWindow::createMenu()
{
  auto* menuBar = new QMenuBar();
  auto* menu = new QMenu("Редактор");
  menuBar->addMenu(menu);
  auto* addNewGraphAction = menu->addAction("Добавить новый график");
  connect(addNewGraphAction, &QAction::triggered, this, &GraphicsEditorWindow::onAddNewGraphClicked);
  this->layout()->setMenuBar(menuBar);
}

void GraphicsEditorWindow::onAddNewGraphClicked()
{
  auto dlg = std::make_unique<DlgAddNewGraph>(this);
  dlg->exec();
}
