#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
long long l,r,ans;
string s;

int main()
{
    scanf("%lld %lld",&l,&r);
    for(long long i=l;i<=1000000;++i){
        if (i>r) break;
        if (i*i<=r && i*i*i<=r){
            ++ans;
            //cout << i << endl;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
