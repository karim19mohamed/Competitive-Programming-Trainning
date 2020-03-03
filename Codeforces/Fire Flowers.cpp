#include <iostream>
#include <cmath>

using namespace std;
long long t;
long double r,x,y,r_req,x_req,y_req,dis;

int main()
{
    cin >> t ;
    for (long long i=0;i<t;i++){
        cin >> r >> x >> y >> r_req >> x_req >> y_req;
        dis=sqrt( (x-x_req)*(x-x_req) + (y-y_req)*(y-y_req) );
        dis+=r_req;
        if (r>=dis) cout << "Rich" << endl;
        else cout << "Dead" << endl;
    }
    return 0;
}
