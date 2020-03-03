#include <iostream>
#include <string>

using namespace std;
int k;
string n,res;
int arr[40];
int ans;
int all_zero=1;

int main()
{
    cin >> k;
    cin >> n;
    int e=n.size();
    for (int i=0;i<e;i++){
        arr[n[i]-'a']++;
    }
    for (int i=0;i<40;i++){
        if (arr[i]!=0)
        if (arr[i]!=0 && arr[i]%k!=0){
            ans=-1;
            break;
        }
    }
    if (ans==-1){
        cout << "-1" << endl;
    }else{
        for (int q=0;q<k;q++){
            for (int i=0;i<30;i++){
                if (arr[i]!=0){
                    for (int j=0;j<arr[i]/k;j++){
                        char x=i+'a';
                        res=res+x;
                    }
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
