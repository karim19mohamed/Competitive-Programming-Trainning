#include <iostream>
#include <cmath>

using namespace std;
int n;
int a[1009];
int b[1009];
int p;
int ans;

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i] >> b[i];
        p=p-a[i]+b[i];
        ans=max(ans,p);
    }
    cout << ans << endl;
    return 0;
}
