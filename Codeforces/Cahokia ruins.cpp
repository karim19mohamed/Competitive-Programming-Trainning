#include <iostream>
#include <cmath>

using namespace std;
int h,w;

int main()
{
    cin >> h >> w;
    double east[h];
    double west[h];
    double space[h];
    double time=100000;
    for (int i=0;i<h;i++){
        cin >> east[i];
    }
    for (int i=0;i<h;i++){
        cin >> west[i];
    }
    for (int i=0;i<h;i++){
        space[i]=(double)(w)-east[i]-west[i];
        time=min(time,space[i]);
    }
    cout << time/2 << endl;
    return 0;
}
