#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>

using namespace std;
int t,n,m,a,p[10009],ran[10009];
long long c,ans;
string dumy;
priority_queue <pair<long long,pair<int,int> > > q;

//unionFind
void UnionFind(int N){
    for (int i=0;i<N;i++){
        p[i]=i;ran[i]=0;
    }
}
int findSet (int i){
    return (p[i]==i)? i : p[i]=findSet(p[i]);
}
bool isSameSet (int i,int j){
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
    //cout << c[a] << endl;

}
void kruskal (){
    while (!q.empty()){
        int a=q.top().second.first;
        int b=q.top().second.second;
        if (!isSameSet(a,b)){
            unionSet(a,b);
            ans-=q.top().first;
        }
        q.pop();
    }
}

int main()
{
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%d",&n);
        UnionFind(n);
        for (int j=0;j<n;j++){
            cin >> dumy;
            scanf("%d",&m);
            for (int k=0;k<m;k++){
                scanf("%d%lld",&a,&c);
                q.push({-c,{j,a-1}});
            }
        }
        kruskal();
        printf("%lld\n",ans);
        ans=0;
    }
    return 0;
}
