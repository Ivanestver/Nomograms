#ifndef GRAPHICSEDITORWINDOW_H
#define GRAPHICSEDITORWINDOW_H

#include <QDialog>

namespace Ui {
class GraphicsEditorWindow;
}

class GraphicsEditorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GraphicsEditorWindow(QWidget *parent = nullptr);
    ~GraphicsEditorWindow() override;

private:
    Ui::GraphicsEditorWindow *ui;
};

#endif // GRAPHICSEDITORWINDOW_H
