#include <iostream>
#include <stdio.h>
#include <queue>
#include <cmath>

using namespace std;
int n;
long long xa,ya,xb,yb,xf[2009],yf[2009],ans;
long long da,db,ra,rb,res;
priority_queue <pair<long long,int> > q;

int main()
{
    scanf("%d%lld%lld%lld%lld",&n,&xa,&ya,&xb,&yb);
    xa+=10000009;ya+=10000009;xb+=10000009;yb+=10000009;
    for (int i=0;i<n;i++){
        scanf("%lld%lld",&xf[i],&yf[i]);
        xf[i]+=10000009;yf[i]+=10000009;
        da=(xa-xf[i])*(xa-xf[i])+(ya-yf[i])*(ya-yf[i]);
        ra=max(ra,da);
        q.push({da,i});
    }
    res=ra;
    while (!q.empty()){

        int z=q.top().second;
        q.pop();
        if (q.size()!=0){
            long long dd=q.top().first;
            ra=dd;
        }else{
            ra=0;
        }
        db=(xb-xf[z])*(xb-xf[z])+(yb-yf[z])*(yb-yf[z]);
        rb=max(rb,db);
        //cout << ra << "  " << rb << endl;
        res=min(res,ra+rb);
    }
    ans=res;
    printf("%lld\n",ans);
    return 0;
}