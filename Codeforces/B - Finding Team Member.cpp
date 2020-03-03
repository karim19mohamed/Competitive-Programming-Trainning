#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int n,indx,ans[809];
vector <pair<long long,pair<int,int> > > arr;
long long res[809*809],a,b,cnt;

int main()
{
    scanf("%d",&n);
    for (int i=2;i<=2*n;++i){
        for (int j=1;j<=i-1;++j){
            scanf("%lld",&a);
            arr.push_back({-a,{i,j}});
        }
    }
    sort(arr.begin(),arr.end());
    indx++;
    for (int i=0;i<arr.size();++i){
        //cout << arr[i].first << endl;
        if (cnt==n) break;
        if (res[arr[i].second.first]!=indx && res[arr[i].second.second]!=indx){
            res[arr[i].second.first]=res[arr[i].second.second]=indx;
            ans[arr[i].second.second]=arr[i].second.first;
            ans[arr[i].second.first]=arr[i].second.second;
            cnt++;
        }
    }
    for (int i=1;i<=2*n;++i){
        printf("%d",ans[i]);
        if (i!=2*n) printf(" ");
    }
    printf("\n");
    return 0;
}
