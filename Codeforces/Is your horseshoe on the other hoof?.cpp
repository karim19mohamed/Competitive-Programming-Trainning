#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <map>

using namespace std;
long long int s;
map<long long int,bool> arr;
int ans;

int main()
{
    for (int i=0;i<4;++i){
        scanf("%lld",&s);
        if (arr[s]) ++ans;
        else arr[s]=1;
    }
    printf("%d\n",ans);
    return 0;
}

