#include <iostream>
#include <cmath>

using namespace std;
long long n,ans,u;
long long arr[100009];
bool ves[100009];
bool x,y;

int main()
{
    cin >> n;
    for (long long i=0;i<n;i++){
        cin >> arr[i];
        if (arr[i]==i){
            ans++;
            ves[i]=1;
        }
    }
    for (long long i=0;i<n;i++){
        if (ves[i]==0){
            u=arr[i];
            if (ves[u]==0){
                x=1;
                if (ves[arr[u]]==0 && arr[arr[u]]==u){
                    y=1;
                }
            }
        }
    }
    if (y) cout << ans+2 << endl;
    else if (x) cout << ans+1 << endl;
    else cout << ans << endl;
    return 0;
}
