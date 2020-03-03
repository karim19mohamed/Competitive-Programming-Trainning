#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
set <string> arr;
set<string>::iterator it;
string x,y;
int k;
int f=-1,e=-1;
bool flag=0;

int main()
{
    while (cin >> x){
        k=x.size();
        while ((x[0]<'a' || x[0]>'z') && (x[0]<'A' || x[0]>'Z')){
            x.erase(x.begin());
            k--;
        }
        while ((x[k-1]<'a' || x[k-1]>'z') && (x[k-1]<'A' || x[k-1]>'Z')){
            x.erase(x.begin()+k-1);
            k--;
        }
        e=k;
        for (int i=0;i<k;i++){
            if (x[i]>='A' && x[i]<='Z') {
                x[i]+=32;
            }else if (x[i]<'a' || x[i]>'z'){
                x[i]='.';
            }
            cout << "asasda" << endl;
        }
        cout << x << endl;

        for (int i=0;i<k;i++){
            if (x[i]!='.' && flag==0){
                flag=1;
                f=i;
            }
            if (flag=1 && x[i]=='.'){
                arr.insert(x.substr(f,i-1));
                cout << x.substr(f,i-1) << endl;
                flag=0;
                x.erase(f,i-1);
                i=0;
                k=k-i+1+f;
            }
        }
        if (x.size()!=0){
            arr.insert(x);
        }
    }
    for (it=arr.begin(); it!=arr.end(); ++it) cout << *it << endl;
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
set <string> arr;
set<string>::iterator it;
string x;
int k;
bool q=1;

int main()
{
    while (cin >> x){
        k=x.size();
        for (int i=0;i<k;i++){
            if (x[i]>='A' && x[i]<='Z') {
                x[i]+=32;
            }else if (x[i]<'a' || x[i]>'z'){
                x.erase(x.begin()+i);
                k--;
                i--;
                //cout << k << "  " << i << "   " << x[i] << endl;
            }
        }
        //cout << x << endl;
        if (x.size()!=0){
            arr.insert(x);
        }
    }
    //k=arr.size();
    //sort(arr.begin(),arr.end());
    //for (int i=0;i<k;i++) cout << arr[i] << endl;
    for (it=arr.begin(); it!=arr.end(); ++it) cout << *it << endl;
    return 0;
}
*/
