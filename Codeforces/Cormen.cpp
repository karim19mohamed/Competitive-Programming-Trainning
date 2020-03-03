#include <iostream>

using namespace std;
int n;
int k;
int arr[509];
int ans;

int main()
{
    cin >> n >> k;
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    for (int i=0;i<n-1;i++){
        if (arr[i]+arr[i+1]<k){
            ans+=k-(arr[i]+arr[i+1]);
            arr[i+1]=arr[i+1]+k-(arr[i]+arr[i+1]);
        }
    }
    cout << ans << endl;
    for (int i=0;i<n;i++){
        cout << arr[i];
        if (i!=n-1) cout <<" ";
    }
    cout << endl;
    return 0;
}
