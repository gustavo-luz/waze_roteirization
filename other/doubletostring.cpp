#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main() 
{
    ostringstream ss1,ss2,ss3,ss4;
    double d1 = 23.43;
    double d2 = 6789898989.339994;
    double d3 = 1e40;
    double d4 = 1e-40;
    ss1<<d1;
    ss2<<d2;
    ss3<<d3;
    ss4<<d4;
    string d_str1 = ss1.str();
    string d_str2 = ss2.str(); 
    string d_str3 = ss3.str(); 
    string d_str4 = ss4.str(); 
    cout << "Number: " << d1 << '\n'
    << "to string: " << d_str1  << "\n\n"
    << "Number: " << d2 << '\n'
    << "to string: " << d_str2 << "\n\n"
    << "Number: " << d3 << '\n'
    << "to string: " << d_str3 << "\n\n"
    << "Number: " << d4 << '\n'
    << "to string: " << d_str4 << "\n\n";
    return 0;
}
