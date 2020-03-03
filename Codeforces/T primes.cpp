#include <iostream>
#include <cmath>

using namespace std;
long long n;
long long a;
bool ans=1;
long long k;

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a;
        k=sqrt(a);

        if (floor(sqrt(a))*floor(sqrt(a))==a && a!=1){
            //cout << k << endl;
            if (k!=2){
                //while (floor(sqrt(k))*floor(sqrt(k))==k) k=sqrt(k);
                for (long long j=2;j<=ceil(sqrt(k));j++){
                    if (k%j==0){
                        ans=0;
                        break;
                    }
                }
            }
        }else{
            ans=0;
        }
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
        ans=1;
    }
    return 0;
}
