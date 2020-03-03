#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <map>

using namespace std;
int n,m,indx,tc;
string a,b;
map <string,int> arr;
map <int,string> res;
int head[30], nxt[200009], to[200009], ne;
void init(int n) {
	memset(head, -1, n * sizeof(head[0]));
	ne = 0;
	indx=0;
}
void addEdge(int f, int t) {
	nxt[ne] = head[f];
	to[ne] = t;
	head[f] = ne++;
}
int low[30],dfsTime[30],nxtTime,stk[30],stkSz,ncomp,compID[30];
void sccdfs(int i){
    dfsTime[i]=low[i]=nxtTime++;
    stk[stkSz++]=i;
    for (int k=head[i];~k;k=nxt[k]){
        int j=to[k];
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
    for (int i=0;i<n;i++){
        if (!~dfsTime[i]) sccdfs(i);
    }
}

int main()
{
    bool dumy=0;
    while (scanf("%d%d",&n,&m),n){
        if (dumy) printf("\n");
        dumy=1;
        init(n);
        for (int i=0;i<m;i++){
            cin >> a >> b;
            if (arr[a]==0){
                arr[a]=++indx;
                res[indx]=a;
            }
            if (arr[b]==0){
                arr[b]=++indx;
                res[indx]=b;
            }
            addEdge(arr[a]-1,arr[b]-1);
        }
        scc();
        printf("Calling circles for data set %d:\n",++tc);
        for (int i=0;i<ncomp;i++){
            bool k=0;
            for (int j=0;j<n;j++){
                if (compID[j]==i){
                    if (k) cout <<", ";
                    k=1;
                    cout << res[j+1];
                    arr[res[j+1]]=0;
                }
            }
            printf("\n");
        }
    }
    return 0;
}
