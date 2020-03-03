#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
long long n,arr[200009][2],x[200009],y[200009],ans;
long double da,db;
map <pair<long long,long long>,long long> q;
std::map<pair<long long,long long>,long long>::iterator it;

int main()
{
    scanf("%lld",&n);
    for (long long i=0;i<n;i++){
        scanf("%lld%lld",&arr[i][0],&arr[i][1]);
        x[i]=arr[i][0];
        y[i]=arr[i][1];
        q[{x[i],y[i]}]++;
    }
    sort(x,x+n);
    sort(y,y+n);
    long long sum=1;
    for (long long i=1;i<n;i++){
        if (x[i]==x[i-1]){
            sum++;
        }else{
            if (sum>1){
                long long a=sum*(sum-1)/2;
                ans+=a;
            }
            sum=1;
        }
    }
    ans+=sum*(sum-1)/2;
    //cout << ans << endl;
    sum=1;
    for (long long i=1;i<n;i++){
        if (y[i]==y[i-1]){
            sum++;
        }else{
            if (sum>1){
                long long a=sum*(sum-1)/2;
                ans+=a;
            }
            sum=1;
        }
    }
    ans+=sum*(sum-1)/2;
    //cout << ans << endl;
    for (it=q.begin();it!=q.end();++it){
        sum=it->second;
        long long a=sum*(sum-1)/2;
        ans-=a;
    }
    printf("%lld\n",ans);
    return 0;
}
