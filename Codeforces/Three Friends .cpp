#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <map>
#include <queue>

using namespace std;
int q;
long long a[3],b[3],c[3],ans=100000000000;

int main()
{
    scanf("%d",&q);
    //cout << ans << endl;
    for (int i=0;i<q;++i){
        scanf("%lld %lld %lld",&a[0],&b[0],&c[0]);
        a[1]=a[0]-1; a[2]=a[0]+1;
        b[1]=b[0]-1; b[2]=b[0]+1;
        c[1]=c[0]-1; c[2]=c[0]+1;
        for (int j=0;j<3;++j){
            for (int k=0;k<3;++k){
                for (int d=0;d<3;++d){
                    long long tmp=abs(a[j]-b[k])+abs(b[k]-c[d])+abs(a[j]-c[d]);
                    if (tmp<ans){
                        ans=tmp;
                    }
                }
            }
        }
        printf("%lld\n",ans);
        ans=100000000000;
    }
    //printf("%d %d\n",ans_max,ans_min);
    return 0;
}
