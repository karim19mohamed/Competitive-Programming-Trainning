#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

using namespace std;
long long suma,sumb;
string s;

int main()
{
    cin >> s;
    for (long long i=0;i<s.size();i++){
        if (s[i]=='x') suma++;
        else sumb++;
    }
    bool z;
    (suma>sumb) ? z=0 : z=1;
    for (long long i=0;i<abs(suma-sumb);i++){
        if(z==0) printf("x");
        else if(z==1) printf("y");
    }
    printf("\n");
    return 0;
}
