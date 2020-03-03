#include <iostream>
#include <string>

using namespace std;
int t;
long long n;
string s;
long long ans=1;

int main()
{
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> n >> s;
        int k=s.size();
        for (int j=n;j>0;j-=k){
            ans*=j;
        }
        cout << ans << endl;
        ans=1;
    }
    return 0;
}
