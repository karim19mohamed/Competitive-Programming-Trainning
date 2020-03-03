#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
int n,m,c;
bool arr[109][109];
string s;
vector <int> adj[10009];
bool ves[10009];
queue <int> q;
int ans;
void dfs (int u);

int main()
{
    while (1){
        cin >> n >> m;
        if (n==0) break;
        for (int i=0;i<n;i++){
            cin >> s;
            for (int j=0;j<s.size();j++){
                if (s[j]=='@') arr[i][j]=1;
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (arr[i][j]==1){
                    q.push(c);
                    if (j-1>=0){
                        if (arr[i][j-1]==1) adj[c].push_back(c-1);
                        if (arr[i+1][j-1]==1) adj[c].push_back(c+m-1);
                    }
                    if (j-1>=0 && i-1>=0){
                        if (arr[i-1][j-1]==1) adj[c].push_back(c-m-1);
                    }
                    if (i-1>=0){
                        if (arr[i-1][j]==1) adj[c].push_back(c-m);
                        if (arr[i-1][j+1]==1) adj[c].push_back(c-m+1);
                    }
                    if (arr[i][j+1]==1) adj[c].push_back(c+1);
                    if (arr[i+1][j]==1) adj[c].push_back(c+m);
                    if (arr[i+1][j+1]==1) adj[c].push_back(c+m+1);
                }
                c++;
            }
        }
        while (!q.empty()){
            if (ves[q.front()]==0){
                dfs(q.front());
                ans++;
            }
            q.pop();
        }
        cout << ans << endl;
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) arr[i][j]=0;
        for (int i=0;i<n*m;i++) adj[i].erase(adj[i].begin(),adj[i].end());
        memset(ves,0,sizeof ves);
        c=0;
        ans=0;
    }
    return 0;
}
void dfs (int u){
    ves[u]=1;
    for (int i=0;i<adj[u].size();i++){
        if (ves[adj[u][i]]==0) dfs(adj[u][i]);
    }
    return;
}



