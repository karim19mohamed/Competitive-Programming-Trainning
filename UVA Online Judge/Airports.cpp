#include <iostream>
#include <cmath>
#include <queue>
#include <stdio.h>

using namespace std;
int t,n,m,x,y,no_set;
long long c,a,cost;
int airport;
priority_queue < pair<long long, pair<int,int> > > q;
int p[10009],ran[10009];
bool air[10009];

void unionFind(int N){
    for (int i=0;i<N;i++){
        p[i]=i;ran[i]=0;
    }
}
int findSet(int i){
    return (p[i]==i)? i : p[i]=findSet(p[i]);
}
bool isSameSet(int i,int j){
    return findSet(i)==findSet(j);
}
void unionSet (int i,int j){
    int a=p[i],b=p[j];
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
        int a=q.top().second.first;
        int b=q.top().second.second;
        q.pop();
        if (!isSameSet(a,b)){
            if (a==n) airport++;
            unionSet(a,b);
            cost+=c;
            no_set--;
        }
    }
}

int main()
{
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%d%d%lld",&n,&m,&a);
        unionFind(n+1);
        no_set=n+1;
        for (int i=0;i<n;i++) q.push({-a,{n,i}});
        for (int i=0;i<m;i++){
            scanf("%d%d%lld",&x,&y,&c);
            q.push({-c,{x-1,y-1}});
        }
        kruskal();
        airport+=(no_set-1);
        cost+=a*(no_set-1);
        printf("Case #%d: %lld %d\n",i+1,cost,airport);
        cost=0;
        airport=0;
    }
    return 0;
}
