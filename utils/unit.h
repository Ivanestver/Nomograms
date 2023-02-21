#ifndef UNIT_H
#define UNIT_H

#include <QString>

namespace utils
{
    class Unit
    {
    public:
        Unit(const QString& Name);
        virtual ~Unit();

        bool operator==(const Unit& Other) const;
        bool operator<(const Unit& Other) const;

        const QString GetUnitName() const;

    private:
        QString unitName;
        size_t hash;
    };
}

#endif // UNIT_H
