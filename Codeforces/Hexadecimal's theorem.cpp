#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <map>

using namespace std;
long long n,a0=0,a1=1,a=1,b=2,c=3,res,ans1,ans2,ans3;

int main()
{
    scanf("%lld",&n);
    if (n==0) printf("0 0 0\n");
    else if (n==1) printf("1 0 0\n");
    else if (n==2) printf("1 1 0\n");
    else if (n==3) printf("1 1 1\n");
    else{
        while (c!=n){
            a0=a1;
            a1=a;
            a=b;
            b=c;
            c=a+b;
            //cout << a0 << "  " << a1 << endl;
        }
        printf("%lld %lld %lld\n",a0,a1,b);
    }

    return 0;
}
