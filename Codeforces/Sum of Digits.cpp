#include <iostream>
#include <string>

using namespace std;
string n;
long long sum;
long long h;
int ans;

int main()
{
    cin >> n;
    long long k=n.size();
    if (k!=1){
        for (long long i=0;i<k;i++){
            sum+=n[i]-'0';
        }
        ans++;
        while (sum>9){
            while (sum!=0){
                h+=sum%10;
                sum=sum/10;
            }
            sum=h;
            h=0;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
