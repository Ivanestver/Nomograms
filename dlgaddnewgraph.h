#ifndef DLGADDNEWGRAPH_H
#define DLGADDNEWGRAPH_H

#include <QDialog>
#include <nomograms/ndimgraph.h>

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

private:
  Ui::DlgAddNewGraph *ui;
};

#endif // DLGADDNEWGRAPH_H
