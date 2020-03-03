#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>

using namespace std;
long long n,a,b;
stack <long long> q;
stack <long long> ans;

int main()
{
    scanf("%lld",&n);
    for (int i=0;i<n;i++){
        q.push(1);
        while (q.size()!=1){
            a=q.top(); q.pop();
            b=q.top(); q.pop();
            if (a==b){
                q.push(a+1);
            }else{
                q.push(b);q.push(a);
                break;
            }
        }
    }
    while (!q.empty()){
        a=q.top(); q.pop();
        ans.push(a);
    }
    while (!ans.empty()){
        a=ans.top();
        ans.pop();
        printf("%lld",a);
        if (ans.size()!=0) printf(" ");
    }
    printf("\n");
    return 0;
}