#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <map>
#include <cmath>

using namespace std;
int n,m;

int main()
{
    //freopen("input.txt", "r+", stdin);
    //freopen("output.txt", "w+", stdout);
    scanf("%d %d",&n,&m);
    int k=min(n,m);
    if (n>k){
        for (int i=0;i<k;++i) printf("BG");
        for (int i=0;i<n-k;++i) printf("B");
    }else if (m>k){
        for (int i=0;i<k;++i) printf("GB");
        for (int i=0;i<m-k;++i) printf("G");
    }else{
        for (int i=0;i<k;++i) printf("BG");
    }
    printf("\n");
    return 0;
}
