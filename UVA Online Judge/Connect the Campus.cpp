#include <iostream>
#include <cmath>
#include <queue>
#include <stdio.h>

using namespace std;
int n,m,x,y;
double a[759],b[759],ans;
priority_queue < pair<double, pair<int,int> > > q;
int p[759],ran[759];

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
            ans+=c;
        }
    }
}

int main()
{
    while (cin>>n){
        unionFind(n);
        for (int i=0;i<n;i++) scanf("%lf%lf",&a[i],&b[i]);
        for (int j=0;j<n;j++){
            for (int k=j+1;k<n;k++){
                q.push({-sqrt((a[j]-a[k])*(a[j]-a[k])+(b[j]-b[k])*(b[j]-b[k])),{j,k}});
            }
        }
        scanf("%d",&m);
        for (int i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            if (!isSameSet(x-1,y-1)) unionSet(x-1,y-1);
        }
        kruskal();
        printf("%.2lf\n",ans);
        ans=0;
    }
    return 0;
}
