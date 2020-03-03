#include <iostream>
#include <cstring>
#include <stdio.h>
#include <queue>

using namespace std;
int n,m,a,b,p[1009],ran[1009];
long long c;
priority_queue <pair<long long,pair<int,int> > > q;
priority_queue <long long> ans;

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
        long long cz=-q.top().first;
        int a=q.top().second.first;
        int b=q.top().second.second;
        q.pop();
        if (!isSameSet(a,b)){
            unionSet(a,b);
        }else{
            ans.push(-cz);
        }
    }
}

int main()
{
    while (1){
        scanf("%d%d",&n,&m);
        if (n==0) break;
        unionFind(n);
        for (int i=0;i<m;i++){
            scanf("%d%d%lld",&a,&b,&c);
            q.push({-c,{a,b}});
        }
        kruskal();
        if (!ans.empty()){
            while (!ans.empty()){
                long long j=-ans.top();
                ans.pop();
                printf("%lld",j);
                if (ans.size()!=0) printf(" ");
            }
        }else{
            printf("forest");
        }
        printf("\n");
    }
    return 0;
}
