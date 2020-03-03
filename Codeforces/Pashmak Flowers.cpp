#include <iostream>
#include <cmath>
#include <map>

using namespace std;
long long n,ans,d;
long long mi=10000000000;
long long ma;
long long arr[200009];
map <long long,long long> f;

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> arr[i];
        ma=max(ma,arr[i]);
        mi=min(mi,arr[i]);
        f[arr[i]]++;
    }
    d=ma-mi;
    if (ma==mi){
        ans+=( f[ma]*(f[ma]-1)/2 );
    }else{
        ans+=(f[ma]*f[mi]);
    }
    cout << d << " " << ans << endl;
    return 0;
}
