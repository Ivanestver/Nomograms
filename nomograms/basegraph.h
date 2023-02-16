#ifndef BASEGRAPH_H
#define BASEGRAPH_H

#include <QObject>

namespace graphs
{
    class BaseGraph : public QObject
    {
        Q_OBJECT
    public:
        explicit BaseGraph(QObject *parent = nullptr);
        virtual ~BaseGraph();

        virtual double Calculate() = 0;
    private:

    };
}

#endif // BASEGRAPH_H
