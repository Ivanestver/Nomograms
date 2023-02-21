#include "unit.h"
#include <unordered_map>
#include <string>

namespace utils
{
    Unit::Unit(const QString& Name)
        : unitName(Name)
    {
        hash = std::hash<std::string>()(Name.toStdString());
    }

    Unit::~Unit() = default;

    bool Unit::operator==(const Unit& Other) const
    {
      return this->hash == Other.hash;
    }

    bool Unit::operator<(const Unit &Other) const
    {
      return this->hash < Other.hash;
    }

    const QString Unit::GetUnitName() const
    {
        return unitName;
    }
}
