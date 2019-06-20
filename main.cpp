#include <iostream>

using namespace std;

uint8_t pool[128] = {0};

struct I {
    I() {_i = 7;};
    int _i;
};

struct D {
    D(double d):
        _d(d) {}
    double _d;
};

struct G {
    G(double d, char ch):
        _dC(d), _ch(ch) {}
    D _dC;
    char _ch;
};

template<
    typename T,
    typename ... types
> T* factory(void *mem, types ... params)
{
    return new (mem) T(params...);
}

int main()
{
    I *i = factory<I>(pool);
    cout<< i->_i <<endl;
    D *d = factory<D>(pool, 5.6);
    cout<< d->_d << endl;
    //G *g = factory<G, double, char>(pool, 4.5, 'R');
    G *g = factory<G>(pool, 4.5, 'R');  // double and char can be deducted from params
    cout << g->_dC._d << "\t" << g->_ch << endl;
    return 0;
}
