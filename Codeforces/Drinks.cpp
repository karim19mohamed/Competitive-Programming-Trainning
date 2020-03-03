#include <iostream>

using namespace std;
double n;
double p[109];
double sum;
double ans;

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> p[i];
        sum+=p[i];
    }
    ans=sum/n;
    cout << ans << endl;
    return 0;
}
