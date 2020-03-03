#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
const long long N = 10009, M = 200009;
int n,a,b,ans;
long long m;

int head[N],nxt[M],to[M],ne;
void init(int N){
    memset(head,-1,N*sizeof(head[0]));
    ne=0;ans=0;
}
void addEdge(int i,int j){
    nxt[ne]=head[i];
    to[ne]=j;
    head[i]=ne++;
}
int nxtTime,rootID,dfsTime[N],low[N],cntRootchildren;
int isArtID,isBrdgeID,nocomp,stkSz,isArt[N],isBrdge[M],compID[M],stk[M];
void biConCompdfs(int i,int pe=-1){
    dfsTime[i]=low[i]=nxtTime++;
    for (long long k=head[i];~k;k=nxt[k]){
        if ((k^1)==pe) continue;
        int j=to[k];
        if (!~dfsTime[j]){
            biConCompdfs(j,k);
            low[i]=min(low[i],low[j]);
            if (i==rootID){
                if (++cntRootchildren>1) isArt[i]=isArtID;
            }else if (dfsTime[i]<=low[j]){
                isArt[i]=isArtID;
            }
            if (dfsTime[i]<low[j]) isBrdge[k]=isBrdge[k^1]=isBrdgeID;
        }else{
            low[i]=min(low[i],dfsTime[j]);
        }
    }
}
void biConComp(){
    nxtTime=0;
    nocomp=0;
    memset(dfsTime,-1,n*sizeof(dfsTime[0]));
    isArtID++;isBrdgeID++;
    for (rootID=0;rootID<n;rootID++){
        cntRootchildren=0;
        if (!~dfsTime[rootID]){
            biConCompdfs(rootID);
        }
    }
}


int main()
{
    while (scanf("%d%lld",&n,&m) ,n){
        init(n);
        for (long long i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            addEdge(a-1,b-1);
            addEdge(b-1,a-1);
        }
        biConComp();
        for (int i=0;i<n;i++){
            if (isArt[i]==isArtID) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
