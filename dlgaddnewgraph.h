#ifndef DLGADDNEWGRAPH_H
#define DLGADDNEWGRAPH_H

#include <QDialog>
#include <nomograms/ndimgraph.h>
#include <QFileDialog>

namespace Ui {
  class DlgAddNewGraph;
}

class DlgAddNewGraph : public QDialog
{
  Q_OBJECT

public:
  explicit DlgAddNewGraph(QWidget *parent = nullptr);
  ~DlgAddNewGraph();

private:
  void onChooseFileBtnClicked();
  void showCoordinateAxises();
  void onFilePathReceived();

private:
  Ui::DlgAddNewGraph *ui;
  QFileDialog* dlg = nullptr;
  QWidget* graphWidget = nullptr;
};

#endif // DLGADDNEWGRAPH_H
