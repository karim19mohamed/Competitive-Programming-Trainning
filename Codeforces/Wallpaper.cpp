#include <iostream>
#include <stdio.h>
#include <queue>
#include <cmath>

using namespace std;
int n,m,room[509][3],paper[509][4],minindx;
priority_queue <pair<int,int> > q;
long long ans;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        for (int j=0;j<3;j++){
            scanf("%d",&room[i][j]);
        }
            q.push({(room[i][0]+room[i][1])*2,room[i][2]});
    }
    scanf("%d",&m);
    for (int i=0;i<m;i++){
        for (int j=0;j<3;j++) scanf("%d",&paper[i][j]);
    }
    while (!q.empty()){
        int area=q.top().first,z=q.top().second;
        int a=0,r=0,num=0;long long c=99999999999;
        for (int i=0;i<m;i++){
            int b=area;
            a=0;r=0;num=0;
                num=paper[i][0]/z;
                if (num==0) continue;
                num*=paper[i][1];
                a=ceil((double)((double)(b)/(double)(num)));
            if (c>a*paper[i][2]){
                c=a*paper[i][2];
                minindx=i;

            }
        }
        cout << c << endl;
        ans+=c;
        paper[minindx][3]=1;
        q.pop();
    }
    printf("%lld\n",ans);
    return 0;
}
