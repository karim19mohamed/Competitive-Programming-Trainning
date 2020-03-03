#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <map>
#include <cmath>

using namespace std;
long long n,sum;
long long a[100009];

int main()
{
    scanf("%lld",&n);
    for (int i=0;i<n;++i){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    if(sum%n!=0) printf("%lld\n",n-1);
    else printf("%lld\n",n);
    return 0;
}
