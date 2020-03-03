#include <iostream>
#include <cmath>

using namespace std;
int x[4];
int y[4];
int k;

int main()
{
    cin >> x[0] >> y[0] >> x[1] >> y[1];
    if (x[0]==x[1]){
        k=y[1]-y[0];
        cout << x[0]+k << " " << y[0] << " " << x[1]+k << " " << y[1] << endl;
    }else if (y[0]==y[1]){
        k=x[1]-x[0];
        cout << x[0] << " " << y[0]+k << " " << x[1] << " " << y[1]+k << endl;
    }else{
        if (abs(x[1]-x[0])==abs(y[1]-y[0])){
            k=x[1]-x[0];
            cout << x[1] << " " << y[0] << " " << x[0] << " " << y[1] << endl;
        }else{
            cout << "-1" << endl;
        }
    }
    return 0;
}
