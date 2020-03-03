#include <iostream>

using namespace std;
int n;
int f,e;

int main()
{
    cin >> n;
    e=n*n;
    f=1;
    for (int i=0;i<n;i++){
        for (int j=0;j<n/2;j++){
            cout << f << " ";
            f++;
        }
        for (int j=0;j<n/2;j++){
            cout << e ;
            if (j!=n/2) cout << " ";
            e--;
        }
        cout << endl;
    }
    return 0;
}
