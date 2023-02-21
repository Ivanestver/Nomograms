#ifndef GRAPHICSEDITORWINDOW_H
#define GRAPHICSEDITORWINDOW_H

#include "surface.h"

#include <QDialog>
#include <Q3DSurface>

using namespace QtDataVisualization;

namespace Ui {
class GraphicsEditorWindow;
}

class GraphicsEditorWindow : public QDialog
{
    Q_OBJECT;

public:
    explicit GraphicsEditorWindow(QWidget *parent = nullptr);
    ~GraphicsEditorWindow() override;

private:
  void createMenu();

private Q_SLOTS:
  void onAddNewGraphClicked();

private:
    Ui::GraphicsEditorWindow *ui;
    Surface* surface;
};

#endif // GRAPHICSEDITORWINDOW_H
