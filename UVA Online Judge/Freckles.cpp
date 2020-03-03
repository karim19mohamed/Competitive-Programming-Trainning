#include <iostream>
#include <cmath>
#include <queue>
#include <stdio.h>

using namespace std;
int t,n;
double a[109],b[109],ans;
priority_queue < pair<double, pair<int,int> > > q;
int p[109],ran[109];

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
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%d",&n);
        unionFind(n);
        for (int j=0;j<n;j++){
            scanf("%lf %lf",&a[j],&b[j]);
        }
        for (int j=0;j<n;j++){
            for (int k=j+1;k<n;k++){
                q.push({-sqrt((a[j]-a[k])*(a[j]-a[k])+(b[j]-b[k])*(b[j]-b[k])),{j,k}});
            }
        }
        kruskal();
        printf("%.2lf\n",ans);
        if (i!=t-1) printf("\n");
        ans=0;
    }
    return 0;
}
