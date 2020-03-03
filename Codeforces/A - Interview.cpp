#include <iostream>
#include <stdio.h>
#include <bitset>

using namespace std;
int n;
long long a[1009],b[1009],x,y,m;
bitset<100> foo;
bitset<100> bar;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%lld",&a[i]);
    for (int i=0;i<n;i++) scanf("%lld",&b[i]);
    for (int i=0;i<n;i++){
        bar=a[i];
        foo=b[i];
        for (int j=i+1;j<n;j++){
            bar|=a[j];
            foo|=b[j];
        }
        x=bar.to_ullong();
        y=foo.to_ullong();
        m=max(m,x+y);
    }
    printf("%lld\n",m);
    return 0;
}