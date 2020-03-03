#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

using namespace std;
long long n,a,b,ans;
string s;

int main()
{
    cin >> n >> s;
    for (long long i=0;i<n;i++){
        if (s[i]=='0') a++;
        else b++;
    }
    ans=abs(a-b);
    cout << ans << endl;
    return 0;
}