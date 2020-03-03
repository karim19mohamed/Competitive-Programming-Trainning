#include <iostream>
#include <cstring>
#include <stdio.h>
#include <set>
#include <string>

using namespace std;
int n,m,a,num,b;
char dumy;
set <pair<int,int> > q;
std::set<pair<int,int> >::iterator it;

int head[100009],nxt[200009],to[200009],ne;
void init(int N){
    memset(head,-1,N*sizeof(head[0]));
    ne=0;
    m=0;
    q.erase(q.begin(),q.end());
}
void addEdge(int i,int j){
    nxt[ne]=head[i];
    to[ne]=j;
    head[i]=ne++;
}
int rootID,nxtTime,dfsTime[100009],low[100009],cntRootChildern;
int isArtID,isArt[100009],isBrdgeID,isBrdge[200009],stk[200009],stkSz,nocomp,compID[200009];
void biConCompDFS(int i,int pe=-1){
    dfsTime[i]=low[i]=nxtTime++;
    for (int k=head[i];~k;k=nxt[k]){
        if ((k^1)==pe) continue;
        int j=to[k];
        if (!~dfsTime[j]){
            stk[stkSz++]=k;
            biConCompDFS(j,k);
            low[i]=min(low[i],low[j]);
            if (i==rootID){
                if(++cntRootChildern>1){
                    isArt[i]=isArtID;
                }
            }else if (low[j]>=dfsTime[i]){
                isArt[i]=isArtID;
            }
            if (low[j]>dfsTime[i]){
                q.insert({min(to[k],to[k^1]),max(to[k],to[k^1])});
                isBrdge[k]=isBrdgeID;isBrdge[k^1]=isBrdgeID;
            }
        }else{
            if (dfsTime[j]<dfsTime[i]) stk[stkSz++]=k;
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
        cntRootChildern=0;
        if (!~dfsTime[rootID]){
            biConCompDFS(rootID);
        }
    }
}

int main()
{
    while (cin >> n){
        init(n);
        for (int i=0;i<n;i++){
            scanf("%d",&a);
            scanf("%c",&dumy);scanf("%c",&dumy);
            scanf("%d",&num);
            scanf("%c",&dumy);scanf("%c",&dumy);
            for (int j=0;j<num;j++){
                scanf("%d",&b);
                if (b>a){
                    addEdge(a,b);
                    addEdge(b,a);
                }
            }
        }
        biConComp();
        int Sz=q.size();
        printf("%d critical links\n",Sz);
        for (it=q.begin() ; it!=q.end() ; ++it){
            pair <int,int> mm=*it;
            printf("%d - %d\n",mm.first,mm.second);
        }
        printf("\n");
    }
    return 0;
}
