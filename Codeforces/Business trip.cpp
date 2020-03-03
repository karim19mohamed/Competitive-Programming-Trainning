#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <map>
#include <queue>

using namespace std;
int k,a,ans;
priority_queue <int> q;

int main()
{
    scanf("%d",&k);
    for (int i=0;i<12;++i){
        scanf("%d",&a);
        q.push(a);
    }
    //cout << "dasda" << endl;
    while(k>0  && !q.empty()){
        k-=q.top();
        ++ans;
        q.pop();
    }
    (k<=0) ? printf("%d\n",ans) : printf("-1\n") ;
    return 0;
}
