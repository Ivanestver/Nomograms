#ifndef IODATA_H
#define IODATA_H

#include "TypeDefs.h"
#include <vector>
#include <functional>

namespace utils
{
    class IOData
    {
    public:
        IOData();
        ~IOData();

        void SetUnitAndValue(const Unit& unit, double value);
        double GetValueByUnit(const Unit& unit) const;
        void ForEach(const std::function<void(const TUnitValue&)>& callback) const;

    private:
        std::vector<TUnitValue> axisUnits;
    };
}

#endif // IODATA_H
