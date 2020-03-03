#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;
int t,n,a,b;
long long price,m,ans,c;
priority_queue < pair < long long , pair < int,int > > > q;
int p[1009],ran[1009];
int numset;
void kruskal ();

//class UnionFind{
//    public:
    void UnionFind(int N){
        for(int i=0;i<N;i++) {
            ran[i]=0;p[i]=i;
        }
    }
    int findSet (int i){
        return (p[i]==i) ? p[i] : p[i]=findSet(p[i]);
    }
    bool isSameSet (int i,int j){
        return findSet(i)==findSet(j);
    }
    void unionSet (int i,int j){
        //if (!isSameSet(i,j)){
            int a=findSet(i),b=findSet(j);
            if (ran[a]>ran[b]){
                p[b]=a;
            }else{
                p[a]=b;
                if (ran[a]==ran[b]) ran[b]++;
            }
        //}
    }
//};

int main()
{
    scanf("%d %lld %d %lld",&t,&price,&n,&m);
    for (int i=0;i<t;i++){
        while (!q.empty()) q.pop();
        for (int j=0;j<m;j++){
            scanf("%d %d %lld",&a,&b,&c);
            q.push(make_pair(-c,make_pair(a-1,b-1)));
        }
        kruskal ();
        printf("%lld\n",ans);
    }
    return 0;
}
void kruskal (){
    numset=n;
    ans=0;
    UnionFind(n);
    while(numset!=1){
        int a=q.top().second.first;
        int b=q.top().second.second;
        long long c=-1*q.top().first;
        q.pop();
        if (!isSameSet(a,b)){
            unionSet(a,b);
            numset--;
            ans+=c;
        }
    }
    ans*=price;
}



