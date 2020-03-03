#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;
long long n,m,a,b,ans;
long long sink[100009],sinkSz;
bool res[100009];
long long head[100009], nxt[200009], to[200009], ne;
void init(int n) {
	memset(head, -1, n * sizeof(head[0]));
	memset(res, 0, n * sizeof(res[0]));
	memset(sink, 0, n * sizeof(sink[0]));
	ne = 0;
	sinkSz=0;
}
void addEdge(long long f, long long t) {
	nxt[ne] = head[f];
	to[ne] = t;
	head[f] = ne++;
}
long long low[100009],dfsTime[100009],nxtTime,stk[100009],stkSz,ncomp,compID[100009];
void sccdfs(long long i){
    dfsTime[i]=low[i]=nxtTime++;
    stk[stkSz++]=i;
    if (head[i]==-1){
        sink[sinkSz++]=i;
        //cout << i << endl;
    }
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
            if (ncomp==0) ans++;
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
    while (scanf("%lld",&n),n){
        init(n);
        scanf("%lld",&m);
        for (long long i=0;i<m;i++){
            scanf("%lld%lld",&a,&b);
            addEdge(a-1,b-1);
        }
        scc();
        for (long long i=0;i<sinkSz;i++){
            res[ compID[sink[i]] ]=1;
        }
        for (long long i=0;i<n;i++){
            if (res[ compID[i] ]==1 || compID[i]==0){
                printf("%lld",i+1);
                if (i!=n-1) printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
