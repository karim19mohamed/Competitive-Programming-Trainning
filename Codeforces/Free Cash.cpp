#include <iostream>

using namespace std;
long long n,ans;
int a,b;
long long arr[29][69];

int main()
{
    cin >> n;
    for (long long i=0;i<n;i++){
        cin >> a >> b;
        arr[a][b]++;
        ans=max(ans,arr[a][b]);
    }
    cout << ans << endl;
    return 0;
}
