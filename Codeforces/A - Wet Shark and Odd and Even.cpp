#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;
long long n,arr[100009],a,ans;
priority_queue <long long> q;

int main()
{
    scanf("%lld",&n);
    for (long long i=0;i<n;i++){
        scanf("%lld",&arr[i]);
        if (arr[i]%2==0){
            ans+=arr[i];
        }else{
            q.push(arr[i]);
            a++;
        }
    }
    int z;
    if (a%2==0){
        z=0;
    }else{
        z=1;
    }
    while (q.size()!=z){
        long long r=q.top();
        q.pop();
        ans+=r;
    }
    printf("%lld\n",ans);
    return 0;
}