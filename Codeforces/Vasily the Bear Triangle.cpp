#include <iostream>
#include <cmath>

using namespace std;
long long x,y;
long long x_1,y_1,x_2,y_2;

int main()
{
    cin >> x >> y;

    x_1=0;
    y_1=abs(y)+abs(x);
    x_2=abs(y)+abs(x);
    y_2=0;

    if (x>=0 && y>=0) {
        cout << x_1 << " " << y_1 << " " << x_2 << " " << y_2 << endl;
    }else if (x>=0 &&y<0){
        y_1=-1*y_1;
        cout << x_1 << " " << y_1 << " " << x_2 << " " << y_2 << endl;
    }else if (x<0 &&y<0){
        x_2=-1*x_2;
        y_1=-1*y_1;
        cout << x_2 << " " << y_2 << " " << x_1 << " " << y_1 << endl;
    }else{
        x_2=-1*x_2;
        cout << x_2 << " " << y_2 << " " << x_1 << " " << y_1 << endl;
    }
    return 0;
}
