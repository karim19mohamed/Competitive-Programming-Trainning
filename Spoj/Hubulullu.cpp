#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
long long n,t;
int z;

int main()
{
    scanf("%lld",&t);
    while (t--){
        scanf("%lld%d",&n,&z);
        if (z==0) printf("Airborne wins.\n");
        else printf("Pagfloyd wins.\n");
    }
    return 0;
}
