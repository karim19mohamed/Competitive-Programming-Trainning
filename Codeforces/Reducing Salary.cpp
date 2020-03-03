#include <iostream>

using namespace std;
long long y,x,a,sum;
double b=1;
double c=10;
void che(long long u);
bool ans=0;

int main()
{
    cin >> y;
    a=y/10;

    while (a!=0){
        a/=10;
        b+=(1/c);
        c*=10;
    }
    x=( double)(( double)(y)/( double)(b));
    che(x);
    x=x+(y-sum);

    sum=0;
    che(x);
    if (ans==0){
        if (sum==y) cout << x << endl;
        else cout << "-1" << endl;
    }else{
        cout << "ManySolutions" << endl;
    }

    return 0;
}
void che(long long u){
    sum+=u;
    if (u!=0) che(u/10);
}
