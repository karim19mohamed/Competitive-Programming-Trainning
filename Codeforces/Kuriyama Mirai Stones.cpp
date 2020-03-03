#include <iostream>
#include <algorithm>

using namespace std;
int n,m,l,r,indx;
long long arr[100009];
long long arr_s[100009];
long long ans;

int main()
{
    cin >> n;
    for (int i=1;i<n+1;i++){
        cin >> arr[i];
        arr_s[i]=arr[i];
        arr[i]+=arr[i-1];
        //cout << arr[i] << endl;
    }
    sort (arr_s,arr_s+n+1);
    for (int i=1;i<n+1;i++){
        arr_s[i]+=arr_s[i-1];
    }
    cin >> m;
    for (int i=0;i<m;i++){
        cin >> indx >> l >> r;
        if (indx==1){
            ans=arr[r]-arr[l-1];
            cout << ans << endl;
        }else{
            ans=arr_s[r]-arr_s[l-1];
            cout << ans << endl;
        }
    }
    return 0;
}
