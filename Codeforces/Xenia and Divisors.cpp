#include <iostream>
#include <stack>

using namespace std;
long long n;
int arr[100009];
long long freq[100009];
int ans;
stack <string> x;

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }
    if (freq[4]<=freq[2] && freq[4]<=freq[1] && freq[4]!=0){
            for (int i=0;i<freq[4];i++){
                x.push("1 2 4");
                freq[2]--;freq[1]--;
            }
    }
    if (freq[6]==freq[1] && freq[6]!=0){
        for (int i=0;i<freq[2];i++){
            x.push("1 2 6");
        }
        for (int i=0;i<freq[3];i++){
            x.push("1 3 6");
            //cout << "adsas" << endl;
        }
    }
    if (x.size()==n/3){
        while (!x.empty()){
            cout << x.top() << endl;
            x.pop();
        }
    }else{
        cout << "-1" << endl;
    }
    return 0;
}
