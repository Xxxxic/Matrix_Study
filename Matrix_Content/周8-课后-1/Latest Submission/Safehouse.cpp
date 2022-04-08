#include "Safehouse.h"
Safehouse& Safehouse::operator = (const Safehouse& a)
{
    if (&a == this) return *this;
    _count_own_types = a.GetCountOwnTypes();
    _owns = new Resource[MAX_RESOURCE_TYPES];
    for (int i = 0; i < _count_own_types; ++i)
        _owns[i] = Resource(a.GetOwnsName(i), a.GetOwnsCount(i));
    return *this;
}

Safehouse Safehouse::operator + (const Resource& n)
{
    Safehouse temp = Safehouse(*this);
    if (IndexOfResource(n.name) == -1)
    {
        temp._owns[_count_own_types].name = n.name;
        temp._owns[_count_own_types].count = n.count;
        temp._count_own_types++;
    }
    else
        temp._owns[IndexOfResource(n.name)].count += n.count;
    return temp;
}

Safehouse Safehouse::operator + (const Safehouse& a)
{
    Safehouse temp = Safehouse(*this);
    for (int i = 0; i < a.GetCountOwnTypes(); ++i)
        temp = temp + a._owns[i];
    return temp;
}

Safehouse& Safehouse::operator += (const Resource& n)
{
    return *this = *this + n;
}

Safehouse& Safehouse::operator += (const Safehouse& a)
{
    return *this = *this + a;
}

const Resource& Safehouse::operator [] (const int& index) const
{
    return _owns[index];
}

bool Safehouse::operator >= (const Safehouse& a)
{
    if (GetCountOwnTypes() != a.GetCountOwnTypes()) return 0;
    for (int i = 0; i < GetCountOwnTypes(); ++i)
        if (_owns[i].count < a.CountOfResource(_owns[i].name))
            return 0;
    return 1;
}

ostream& operator << (ostream& os, const Safehouse& house)
{
    for (int i = 0; i < house.GetCountOwnTypes(); ++i)
        os << house._owns[i].name << ": " << house._owns[i].count << endl;
    return os;
}