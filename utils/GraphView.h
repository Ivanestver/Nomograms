#ifndef BASEGRAPHVIEW_H
#define BASEGRAPHVIEW_H

#include "parametersstorage.h"
#include <QObject>
#include <memory>


namespace utils
{
  class BaseGraphView : public QObject
  {
    Q_OBJECT;
  private:
    using base = BaseGraphView;
  public:
    BaseGraphView() = default;
    virtual ~BaseGraphView() = default;

    virtual QWidget* CreateGraph(const ParametersStorage& Storage) = 0;
  };
}



#endif // GRAPHVIEW_H
