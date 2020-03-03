#include <iostream>
#include <stdio.h>

using namespace std;
int n,p[30009],ran[30009],ans=1,a,b;
int c[30009];
long long m,t;

//unionFind
void UnionFind(int N){
    for (int i=0;i<N;i++){
        p[i]=i;ran[i]=0;c[i]=1;
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
        c[a]+=c[b];
        ans=max(ans,c[a]);
    }else{
        p[a]=b;
        c[b]+=c[a];
        ans=max(ans,c[b]);
        if (ran[a]==ran[b]) ran[b]++;
    }
    //cout << c[a] << endl;

}

int main()
{
    cin >> t;
    for(long long i=0;i<t;i++){
        scanf("%d%lld",&n,&m);
        UnionFind(n);
        for(long long j=0;j<m;j++){
            scanf("%d%d",&a,&b);
            if (!isSameSet(a-1,b-1)){
                unionSet(a-1,b-1);
            }
        }
        cout << ans << endl;
        ans=1;
    }
    return 0;
}
