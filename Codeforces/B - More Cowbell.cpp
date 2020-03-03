#include <iostream>
#include <stdio.h>
#include <queue>
#include <queue>

using namespace std;
long long n,k,arr[100009],sum,indx=1;
priority_queue <pair<long long,long long> > in,de;
long long bb[1000009];

bool box(long long s){
    long long ss=0,ite=0;
    while (!in.empty()) in.pop();
    while (!de.empty()) de.pop();
    for (long long i=0;i<n;i++){
        in.push({arr[i],i});
        de.push({-arr[i],-i});
    }
    while(ite!=n){
        //cout << in.top().first << "  " << de.top().first << endl;
        if (in.top().first-de.top().first<=s && bb[in.top().second]!=indx && bb[-de.top().second]!=indx && -de.top().second!=in.top().second ){
            ite+=2;
            bb[in.top().second]=bb[-de.top().second]=indx;
            in.pop();
            de.pop();
        }else if (in.top().first<=s && bb[in.top().second]!=indx){
            ite++;
            bb[in.top().second]=indx;
            in.pop();
        }else if (-de.top().first<=s && bb[-de.top().second]!=indx){
            ite++;
            bb[-de.top().second]=indx;
            de.pop();
        }else{
            return 0;
        }
        //cout << ite << endl;//int z; cin >> z;
        ss++;
    }
    //cout << "  " << ss << "  " << ite << endl;
    if (ss>k) return 0;
    else return 1;
}

long long binary(){
    long long i=0,j=sum,m,ans=0;
    while (i<=j){
        m=i+(j-i)/2;
        indx++;
        //cout << m << endl;//int z; cin >> z;
        if (box(m)){
            j=m-1; // one
            ans=m;
        }else{
            i=m+1; // zero
        }
    }
    return ans;
}

int main()
{
    scanf("%lld%lld",&n,&k);
    for (long long i=0;i<n;i++){
        scanf("%lld",&arr[i]);
        sum+=arr[i];
    }
    long long ans=binary();
    printf("%lld\n",ans);
    return 0;
}