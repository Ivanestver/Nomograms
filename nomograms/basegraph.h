#ifndef BASEGRAPH_H
#define BASEGRAPH_H

#include <utils/iodata.h>

class BaseGraph
{
public:
    BaseGraph();
    virtual ~BaseGraph();

    virtual bool Calculate(const utils::IOData& input, utils::IOData& output) = 0;
};

#endif // BASEGRAPH_H
