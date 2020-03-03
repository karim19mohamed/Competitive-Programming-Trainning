#include <iostream>
#include <cmath>

using namespace std;
int n;
int ans;

int main()
{
    cin >> n;
    int i=2;
    while (i<=n){
        if (n%i==0){
            int k=i;
            while (k!=0){
                if (k%10==4 || k%10==7){
                    k=k/10;
                }else{
                    break;
                }
            }
            if (k==0) {
                ans=1;
                break;
            }
        }
        i++;
    }
    if (ans==1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
