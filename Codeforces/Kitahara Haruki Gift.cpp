#include <iostream>
#include <algorithm>

using namespace std;
int n,num_1,num_2;
long long w[109];
int ans=0;
long long tot_sum;

int main()
{
    cin >> n;
    for (int i=1;i<n+1;i++){
        cin >> w[i];
    }
    sort (w,w+n+1);
    for (int i=1;i<n+1;i++){
        w[i]+=w[i-1];
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<=i;j++){
            if (w[i]-w[j]==w[n]-w[i]+w[j]) {
                ans=1;
                break;
            }
        }
    }
    if (ans==1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
