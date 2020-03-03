#include <iostream>

using namespace std;
int n;

int main()
{
    cin >> n;
    int k=n;
    for (int i=0;i<2*n+1;i++){
        int num=0;
        k=n-i;
        for (int j=0;j<=n+i;j++){
            if (k>0){
                cout << "  ";
                k--;
            }else{
                cout << num ;
                if (j!=n+i-1) cout << " ";
                if (num<i) num++;
                if (num>=i) num--;
            }
        }
        cout << endl;
    }
    return 0;
}
