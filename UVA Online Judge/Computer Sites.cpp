#include <iostream>
#include <cstring>
#include <stdio.h>
#include <queue>

using namespace std;
bool ww;
long long n,a,b,k,m,p[1000009],ran[1000009];
long long c,preans,postans;
priority_queue <pair<long long,pair<long long,long long > > > q;

void unionFind(long long N){
    preans=0;postans=0;
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
void kruskal(){
    while (!q.empty()){
        long long c=-q.top().first;
        long long a=q.top().second.first;
        long long b=q.top().second.second;
        q.pop();
        if (!isSameSet(a,b)){
            unionSet(a,b);
            postans+=c;
        }
    }
}

int main()
{
    while (cin >> n){
        unionFind(n);
        if (ww) printf("\n");
        for (long long i=0;i<n-1;i++){
            scanf("%lld%lld%lld",&a,&b,&c);
            preans+=c;
        }
        scanf("%lld",&k);
        for (long long i=0;i<k;i++){
            scanf("%lld%lld%lld",&a,&b,&c);
            q.push({-c,{a-1,b-1}});
        }
        scanf("%lld",&m);
        for (long long i=0;i<m;i++){
            scanf("%lld%lld%lld",&a,&b,&c);
            q.push({-c,{a-1,b-1}});
        }
        ww=1;
        kruskal();
        printf("%lld\n%lld\n",preans,postans);
    }
    return 0;
}
