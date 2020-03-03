#include <iostream>
#include <algorithm>

using namespace std;
int n;
int m;
int arr[109];
int ans;

int main()
{
    cin >> n;
    cin >> m;
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for (int i=0;i<m;i++){
        if (arr[i]<0){
            ans-=arr[i];
        }else{
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
