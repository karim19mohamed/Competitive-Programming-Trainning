#include <iostream>
#include <algorithm>

using namespace std;
int n,m;
int arr[59];
int f,e;
int ans=10000;

int main()
{
    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> arr[i];
    }
    sort(arr,arr+m);
    e=n-1;
    while (e<=m-1){
        ans=min(ans,arr[e]-arr[f]);
        f++;
        e++;
    }
    cout << ans << endl;
    return 0;
}
