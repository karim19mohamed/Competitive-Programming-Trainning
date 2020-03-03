#include <iostream>

using namespace std;
long long n,s,t,mid;
long long ans=0;
long long arr[100009];
bool f;

int main()
{
    cin >> n >> s >> t;
    for (int i=1;i<=n;i++) cin >> arr[i];
    mid=s;
    for (int i=1;i<=n+1;i++){
        if (mid==t){
            f=1;
            break;
        }
        mid=arr[mid];
        ans++;
    }
    if (f==0) cout << "-1" << endl;
    else cout << ans << endl;
    return 0;
}
