#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
string s;
long long k,pa,pb,num,ans;

int main()
{
    cin >> k >> s;
    while (pa!=s.size()-1){
        if (num!=k && pb<s.size()-1){
            pb++;
            if (s[pb]=='1'){
                num++;
            }
        }else{
            ans++;
            long long q=0;
            while (s[pa]=='0' && pa!=pb){
                pa++;
                q++;
            }
            ans+=q;
            if (pb<s.size()-1) pb++;
            while (s[pb]=='0'){
                if (q!=1) ans+=q;
                else ans++;
                if (pb<s.size()-1){
                    pb++;
                }else{
                    break;
                }
            }
            pa=pb;
            num=0;
        }
        cout << pa << "  " << pb << endl;
    }
    cout << ans << endl;
    return 0;
}
