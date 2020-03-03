#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstring>

using namespace std;
bool ans;
int n,m,k,arr[109][109],a,b,c,d,e,f;
int cat[109][109],mou[109][109];
queue <pair<int,int> > q;

void bfs (int x,int y, int dist[109][109]){
    q.push({x,y});
    dist[x][y]=0;
    while (!q.empty()){
        int i=q.front().first,j=q.front().second;
        //cout << i << " " << j << endl;
        q.pop();
        if (i-1>=0 && dist[i-1][j]>dist[i][j]+1){
            q.push({i-1,j});dist[i-1][j]=dist[i][j]+1;
        }
        if (j-1>=0 && dist[i][j-1]>dist[i][j]+1){
            q.push({i,j-1});dist[i][j-1]=dist[i][j]+1;
        }
        if (i+1<=n-1 && dist[i+1][j]>dist[i][j]+1){
            q.push({i+1,j});dist[i+1][j]=dist[i][j]+1;
        }
        if (j+1<=m-1 && dist[i][j+1]>dist[i][j]+1){
            q.push({i,j+1});dist[i][j+1]=dist[i][j]+1;
        }
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<k;i++){
        ans=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cat[i][j]=10000;mou[i][j]=10000;
            }
        }
        scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
        bfs(a-1,b-1,mou);
        bfs(c-1,d-1,cat);
        bfs(e-1,f-1,cat);
        for (int i=0;i<n;i++){
            if (cat[i][0]>mou[i][0] || cat[i][m-1]>mou[i][m-1]){
                ans=1;
            }
        }
        for (int i=0;i<m;i++){
            if (cat[0][i]>mou[0][i] || cat[n-1][i]>mou[n-1][i]){
                ans=1;
            }
        }
        if (ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
