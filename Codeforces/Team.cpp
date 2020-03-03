#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <map>

using namespace std;
int n,ans,a,b,c;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%d %d %d",&a,&b,&c);
        if (a+b+c>1) ++ans;
    }
    printf("%d\n",ans);
    return 0;
}

