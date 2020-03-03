
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using namespace std;
int main()
{
    mp::cpp_int s1("99999999999999999999999999999999999999999999999999999999999999999");
    mp::cpp_int s2("3458979343709887329092450970423707534025");
    mp::cpp_int S=s1*s2;
    std::cout << S << '\n';
}
