#include <iostream>
#include <cmath>
 
using namespace std;
 
class Complex
{
private:
    double real;
    double imag;
 
public:
    // Default constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i)
    {}
 
    // magnitude : usual function style
    double mag()
    {
        return getMag();
    }
 
    // magnitude : conversion operator
    operator double ()
    {
        return getMag();
    }
 
private:
    // class helper to get magnitude
    double getMag()
    {
        return sqrt(real * real + imag * imag);
    }
};
 
int main()
{
    // a Complex object
    Complex com(3.0, 4.0);
 
    // print magnitude
    cout << com.mag() << endl;
    // same can be done like this
    cout << com << endl;
}
