#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <map>
#include <cmath>

using namespace std;
long long n,l[100009],r[100009],b;
long long a=10000000009;
map < pair< long long,long long > ,long long> m;

int main()
{
    scanf("%lld",&n);
    for (long long i=0;i<n;++i){
        scanf("%lld %lld",&l[i],&r[i]);
        a=min(a,l[i]);
        b=max(b,r[i]);
        m[make_pair(l[i],r[i])]=i+1;
    }
    (m[make_pair(a,b)]!=0) ? printf("%lld\n",m[make_pair(a,b)]) : printf("-1\n");
    return 0;
}
