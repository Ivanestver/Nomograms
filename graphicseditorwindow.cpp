#include "graphicseditorwindow.h"
#include "surface.h"
#include "ui_graphicseditorwindow.h"

#include <Q3DSurface>

using namespace QtDataVisualization;

GraphicsEditorWindow::GraphicsEditorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphicsEditorWindow)
{
    ui->setupUi(this);
    Q3DSurface* surface = new Q3DSurface();
    auto* widget = QWidget::createWindowContainer(surface);
    ui->verticalLayout->addWidget(widget);
    ui->verticalLayout->setStretch(0, 1);
    ui->verticalLayout->setStretch(1, 2);

    Surface* s = new Surface(surface);

}

GraphicsEditorWindow::~GraphicsEditorWindow()
{
    delete ui;
}
