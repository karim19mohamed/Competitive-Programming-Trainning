#include <iostream>
#include <cstring>
#include <stdio.h>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n,m,k,a,b,vis[109],vid=1;
vector <int> adj[109];

queue <int> q;
string s;

void dfs(int u){
    vis[u]=vid;
    for (int k=0;k<adj[u].size();k++){
        if (vis[ adj[u][k] ]!=vid) dfs(adj[u][k]);
    }
    q.push(u);
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++){
        scanf("%d%d",&a,&k);
        for (int j=0;j<k;j++){
            scanf("%d",&b);
            adj[a-1].push_back(b-1);
        }
        int c=adj[a-1].size();
        sort(adj[a-1].begin(),adj[a-1].end());
    }
    for (int i=0;i<n;i++){
        if (vis[i]!=vid) dfs(i);
    }
    while (!q.empty()){
        int w=q.front()+1;
        q.pop();
        printf("%d",w);
        if (q.size()!=0) printf(" ");
    }
    printf("\n");
    return 0;
}
