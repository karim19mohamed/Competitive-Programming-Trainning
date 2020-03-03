#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <map>
#include <cmath>

using namespace std;
int n,c_int,c,ans;
map <pair<int,int>,bool> m;

int main()
{
    scanf("%lld",&n);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            c = i*i + j*j;
            c_int=sqrt(c);
            if (c_int*c_int==i*i+j*j && !m[make_pair(i,j)] && c_int<=n){
                ++ans;
                m[make_pair(i,j)]=m[make_pair(j,i)]=1;
                //cout << i << " " << j << "  " << c_int << endl;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
