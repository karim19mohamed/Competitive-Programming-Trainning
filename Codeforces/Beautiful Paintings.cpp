#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>

using namespace std;
int n,arr[1009],ans;
int x[1009];
queue <int> q;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        x[i]=arr[i];
    }
    sort(arr,arr+n);
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (arr[i]<arr[j] && x[j]!=-1){
                ans++;
                x[j]=-1;
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
