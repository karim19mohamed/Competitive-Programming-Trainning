#include <iostream>
#include <stdio.h>

using namespace std;
int n,m,p[50009],ran[50009],a,b,num,ans;

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
}

int main()
{
    while(1){
        scanf("%d%d",&n,&m);
        if (n==0 && m==0) break;
        UnionFind(n);
        ans=n;
        for (int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            if (!isSameSet(a-1,b-1)){
                unionSet(a-1,b-1);
                ans--;
            }
        }
        num++;
        printf("Case %d: %d\n",num,ans);
    }
    return 0;
}


