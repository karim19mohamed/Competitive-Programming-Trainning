#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
long long n,a,b;

int main()
{
    scanf("%lld",&n);
    if (n==1)printf("9 8\n");
    else printf("%lld %lld\n",3*n,2*n);
    return 0;
}
