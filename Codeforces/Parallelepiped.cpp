#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <map>

using namespace std;
int ar,br,cr,ans;

int main()
{
    scanf("%d %d %d",&ar,&br,&cr);
    ans=4*(sqrt(ar*br/cr)+sqrt(ar*cr/br)+sqrt(cr*br/ar));
    printf("%d\n",ans);
    return 0;
}
