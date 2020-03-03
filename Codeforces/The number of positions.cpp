#include <iostream>

using namespace std;
int n,a,b;

int main()
{
    cin >> n >> a >> b;
    if (n-a-1<=b) cout << n-a << endl;
    else cout << b+1 << endl;

    return 0;
}
