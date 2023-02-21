#ifndef ENUMS_H
#define ENUMS_H

namespace utils
{
    #define DECL_TO_INT(__enumname__) \
        int toInt(__enumname__ value) { return static_cast<int>(value); }

    enum class AxisType
    {
        Axis_X,
        Axis_Y,
        Axis_P,

        Count_Axises
    };
}

#endif // ENUMS_H
