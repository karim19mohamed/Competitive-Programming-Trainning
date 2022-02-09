#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N = 1e5 + 7, M = 1e6 + 7, OO = 0x3f3f3f3f;
int n;

vector<pair<int, int>> adj[N];

struct node {
    int idx, xorval, par;
} q[N];
int qsz;

int bfs(int src) {
    qsz = 0;
    q[qsz++] = {src, 0, -1};
    int ans = 0;
    for (int k = 0; k < qsz; ++k) {
        node tp = q[k];
        int u = tp.idx, d = tp.xorval, p = tp.par;
        bool leaf = 1;
        for (auto e : adj[u]) {
            int v = e.first;
            int w = e.second;
            if (v == p) continue;
            leaf = 0;
            q[qsz++] = {v, d ^ w, u};
        }
        if (leaf && d == 1) ++ans;
    }
    return ans;
}


int tsts;

int main() {
#ifdef CLION
    freopen("input.in", "rt", stdin);
#endif
    cin >> tsts;
    while (tsts--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
        }
        for (int i = 0; i < n - 1; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            adj[u].emplace_back(v, c);
            adj[v].emplace_back(u, c);
        }
        cout << bfs(1) << "\n";

    }
}

















