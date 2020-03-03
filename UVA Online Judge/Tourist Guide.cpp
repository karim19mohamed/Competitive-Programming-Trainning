#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;
int n,r,c,tc;
map <string,int> arr;
map <int,string> ans;
string res[109];
string s,a,b;

int head[109],nxt[10009],to[10009],ne;
void init (int N){
    ne=0;c=0;
    memset(head,-1,N*sizeof(head[0]));
}
void addEdge (int i,int j){
    nxt[ne]=head[i];
    to[ne]=j;
    head[i]=ne++;
}
int nxtTime,cntRootChildern,rootID,low[109],dfsTime[109];
int isArtID,isBrdgeID,isArt[109],isBrdge[10009],stk[10009],ncomp,compID[10009];
void biConCompdfs(int i,int pe=-1){
    dfsTime[i]=low[i]=nxtTime++;
    for (int k=head[i];~k;k=nxt[k]){
        if ((k^1)==pe) continue;
        int j=to[k];
        if (!~dfsTime[j]){
            biConCompdfs(j,k);
            low[i]=min(low[i],low[j]);
            if (i==rootID){
                if (++cntRootChildern>1){
                    isArt[i]=isArtID;
                }
            }else if (low[j]>=dfsTime[i]){
                isArt[i]=isArtID;
            }
            if (low[j]>dfsTime[i]){
                isBrdge[k]=isBrdge[k^1]=isBrdgeID;
            }
        }else{
            low[i]=min(low[i],dfsTime[j]);
        }
    }
}
void biConComp(){
    nxtTime=0;
    ncomp=0;
    memset(dfsTime,-1,n*sizeof(dfsTime[0]));
    isArtID++;isBrdgeID++;
    for (rootID=0;rootID<n;rootID++){
        cntRootChildern=0;
        if (!~dfsTime[rootID]){
            biConCompdfs(rootID);
        }
    }
}

int main()
{
    bool dumy=0;
    while (scanf("%d",&n),n){
        init(n);
        if (dumy) cout << endl;
        dumy=1;
        for (int i=0;i<n;i++){
            cin >> s;
            arr[s]=i;
            ans[i]=s;
        }
        scanf("%d",&r);
        for (int i=0;i<r;i++){
            cin >> a >> b;
            addEdge(arr[a],arr[b]);
            addEdge(arr[b],arr[a]);
        }
        biConComp();
        for (int i=0;i<n;i++){
            if(isArt[i]==isArtID){
                res[c]=ans[i];
                c++;
            }
        }
        sort(res,res+c);
        printf("City map #%d: %d camera(s) found\n",++tc,c);
        for (int i=0;i<c;i++) cout << res[i] << endl;
    }
    return 0;
}
