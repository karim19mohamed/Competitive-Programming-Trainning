#include <iostream>
#include <cstring>
#include <stdio.h>
#include <bitset>

using namespace std;
int t,n,m,a,b,head[20],arr[40][2],nxt[40],to[40],ne,ans;
long long res;
int vis[20],vid=1;

void addEdge (int f,int t){
    nxt[ne]=head[f];
    to[ne]=t;
    head[f]=ne++;
}
void dfs (int u){
    vis[u]=vid;ans++;
    //cout <<vid<< "  " << u << " "<< ans<<endl;
    for (int k=head[u];~k;k=nxt[k]){
        int j=to[k];
        if (vis[j]!=vid) dfs(j);
    }
}

int main()
{
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%d%d",&n,&m);
        for(int j=0;j<m;j++){
            scanf("%d%d",&a,&b);
            arr[j][0]=a-1;arr[j][1]=b-1;
        }
        int num=n-1;
        bitset <12> take=000000000000;
        int x=0;
        int node;
        while (take.count()!=m){
            x=x+1;
            take=x;
            if (take.count()==num){
                ne=0;
                memset(head,-1,n*sizeof(head[0]));
                for (int i=0;i<m;i++){
                    if (take[i]==1) {
                        addEdge(arr[i][0],arr[i][1]);
                        addEdge(arr[i][1],arr[i][0]);
                        node=arr[i][0];
                        //cout << arr[i][0] << "  " << arr[i][1] << endl;
                    }
                }
                ans=0;
                dfs(node);
                vid++;
                if (ans==n) res++;
            }
        }
        if (n!=1) printf("%lld\n",res);
        else printf("1\n");
        res=0;
    }
    return 0;
}
