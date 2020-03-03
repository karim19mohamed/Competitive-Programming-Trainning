#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;
long long x,y,m,ans,pa,pb;
long double c,a,b;

int main()
{
    cin >> x >> y >> m;
    if (x>=m || y>=m){
        ans=0;
    }else if (x<=0 && y<=0 && (m>x && m>y) ){
        ans=-1;
    }else if (x>=0 && y>=0 && (m<x && m<y) ){
        ans=-1;
    }else if (m>0){
        if (x<0 || y<0){
            a=min(x,y);
            b=max(x,y);
            c=ceil((b+abs(a)-1)/b);
            ans+=c;
            if (x<0) x=x+c*b;
            else y=y+c*b;
        }
    }else if (m<0){
        if (x>0 || y>0){
            a=min(x,y);
            b=max(x,y);
            c=ceil((b+abs(a))/abs(a));
            ans+=c;
            if (x>0) x=x-c*abs(a);
            else y=y-c*abs(a);
        }
    }
    if (ans!=-1){
        if (x>=0 && y>=0){
            while (x<m && y<m){
                pa=x+y;
                if (x>y) y=pa;
                else x=pa;
                ans++;
            }
        }/*else if (x<=0 && y<=0){
            while (x<m && y<m){
                pa=x+y;
                if (x<y) y=pa;
                else x=pa;
                ans++;
            }
        }*/
    }
    cout << ans << endl;
    return 0;
}