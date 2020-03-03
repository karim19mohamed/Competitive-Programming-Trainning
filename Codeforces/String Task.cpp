#include <iostream>
#include <string>

using namespace std;
string n,ans;

int main()
{
    cin >> n;
    int k=n.size();
    for (int i=0;i<k;i++){
        if (n[i]<'a') n[i]+=32;
        if (n[i]=='a' || n[i]=='e' || n[i]=='i' || n[i]=='o' || n[i]=='u' || n[i]=='y'){
            continue;
        }else{
            ans=ans+"."+n[i];
        }
    }
    cout << ans << endl;
    return 0;
}
