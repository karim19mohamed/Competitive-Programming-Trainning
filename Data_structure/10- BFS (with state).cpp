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

struct node {
    int idx, dis, par;
} q[N];
int qsz;

int bfs(int src, int snk) {
    qsz = 0;
    q[qsz++] = {src, 0, -1};
    vis[src] = ++vid;
    for(int k = 0; k < qsz; ++k){
        node tp = q[k];
        int u = tp.idx, d = tp.dis;
        if (u == snk) return k;
        for (int v = 0; v < n; ++v) {
            if (mat[u][v] == 0 || vis[v] == vid) continue;
            q[qsz++] = {v, d + 1, k};
            vis[v] = vid;
        }
    }
    return -1;
}

void printPath(int k) {
    if (k == -1) return;
    printPath(q[k].par);
    cout << q[k].idx << " ";
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
        int k = bfs(u, v);
        cout << q[k].dis << endl;
        printPath(k);
        cout << "\n";
    }
}

















