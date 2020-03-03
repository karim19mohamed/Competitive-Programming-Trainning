#include <iostream>
#include <stdio.h>

using namespace std;
int n,ans;
char arr[109][109];

int main()
{
    cin >> n;
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) cin >> arr[i][j];
    int z=-1;
    for (int i=0;i<n;i++){
        z=0;
        for (int j=0;j<n;j++){
            if (arr[i][j]=='C') z++;
        }
        ans=ans+(z*z-z)/2;
    }
    for (int i=0;i<n;i++){
        z=0;
        for (int j=0;j<n;j++){
            if (arr[j][i]=='C') z++;
        }
        ans=ans+(z*z-z)/2;
    }
    printf("%d\n",ans);
    return 0;
}