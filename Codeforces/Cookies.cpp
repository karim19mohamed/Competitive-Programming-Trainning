#include <iostream>

using namespace std;
int n;
int arr[109];
int no_odd,no_even;
int ans;

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> arr[i];
        if (arr[i]%2==0) no_even++;
        if (arr[i]%2!=0) no_odd++;
    }
    if (no_odd%2==0){
        ans=ans+no_even;
    }else{
        ans=ans+no_odd;
    }
    cout << ans << endl;
    return 0;
}
