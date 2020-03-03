#include <iostream>
#include <string>

using namespace std;
string x;
string ans;
long long k;
long long y;
bool q;


int main()
{
    string::iterator it=ans.begin();
    while(1){
        getline(cin,x);
        k=x.size();
        if (k==0) break;
        for (int i=0;i<k;i++){
            if (x[i]=='['){
                q=1;
                y=0;
                continue;
            }else if (x[i]==']'){
                q=0;
                y=0;
                continue;
            }
            if (q==0) {
                ans=ans+x[i];
            }else if (q==1) {
                it+=y;
                ans.insert(it,x[i]);
                y++;
            }
            //cout << ans << endl;
        }
        cout << ans << endl;
        ans="";
        q=0;
    }
    cout << endl;
    return 0;
}
