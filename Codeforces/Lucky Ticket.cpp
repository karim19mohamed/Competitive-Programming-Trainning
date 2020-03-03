#include <iostream>
#include <stdio.h>

using namespace std;
int n,suma,sumb;
char arr[59];
bool ans=1;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf(" %c",&arr[i]);
        if (i<n/2) suma+=(arr[i]-'0');
        if (i>=n/2) sumb+=(arr[i]-'0');
        if (arr[i]!='4' && arr[i]!='7') ans=0;
    }
    if (suma!=sumb) ans=0;
    if (ans) printf("YES\n");
    else printf("NO\n");
    return 0;
}
