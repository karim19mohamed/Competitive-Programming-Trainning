#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>

using namespace std;
int n,l,r,lo,lz,ro,rz;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%d %d",&l,&r);
        (l)? ++lo : ++lz;
        (r)? ++ro : ++rz;
    }
    printf("%d\n" , min(lo,lz)+min(ro,rz));
    return 0;
}

