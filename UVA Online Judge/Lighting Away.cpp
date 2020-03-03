#include <iostream>
#include <cstring>
#include <stdio.h>
#include <queue>

using namespace std;
const int N=10009;
const long long M=100009;
int t,n,a,b,tc;
long long m;
queue <long long> qq;

long long head[N], nxt[M], to[M], ne;
long long revhead[N], revnxt[M], revto[M], revne;
long long vis[N],vid;
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
    scanf("%d",&t);
    while(t--){
        scanf("%d%lld",&n,&m);
        init(n);
        for (long long i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            addEdge(a-1,b-1);
            revaddEdge(b-1,a-1);
        }
        for (long long j=0;j<n;j++){
            if (vis[j]!=vid) dfs(j);
        }
        scc();
        printf("Case %d: %lld\n",++tc,ncomp);
    }
    return 0;
}
