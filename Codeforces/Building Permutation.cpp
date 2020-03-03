#include <iostream>
#include <algorithm>

using namespace std;
long long n,ans;
//long long in;
long long arr[300009];
//long long ves[300009];

int main()
{
    cin >> n;
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for (long long i=0;i<n;i++){
        if (arr[i]!=i+1){
            ans+=abs(i+1-arr[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
/*

    in=1;
    for (long long i=0;i<n;i++){
        if (ves[arr[i]]==0){
            ves[arr[i]]=1;
            continue;
        }else{
            if (pre==arr[i]){
                in++;
            }else{
                in=1;
            }
            ans+=in;
            arr[i]+=in;
            ves[arr[i]]=1;
            pre=arr[i];
        }
    }
*/
