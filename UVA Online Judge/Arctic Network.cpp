#include <iostream>
#include <cmath>
#include <queue>
#include <stdio.h>

using namespace std;
int t,n,no_set;
double a[509],b[509],ans;
priority_queue < pair<double, pair<int,int> > > q;
int p[509],ran[509];

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
    while (!q.empty() && n!=no_set){
        double c=-q.top().first;
        int a=q.top().second.first;
        int b=q.top().second.second;
        q.pop();
        if (!isSameSet(a,b)){
            unionSet(a,b);
            ans=max(c,ans);
            n--;
        }
    }
}

int main()
{
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%d%d",&no_set,&n);
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
        ans=0;
        if (!q.empty()) q.pop();
    }
    return 0;
}
