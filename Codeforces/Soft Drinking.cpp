#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <map>

using namespace std;
int nom, k, l, c, d, p, nl, np , ans;

int main()
{
    scanf("%d %d %d %d %d %d %d %d",&nom, &k, &l, &c, &d, &p, &nl, &np);
    ans = min(min(k*l/nl,c*d),p/np)/nom;
    printf("%d\n",ans);
    return 0;
}
