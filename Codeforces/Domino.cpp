#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <map>
#include <cmath>

using namespace std;
int n,x[109],y[109],x_sum,y_sum,ch;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%d %d",&x[i],&y[i]);
        x_sum+=x[i];
        y_sum+=y[i];
        if ( (!(x[i]%2) && y[i]%2) || (x[i]%2 && !(y[i]%2)) ) ++ch;
    }
    if (!(x_sum%2) && !(y_sum%2) ) printf("0\n");
    else if (x_sum%2 && y_sum%2 && !(ch%2) && ch!=0) printf("1\n");
    else printf("-1\n");
    return 0;
}
