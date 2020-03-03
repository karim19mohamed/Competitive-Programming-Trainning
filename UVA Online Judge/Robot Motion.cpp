#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
int n,m,s;
vector <pair <int,int> > adj[19][19];
int ves[19][19];
string s1;
int ans,loop;
void track(int x,int y);

int main()
{
    while (1){
        cin >> n >> m >> s;
        if (n==0) break;
        s--;
        for (int i=0;i<n;i++){
            cin >> s1;
            for (int j=0;j<m;j++){
                if (s1[j]=='N' && i-1>=0) adj[i][j].push_back(make_pair(i-1,j));
                else if (s1[j]=='S' && i+1<n) adj[i][j].push_back(make_pair(i+1,j));
                else if (s1[j]=='E' && j+1<m) adj[i][j].push_back(make_pair(i,j+1));
                else if (s1[j]=='W' && j-1>=0) adj[i][j].push_back(make_pair(i,j-1));
            }
        }
        memset(ves,-1,sizeof(ves[0][0])*19*19);
        ves[0][s]=0;
        track(0,s);
        if (loop==0) cout << ans+1 << " step(s) to exit" << endl;
        else cout << ans << " step(s) before a loop of " << loop << " step(s)" << endl;
        ans=0;loop=0;
        for (int i=0;i<19;i++) for (int j=0;j<19;j++) adj[i][j].erase(adj[i][j].begin(),adj[i][j].end());
    }
    return 0;
}
void track(int x,int y){
    if (!adj[x][y].empty()){
        if ( ves[adj[x][y][0].first][adj[x][y][0].second]==-1 ){
            ves[adj[x][y][0].first][adj[x][y][0].second]=ves[x][y]+1;
            track(adj[x][y][0].first,adj[x][y][0].second);
            ans++;
        }else{
            loop=ves[x][y]+1-ves[adj[x][y][0].first][adj[x][y][0].second];
            ans=ans-loop+1;
        }
    }
    return;
}






