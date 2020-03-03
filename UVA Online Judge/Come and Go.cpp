#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
const int N = 2009, M = ((N*(N-1))>>1)+9;
int n,a,b,c;
long long m;

long long head[N], nxt[M], to[M], ne;
void init(int n) {
	memset(head, -1, n * sizeof(head[0]));
	ne = 0;
}
void addEdge(long long f, long long t) {
	nxt[ne] = head[f];
	to[ne] = t;
	head[f] = ne++;
}
long long low[N],dfsTime[N],nxtTime,stk[N],stkSz,ncomp,compID[N];
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
        ncomp++;
    }
}
void scc(){
    memset(dfsTime,-1,n*sizeof(dfsTime[0]));
    memset(compID,-1,n*sizeof(compID[0]));
    nxtTime=ncomp=0;
    for (long long i=0;i<n;i++){
        if (!~dfsTime[i]) sccdfs(i);
    }
}

int main()
{
    while (scanf("%d%lld",&n,&m),n){
        init(n);
        for (long long i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            if (c==1){
                addEdge(a-1,b-1);
            }else{
                addEdge(a-1,b-1);
                addEdge(b-1,a-1);
            }
        }
        scc();
        if (ncomp==1) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
