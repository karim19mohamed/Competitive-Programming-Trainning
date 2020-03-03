#include <iostream>

using namespace std;
long long n,m;
long long x;
long long cur=1;
long long ans;

int main()
{
    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> x;
        if (x-cur>=0){
            ans=ans+x-cur;
            cur=x;
        }else{
            ans=ans+n-cur+x;
            cur=x;
        }
    }
    cout << ans << endl;
    return 0;
}
