#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;
int n,k,a[109],ans;
priority_queue <pair<int,int> > q;
queue <int> qu;

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        q.push({-a[i],i+1});
    }
    while (!q.empty()){
        int x=-q.top().first,y=q.top().second;
        q.pop();
        if (k-x>=0){
            k-=x;
            ans++;
            qu.push(y);
        }else{
            break;
        }
    }
    printf("%d\n",ans);
    bool z=0;
    while (!qu.empty()){
        z=1;
        int x=qu.front();
        qu.pop();
        printf("%d",x);
        if (qu.size()!=0) printf(" ");
    }
    if (z) printf("\n");
    return 0;
}