#include <iostream>

using namespace std;
int n;
int arr[1009];
int no_zero;
int no_five;
int max_five;

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> arr[i];
        if (arr[i]==0) no_zero++;
        if (arr[i]==5) no_five++;
    }
    if (no_zero==0) {
        cout <<"-1"<< endl;
    }else{
        while (no_five!=0){
            if ((no_five*5)%9==0) {
                max_five=no_five;
                break;
            }else{
                no_five--;
            }
        }
        for (int i=0;i<max_five;i++){
            cout << "5";
        }
        if (max_five!=0){
            for (int i=0;i<no_zero;i++){
                cout << "0";
            }
            cout << endl;
        }else{
            cout << "0" << endl;
        }
    }
    return 0;
}
