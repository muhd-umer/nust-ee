#include <iostream>
using namespace std;
 template<typename B>
class function
{
    public:

    B a ;
    
    template<typename T>
    T operator << (T x)
    {
        T k;
        k.a = a * x.a;
        return k;
    }
};

template<typename T>
void display (T o)
    {
        cout << o.a  << endl;
    }

int main ()
{
    function<double> p, t;
    p.a = 33;

    t.a = 2.9;

    p << t;

    display(p << t);
}