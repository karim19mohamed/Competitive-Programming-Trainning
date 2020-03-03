#include <iostream>
#include <algorithm>

using namespace std;
int n;
long long arr[109];
long long a[109];
long long num;

int main()
{
    cin >> n;
    for (int i=0;i<n;i++) cin >> arr[i];
    sort (arr,arr+n);
    num=arr[n-1];
    arr[n-1]=arr[0];
    arr[0]=num;
    for (int i=0;i<n;i++) {
        cout << arr[i];
        if (i!=n-1) cout << " ";
    }
    cout << endl;
    return 0;
}
