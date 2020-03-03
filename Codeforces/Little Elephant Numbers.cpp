#include <iostream>
#include <stdio.h>
#include <string>
#include <map>

using namespace std;
string s;
long long num,ans;
string::size_type sz;
map<long long,bool> arr;
string kk="0123456789";

void perm(int indx,string w,bool q){
    if (w.size()!=0){
        long long x=std::stoi (w,&sz);
        if (arr[x]==0 && x!=0){
            arr[x]=1;
            if (num%x==0){
                ans++;
                cout << x << endl;
            }
        }
    }
    if (indx==s.size()) return;

    for (int i=0;i<kk.size();i++){
        if (q) perm(indx+1,w+kk[i],q);
        else perm(indx+1,kk[i]+w,q);
    }
}

int main()
{
    cin >> s;
    num=std::stoi (s,&sz);
    string dumy="";
    for (int i=0;i<s.size();i++){
        if (s[i]=='0') perm(1,dumy+s[i],0);
        else perm(1,dumy+s[i],1);
    }
    printf("%lld\n",ans);
    return 0;
}
