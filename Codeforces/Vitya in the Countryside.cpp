#include <iostream>

using namespace std;
int n;
int a[100];
int arr_for[16]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
int arr_rev[15]={14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    if (n!=1){
        int dir=a[n-1]-a[n-2];
        int nex;
        if(dir==1){
            nex=a[n-1]+1;
            if (nex<=15){
                cout << "UP" << endl;
            }else{
                cout << "DOWN" << endl;
            }
        }else{
            nex=(14-a[n-1])+1;
            if (nex<=14){
                cout << "DOWN" << endl;
            }else{
                cout << "UP" << endl;
            }
        }
    }else{
        if (a[0]==0) {
            cout << "UP" << endl;
        }else if (a[0]==15) {
            cout << "DOWN" << endl;
        }else{
            cout <<"-1"<<endl;
        }
    }
    return 0;
}
