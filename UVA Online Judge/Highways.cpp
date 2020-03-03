#include <iostream>
#include <cstring>
#include <stdio.h>
#include <cmath>
#include <queue>

using namespace std;
int n,m,t,a,b,p[759],ran[759];
double arr[759][2];
bool ans;
priority_queue <pair<double,pair<int,int> > > q;

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
        double c=-q.top().first;
        int a=q.top().second.first;
        int b=q.top().second.second;
        q.pop();
        if (!isSameSet(a,b)){
            unionSet(a,b);
            printf("%d %d\n",a+1,b+1);
            ans=1;
        }
    }
}

int main()
{
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        ans=0;
        scanf("%d",&n);
        unionFind(n);
        for (int j=0;j<n;j++){
            scanf("%lf%lf",&arr[j][0],&arr[j][1]);
        }
        for (int j=0;j<n;j++){
            for (int k=j+1;k<n;k++){
                double c=sqrt((arr[j][0]-arr[k][0])*(arr[j][0]-arr[k][0])+(arr[j][1]-arr[k][1])*(arr[j][1]-arr[k][1]));
                q.push({-c,{j,k}});
            }
        }
        scanf("%d",&m);
        for (int j=0;j<m;j++){
            scanf("%d%d",&a,&b);
            if (!isSameSet(a-1,b-1)) unionSet(a-1,b-1);
        }
        kruskal();
        if (ans==0){
            printf("No new highways need\n");
        }
    }
    return 0;
}
