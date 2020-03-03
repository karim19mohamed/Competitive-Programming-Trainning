#include <iostream>

using namespace std;
long long n,ans;
long long arr[1000000];

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> arr[i];
        ans=max(ans,arr[i]);
    }
    cout << ans << endl;
    return 0;
}
