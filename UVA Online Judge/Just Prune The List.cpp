#include <iostream>
#include <map>
#include <set>
#include <cmath>

using namespace std;
int t,n,m;
long long ge,ans;
set <long long> x;
map <long long,long long> arr_1;
map <long long,long long> arr_2;
set<long long>::iterator it=x.begin();

int main()
{
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> n >> m;
        for (int j=0;j<n;j++) {
            cin >> ge;
            arr_1[ge]++;
            x.insert(it,ge);
        }
        for (int j=0;j<m;j++) {
            cin >> ge;
            arr_2[ge]++;
            x.insert(it,ge);
        }
        for (it=x.begin();it!=x.end();++it){
            ans+=abs(arr_1[*it]-arr_2[*it]);
            arr_1[*it]=0;
            arr_2[*it]=0;
        }
        cout << ans << endl;
        ans=0;
    }
    return 0;
}
