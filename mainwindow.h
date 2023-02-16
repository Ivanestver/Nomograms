#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void onGraphicsButtonClicked();
    void onCloseGraphsEditor(int finished);

private:
    Ui::MainWindow *ui;
    QDialog* dialog = nullptr;
};
#endif // MAINWINDOW_H
