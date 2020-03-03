#include <iostream>

using namespace std;
long long n;
int ans=1;

int main()
{
    cin >> n;
    while (ans==1 && n!=0){
        if (n%1000==144){
            n=n/1000;
        }else if (n%100==14){
            n=n/100;
        }else if (n%10==1){
            n=n/10;
        }else{
            ans=0;
        }
    }
    if (ans==1) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
