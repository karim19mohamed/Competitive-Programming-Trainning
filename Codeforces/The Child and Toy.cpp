#include <iostream>

using namespace std;
long long e[1009];
long long ans;
int n,m,a,b;

int main()
{
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> e[i];
    for (int i=0;i<m;i++){
        cin >> a >> b;
        ans+=min(e[a-1],e[b-1]);
    }
    cout << ans << endl;

    return 0;
}
