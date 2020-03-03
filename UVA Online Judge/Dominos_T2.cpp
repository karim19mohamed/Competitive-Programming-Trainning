#include <iostream>
#include <cstring>
#include <stdio.h>
#include <queue>

using namespace std;
long long t,n,m,a,b;
queue <long long> qq;

long long head[100009], nxt[100009], to[100009], ne;
long long revhead[100009], revnxt[100009], revto[100009], revne;
long long vis[100009],vid;
void init(long long n) {
	memset(head, -1, n * sizeof(head[0]));
	memset(revhead, -1, n * sizeof(revhead[0]));
	revne = 0;
	ne = 0;
	vid++;
}
void addEdge(long long f, long long t) {
	nxt[ne] = head[f];
	to[ne] = t;
	head[f] = ne++;
}
void revaddEdge(long long f, long long t) {
	revnxt[revne] = revhead[f];
	revto[revne] = t;
	revhead[f] = revne++;
}
long long low[100009],dfsTime[100009],nxtTime,stk[100009],stkSz,ncomp,compID[100009];
void sccdfs(long long i){
    dfsTime[i]=low[i]=nxtTime++;
    stk[stkSz++]=i;
    for (long long k=head[i];~k;k=nxt[k]){
        long long j=to[k];
        if (!~dfsTime[j]){
            sccdfs(j);
            low[i]=min(low[i],low[j]);
        }else if (!~compID[j]){
            low[i]=min(low[i],low[j]);
        }
    }
    if (dfsTime[i]==low[i]){
        do{
            compID[stk[--stkSz]]=ncomp;
        }while(stk[stkSz]!=i);
        //ncomp++;
    }
}
void scc(){
    memset(dfsTime,-1,n*sizeof(dfsTime[0]));
    memset(compID,-1,n*sizeof(compID[0]));
    nxtTime=ncomp=0;
    while(!qq.empty()){
        long long i=qq.front();
        qq.pop();
        //cout << i << endl;
        if (!~dfsTime[i]){
            sccdfs(i);
            ncomp++;
        }
    }
}

void dfs(long long u){
    vis[u]=vid;
    for (long long k=revhead[u];~k;k=revnxt[k]){
        long long j=revto[k];
        if (vis[j]!=vid) dfs(j);
    }
    qq.push(u);
}

int main()
{
    scanf("%lld",&t);
    for(long long i=0;i<t;i++){
        scanf("%lld%lld",&n,&m);
        init(n);
        for (long long j=0;j<m;j++){
            scanf("%lld%lld",&a,&b);
            addEdge(a-1,b-1);
            revaddEdge(b-1,a-1);
        }
        for (long long j=0;j<n;j++){
            if (vis[j]!=vid) dfs(j);
        }
        scc();
        printf("%lld\n",ncomp);
    }
    return 0;
}
