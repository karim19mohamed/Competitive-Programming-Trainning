#include <iostream>
#include <map>
#include <string>
#include <ctype.h>

using namespace std;
int m,n;
map <string,long long> arr;
string x,q;
long long y,k;
long long ans;

int main()
{
    cin >> m >> n;
    for (int i=0;i<m;i++){
        cin >> x;
        cin >> y;
        arr[x]= y;
    }
    getline(cin,x);
    for (int i=0;i<n;i++){
        while (1){
            getline(cin,x);
            k=x.size();
            if (x[k-1]=='.') break;
            for (int j=0;j<k;j++){
                if (isspace(x[j])){
                    ans+=arr[q];
                    q="";
                }else{
                    q=q+x[j];
                }
            }
            ans+=arr[q];
            q="";
        }
        cout << ans << endl;
        ans=0;
    }
    return 0;
}
