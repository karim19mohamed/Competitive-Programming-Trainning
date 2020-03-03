#include <iostream>
#include <string>
#include <vector>

using namespace std;
long long ans=-1,sz,pr;
string s,w;
vector <string> arr;

int main()
{
    cin >> s;
    arr.push_back("4");
    arr.push_back("7");
    while (ans==-1){
        sz=arr.size();
        for (int i=pr;i<sz;i++){
            w=arr[i];
            if (w==s) ans=i+1;
            arr.push_back("4"+w);
        }
        for (int i=pr;i<sz;i++){
            w=arr[i];
            if (w==s) ans=i+1;
            arr.push_back("7"+w);
        }
        pr=sz;
    }
    cout << ans << endl;
    return 0;
}