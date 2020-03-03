#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;
int t;
long long n,m,a,b,ans;
long long p[10000009],ran[10000009];

void unionFind(long long N){
    for (long long i=0;i<N;i++){
        p[i]=i;ran[i]=0;
    }
}
long long findSet(long long i){
    return (p[i]==i)? i : p[i]=findSet(p[i]);
}
bool isSameSet(long long i,long long j){
    return findSet(i)==findSet(j);
}
void unionSet (long long i,long long j){
    long long a=p[i],b=p[j];
    if (ran[a]>ran[b]){
        p[b]=a;
    }else{
        p[a]=b;
        if (ran[a]==ran[b]) ran[b]++;
    }
}

int main()
{
    scanf("%d",&t);
    for (int k=0;k<t;k++){
        scanf("%lld%lld",&n,&m);
        ans=n;
        unionFind(n);
        for (long long i=0;i<m;i++){
            scanf("%lld%lld",&a,&b);
            if (!isSameSet(a-1,b-1)){
                ans--;
                unionSet(a-1,b-1);
            }
            cout << i << endl;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
