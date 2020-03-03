#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>

using namespace std;
int k,m,n,a,b,t,arr[109][109];
long long ans[109][109],res;
queue <pair <int,int> > q;

void bfs(int i, int j){
    q.push({i,j});
    ans[i][j]=arr[i][j];
    while (!q.empty()){
        int u=q.front().first,v=q.front().second;
        q.pop();
        if (u!=0 && ans[u-1][v]>ans[u][v]+arr[u-1][v]){
            ans[u-1][v]=ans[u][v]+arr[u-1][v];
            q.push({u-1,v});
        }
        if (v!=0 && ans[u][v-1]>ans[u][v]+arr[u][v-1]){
            ans[u][v-1]=ans[u][v]+arr[u][v-1];
            q.push({u,v-1});
        }
        if (u!=m-1 && ans[u+1][v]>ans[u][v]+arr[u+1][v]){
            ans[u+1][v]=ans[u][v]+arr[u+1][v];
            q.push({u+1,v});
        }
        if (v!=n-1 && ans[u][v+1]>ans[u][v]+arr[u][v+1]){
            ans[u][v+1]=ans[u][v]+arr[u][v+1];
            q.push({u,v+1});
        }
    }
}

int main()
{
    scanf("%d",&k);
    for (int i=0;i<k;i++){
        scanf("%d%d",&m,&n);
        for (int j=0;j<m;j++){
            for (int w=0;w<n;w++){
                scanf("%d",&arr[j][w]);ans[j][w]=10000000;
            }
        }
        scanf("%d%d%d",&a,&b,&t);
        bfs(0,0);
        res=t-ans[a-1][b-1];
        //cout << ans[a-1][b-1] << endl;
        if (res>=0) printf("YES\n%lld\n",res);
        else printf("NO\n");
    }
    return 0;
}
