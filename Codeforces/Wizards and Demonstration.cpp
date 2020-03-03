#include <iostream>
#include <cmath>

using namespace std;
int n,x,y;

int main()
{
    cin >> n >> x >> y;
    int k=ceil((double)(n)*(double)(y)/100);
    //cout << k << endl;
    if (k-x>=0) cout << k-x <<endl;
    else cout << "0" << endl;
    return 0;
}
