// Solution 1
#include <iostream>
#include <vector>
#include <cstring>
#include<cstdio>

using namespace std;
int t,n,a,b;
vector <int> adj[50009];
bool ves[50009];
bool f[50009];
int res[50009];
bool ss[50009];
int ans,c;
int w=1;
void track(int u,int v);

int main()
{
    scanf("%d", &t);
    for (int k=0;k<t;k++){
        scanf("%d", &n);
        for (int i=0;i<n;i++){
            scanf("%d %d", &a, &b);
            f[b-1]=1;
            adj[a-1].push_back(b-1);
        }
        for (int i=0;i<n;i++){
            if (ss[i]==0) track(i,i);
            if (c<res[i]){
                c=res[i];
                ans=i;
            }else if (c==res[i]){
                ans=min(ans,i);
            }
        }
        printf("Case %d: %d\n", w, ans + 1);
        w++;ans=0;c=0;
        memset(ss,0,sizeof ss);
        memset(res,0,sizeof res);
        for (int i=0;i<n;i++) adj[i].erase(adj[i].begin(),adj[i].end());
    }
    return 0;
}
void track(int u,int v){
    ves[u]=1;
    ss[u]=1;
    if (ves[adj[u][0]]==0){
        res[v]++;
        track(adj[u][0],v);
    }
    ves[u]=0;
    return;
}
/* Solution 2
#include <iostream>
#include <vector>
#include <cstring>
#include<cstdio>

using namespace std;
int t,n,a,b;
vector <int> adj[50009];
bool ves[50009];
bool f[50009];
int res[50009];
int ans,c;
int w=1;
int track(int u,int v);

int main()
{
    scanf("%d", &t);
    for (int k=0;k<t;k++){
        scanf("%d", &n);
        for (int i=0;i<n;i++){
            scanf("%d %d", &a, &b);
            f[b-1]=1;
            adj[a-1].push_back(b-1);
        }
        for (int i=0;i<n;i++){
            if (res[i]==0) track(i,i);
            if (c<res[i]){
                c=res[i];
                ans=i;
            }else if (c==res[i]){
                ans=min(ans,i);
            }
        }
        printf("Case %d: %d\n", w, ans + 1);
        w++;ans=0;c=0;
        //memset(ves,0,sizeof ves);
        memset(res,0,sizeof res);
        for (int i=0;i<n;i++) adj[i].erase(adj[i].begin(),adj[i].end());
    }
    return 0;
}
int track(int u,int v){
    ves[u]=1;
    int tot=0;
    if (ves[adj[u][0]]==0){
        tot+=track(adj[u][0],v)+1;
    }
    ves[u]=0;
    return res[u]=tot;
}
*/

