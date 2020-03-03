#include <iostream>
#include <cmath>

using namespace std;
int n;
long long k;
long long f,t;
long long ans=-1*1e10;

int main()
{
    cin >> n >> k;
    for (int i=0;i<n;i++){
        cin >> f >> t;
        if (t>k){
            ans=max(ans,(f-t+k));
        }else{
            ans=max(ans,f);
        }
    }
    cout << ans << endl;
    return 0;
}
