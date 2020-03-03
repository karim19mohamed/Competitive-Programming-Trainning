#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <map>
#include <queue>

using namespace std;
string s;
int n,m,a,ans_max,ans_min;
priority_queue <int> q_max,q_min;

int main()
{
    scanf("%d %d",&n,&m);
    for (int i=0;i<m;++i){
        scanf("%d",&a);
        q_max.push(a);
        q_min.push(-a);
    }
    for (int i=0;i<n;++i){
        ans_max+=q_max.top();
        a=q_max.top()-1;
        q_max.pop();
        if (a!=0) q_max.push(a);

        ans_min-=q_min.top();
        a=q_min.top()+1;
        q_min.pop();
        if (a!=0) q_min.push(a);
    }
    printf("%d %d\n",ans_max,ans_min);
    return 0;
}
