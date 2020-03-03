#include <iostream>
#include <stdio.h>

using namespace std;
int n;
long long b,x,y,arr[19];

long long num(int n,long long a){
    long long ans=0;
    for (int i=0;i<n;i++){
        ans+=arr[i]*a;
        a*=b;
    }
    return ans;
}

int main()
{
    scanf("%d%lld",&n,&b);
    for (int i=n-1;i>=0;i--) scanf("%lld",&arr[i]);
    x=num(n,1);
    scanf("%d%lld",&n,&b);
    for (int i=n-1;i>=0;i--) scanf("%lld",&arr[i]);
    y=num(n,1);
    if (x==y) printf("=\n");
    else if (x>y) printf(">\n");
    else printf("<\n");
    return 0;
}