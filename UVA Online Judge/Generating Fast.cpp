#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
set <string> ans;
set <string>::iterator it;
long long n;
string x;

int main()
{
    cin >> n;
    for (long long i=0;i<n;i++){
        it=ans.begin();
        cin >> x;
        int k=x.size();
        sort(x.begin(),x.begin()+k);
        ans.insert(x);
        while (next_permutation(x.begin(),x.begin()+k)){
            ans.insert(x);
        }
        for (set <string>::iterator it=ans.begin();it!=ans.end();++it) cout << *it << endl;
        ans.erase(ans.begin(),ans.end());
        cout << endl;
    }
    return 0;
}
