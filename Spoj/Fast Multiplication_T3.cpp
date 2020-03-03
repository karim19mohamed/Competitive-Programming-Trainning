#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>
namespace mp = boost::multiprecision;

using namespace std;
int n;
string l1,l2;
mp::cpp_int S;

int main()
{
    cin >> n ;
    for (int i=0;i<n;i++){
        cin >> l1;
        cin >> l2;
        mp::cpp_int s1(l1);
        mp::cpp_int s2(l2);
        S=s1*s2;
        std::cout << S << '\n';
    }
    return 0;
}
