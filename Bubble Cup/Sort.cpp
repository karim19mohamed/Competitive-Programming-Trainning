#include <iostream>
#include <algorithm>

using namespace std;
long long n,arr[1000009];

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for (int i=0;i<n;i++){
        cout << arr[i];
        if (i!=n-1) cout << " ";
    }
    cout << endl;
    return 0;
}
