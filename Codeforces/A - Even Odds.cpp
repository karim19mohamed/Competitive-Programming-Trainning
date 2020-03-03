#include <iostream>
#include <cmath>

using namespace std;
long long n,k,a,b;

int main()
{
    cin >> n >> k;
    a=2*k-1;
    b=2*( k-( (n+1)/2 ) );
    if (a<=n) cout << a << endl;
    else if (b>0) cout << b << endl;
    return 0;
}