#include "Vector.h"

template<typename K, typename V, template<typename T> class U>
class Map;
template<typename K, typename V, template<typename T> class U>
ostream& operator<<(ostream&, const Map<K, V, U>&);

template<typename K, typename V, template<typename T> class U>
class Map
{
private:
    U<K> key;
    U<V> value;
public:
    Map(const int&, const int&);
    ~Map();
    void Show();
    friend ostream& operator<< <K, V, U>(ostream&, const Map<K, V, U>&);
};
template<typename K, typename V, template<typename T> class U>
ostream& operator<< (ostream& o, const Map<K, V, U>& m)
{
    o << m.key << endl << m.value;
    return o;
}

template<typename K, typename V, template<typename T> class U>
Map<K, V, U>::Map(const int& m, const int& n) : key(m), value(n)
{
}
template<typename K, typename V, template<typename T> class U>
Map<K, V, U>::~Map()
{
}
template<typename K, typename V, template<typename T> class U>
void Map<K, V, U>::Show()
{
    cout << this->key << endl << this->value;
}

template class Map<int, double, Vector>;