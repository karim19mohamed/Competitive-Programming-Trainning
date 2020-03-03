#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;
int n,ans;
string s;

int head[100009],nxt[200009],to[200009],ne;
void init(int N){
    memset(head,-1,N*sizeof(head[0]));
    ne=0;
    ans=0;
}
void addEdge(int i,int j){
    nxt[ne]=head[i];
    to[ne]=j;
    head[i]=ne++;
}
int rootID,nxtTime,dfsTime[100009],low[100009],cntRootChildern;
int isArtID,isArt[100009],isBrdgeID,isBrdge[200009],stk[200009],stkSz,nocomp,compID[200009];
void extractComp(int k){
    do{
        int e=stk[--stkSz];
        compID[e]=compID[e^1]=nocomp;
    }while(stk[stkSz]!=k);
    nocomp++;
}
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
                    isArt[i]=isArtID;extractComp(k);
                }
            }else if (low[j]>=dfsTime[i]){
                isArt[i]=isArtID;extractComp(k);
            }
            if (low[j]>dfsTime[i]){
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
    while (scanf("%d",&n),n){
        init(n);
        string dumy;getline(cin, dumy);
        while (1)
        {
            getline(cin, s);
            istringstream iss(s);
            int a;
            int b;
            iss >> a;
            if (a == 0) break;
            while (iss >> b)
            {
                addEdge(a-1,b-1);
                addEdge(b-1,a-1);
            }
        }
        biConComp();
        for (int i=0;i<n;i++){
            if (isArt[i]==isArtID) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
