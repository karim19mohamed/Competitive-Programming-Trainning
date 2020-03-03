#include <iostream>

using namespace std;
int n;
long long arr[111][111];
long long ans=-127000000;

int main()
{
    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> arr[i][j] ;
            arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }
    long long num;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int k=i;k<=n;k++){
                for (int l=j;l<=n;l++){
                    num=arr[k][l]-arr[i-1][l]-arr[k][j-1]+arr[i-1][j-1];
                    ans=max(ans,num);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
