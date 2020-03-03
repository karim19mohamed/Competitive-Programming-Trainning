#include <iostream>
#include <stdio.h>

using namespace std;
int vp,vd,t,f,c;
int dp,dd,ans;

int main()
{
    scanf("%d%d%d%d%d",&vp,&vd,&t,&f,&c);
    dd=-1*vd*t;
    while (dp<c){
        dp+=vp;
        dd+=vd;
        if (dd>=dp && dp<c){

            dd=dd-2*dd-vd*f;
            ans++;
        }
        cout << dp<< endl;
    }
    printf("%d\n",ans);
    return 0;
}
