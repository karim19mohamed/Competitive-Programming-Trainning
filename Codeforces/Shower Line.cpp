#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
long long b[5][5],ans;
int a[5]={0,1,2,3,4};

int main()
{
    for (int i=0;i<5;++i){
        for (int j=0;j<5;++j){
            scanf("%lld",&b[i][j]);
        }
    }
    do{
        long long x;
        x =b[a[0]][a[1]]+b[a[1]][a[0]] + 2*b[a[2]][a[3]]+2*b[a[3]][a[2]];
        x+=b[a[1]][a[2]]+b[a[2]][a[1]] + 2*b[a[3]][a[4]]+2*b[a[4]][a[3]];
        ans=max(ans,x);
    }while(next_permutation(a,a+5));
    printf("%lld\n",ans);
    return 0;
}
