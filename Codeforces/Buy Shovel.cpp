#include <iostream>

using namespace std;
int k;
int r;
int ans=0;

int main()
{
    cin >> k >> r;
    for (int i=1;i<11;i++){
        ans++;
        if ((k*i)%10==0) break;
        if (((k*i)-r)%10==0) break;
    }
    cout << ans << endl;
    return 0;
}
