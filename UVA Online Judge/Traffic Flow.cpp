#include <iostream>
#include <cstring>
#include <stdio.h>
#include <queue>
#include <cmath>

using namespace std;
int n,m,a,b,c,p[109],ran[109],ans,t,ww=1;
priority_queue <pair<int,pair<int,int> > > q;

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
    ans=10000;
    while (!q.empty()){
        int c=q.top().first;
        int a=q.top().second.first;
        int b=q.top().second.second;
        q.pop();
        if (!isSameSet(a,b)){
            unionSet(a,b);
            ans=min(c,ans);
        }
    }
}

int main()
{
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%d%d",&n,&m);
        unionFind(n);
        for (int j=0;j<m;j++){
            scanf("%d%d%d",&a,&b,&c);
            q.push({c,{a,b}});
        }
        kruskal();
        printf("Case #%d: %d\n",ww,ans);
        ww++;
    }
    return 0;
}
