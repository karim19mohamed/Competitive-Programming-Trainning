#include <iostream>
#include <cmath>

using namespace std;
int n;
long long x;
long long ans=1000000009;
int s;

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> x;
        if (x<ans){
            s=i+1;
            ans=x;
        }else if (x==ans){
            s=-1;
            //break;
        }
    }
    if (s!=-1) cout << s << endl;
    else cout << "Still Rozdil" << endl;
    return 0;
}
