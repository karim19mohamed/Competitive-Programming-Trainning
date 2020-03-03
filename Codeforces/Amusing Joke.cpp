#include <iostream>
#include <map>

using namespace std;
map <char,int> arr1;
string x,y,z;
int sum;
bool ans=1;

int main()
{
    cin >> x >> y >> z;
    for (int i=0;i<x.size();i++) arr1[x[i]]++;
    for (int i=0;i<y.size();i++) arr1[y[i]]++;
    sum+=x.size()+y.size();
    int k=z.size();
    for (int i=0;i<k;i++){
        if (arr1[z[i]]==0){
            ans=0;
            break;
        }else{
            arr1[z[i]]--;
            sum--;
        }
    }
    //cout << sum << endl;
    if (sum!=0 || ans==0) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}
