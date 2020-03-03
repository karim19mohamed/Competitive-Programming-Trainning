#include <iostream>
#include <map>
#include <string>
#include <ctype.h>

using namespace std;
string x,y,in,ans;
map <string,string> arr;
long long k;
bool q;

int main()
{
    while (1){
        getline(cin,in);
        if (in=="") break;
        k=in.size();
        for (int i=0;i<k;i++){
            if (isspace(in[i])) {
                q=1;
                continue;
            }
            if (q==0) x=x+in[i];
            else y=y+in[i];
        }
        arr[y]=x;
        q=0;
        x="";
        y="";
    }
    while (cin >> y){
        if (arr[y].size()!=0) cout << arr[y] << endl;
        else cout << "eh" << endl;
    }
    return 0;
}

