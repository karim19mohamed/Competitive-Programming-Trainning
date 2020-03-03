#include <iostream>
#include <string>

using namespace std;
int n;
string s1[109];

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> s1[i];
    }
    for (int i=0;i<n;i++){
        int k=s1[i].size();
        if (k>10){
            cout << s1[i][0] << k-2 << s1[i][k-1] << endl;
        }else{
            cout << s1[i] << endl;
        }
    }
    return 0;
}
