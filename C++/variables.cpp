#include <iostream>
#include <climits> //int limits
#include <cfloat> //for flaot/doubles
using namespace std;

int main() {
    //INT_MIN, INT_MAX, UINT_MAX, FLT_MIN, FLT_MAX, DBL_MIN, 
    cout << "int: min = "  << INT_MIN << ", max = " << INT_MAX << " - 4 bytes (32 bits)" << endl;
    cout << "unsigned int " << UINT_MAX << endl;
    cout << "long: min = " << LONG_MIN << ", max = " << LONG_MAX << " - 4 or 8 bytes (32/64 bits)" << endl;
    cout << "long long: min = " << LLONG_MIN << ", max = " << LLONG_MAX << " - 4 or 8 bytes (32/64 bits)" << endl;
    cout << "float: min = " << FLT_MIN << ", max = " << FLT_MAX << " - 32 bytes (256 bits)" << endl;
    cout << "double: min = " << DBL_MIN << ", max = " << DBL_MAX << " - 64 bytes (512 bits)" << endl;

    int a =1/3;
    float b = 10.f/3;
    double c = 1.0/3;

    cout << a << " " << b << " " << c << endl;
    return 0;
}