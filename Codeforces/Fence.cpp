#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <map>
#include <cmath>

using namespace std;
long long n,k,j;
long long h[1000009],sum_j;

int main()
{
    scanf("%lld %lld",&n,&k);
    for (long long i=0;i<n;++i) scanf("%lld",&h[i]);
    j=1;
    for (long long i=0;i<k;++i) sum_j+=h[i];
    long long sum=sum_j;
    for (long long i=1;i<n-k+1;++i){
        if (k!=1){
            sum=sum-h[i-1]+h[i+k-1];
        }else{
            sum=h[i];
        }
        if (sum<sum_j){
            sum_j=sum;
            j=i+1;
        }
        //cout << sum_j << "  " << sum << "  " << h[i] << "  " << h[i+k-1] << endl;
    }
    printf("%lld\n",j);
    return 0;
}
