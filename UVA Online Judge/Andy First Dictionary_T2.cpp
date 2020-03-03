#include <iostream>
#include <string>
#include <set>

using namespace std;
string arr[1000000];
string x;
set <string> ans;
set<string>::iterator it;
int k=0;
int indx=0;
bool q=0;

int main()
{
    while (cin >> x){
        k=x.size();
        for (int i=0;i<k;i++){
            while ((x[i]>='a' && x[i]<='z') || (x[i]>='A' && x[i]<='Z')){
                if (x[i]>='A' && x[i]<='Z') x[i]+=32;
                arr[indx]=arr[indx]+x[i];
                i++;
                q=1;
            }
            if (q==1){
                //cout << arr[indx] << endl;
                ans.insert(arr[indx]);
                indx++;
                q=0;
            }
        }
    }
    for (it=ans.begin(); it!=ans.end(); ++it) cout << *it << endl;
    //cout << endl;
    return 0;
}
