#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 1500 + 7, M = 1e6 + 7, OO = 0x3f3f3f3f;
int n, m;

//vector<int> adj[N];
int mat[N][N];

/*int grid[N][N];
R, L, U, D, UR, UL, DR, DL"
int di[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dj[] = {1, -1, 0, 0, 1, -1, 1, -1};
*/
int vis[N], vid;

int dis[N];
int par[N];

void bfs(int src) {
    ++vid;
    queue<int> q;
    q.push(src);
    par[src] = -1;
    vis[src] = vid;
    int lvl = 0;
    while (q.size()) {
        int sz = q.size();
        while (sz--) {
            int u = q.front();
            dis[u] = lvl;
            q.pop();
            for(int i = 0; i < n; ++i){
                if(mat[u][i] == 0) continue;
                int v = i;

                if (vis[v] == vid) continue;
                q.push(v);
                par[v] = u;
                vis[v] = vid;
            }
        }
        //if previous sz is done
        ++lvl;
    }
}

void printPath(int v){
    if (v == -1) return;
    printPath(par[v]);
    cout << v << " ";
}

int tsts;

int main() {
#ifdef CLION
    freopen("input.in", "rt", stdin);
#endif
    cin >> tsts;
    while (tsts--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> mat[i][j];
                /*
                 * cin >> v;
                 * if (v) adj[i].push_back(j);
                 */
            }
        }
        int u, v;
        cin >> u >> v;
        bfs(u);
        cout << dis[v] << "\n";
        printPath(v);
        cout << "\n";
    }
}

















