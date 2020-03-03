#include <iostream>
#include <stdio.h>
#include <cmath>
#include <queue>

using namespace std;
long long n,a,b,c,m;
long double d,db,dc,arr[100009][2],si,sj;
priority_queue <pair<long double,long long> > q;

int main()
{
    scanf ("%lld",&n);
    for (long long i=0;i<n;i++){
        scanf ("%llf%llf",&arr[i][0],&arr[i][1]);
        arr[i][0]+=1000000009;
        arr[i][1]+=1000000009;
        d=sqrt(arr[i][0]*arr[i][0]+arr[i][1]*arr[i][1]);
        if (d>c){
            c=d;
            a=i;
        }
    }
    for (long long i=0;i<n;i++){
        if (i==a) continue;
        d=sqrt( (arr[a][0]-arr[i][0])*(arr[a][0]-arr[i][0])+(arr[a][1]-arr[i][1])*(arr[a][1]-arr[i][1]) );
        q.push({-d,i});
    }
    while (!q.empty()){
        b=q.top().second;
        db=-q.top().first;
        q.pop();
        c=q.top().second;
        dc=-q.top().first;
        q.pop();
        d=sqrt( (arr[b][0]-arr[c][0])*(arr[b][0]-arr[c][0])+(arr[b][1]-arr[c][1])*(arr[b][1]-arr[c][1]) );
        si=(arr[a][1]-arr[b][1])/(arr[a][0]-arr[b][0]);
        sj=(arr[a][1]-arr[c][1])/(arr[a][0]-arr[c][0]);
        if (db>=dc && db>=d && db<=d+dc && si!=sj) break;
        else if (dc>=db && dc>=d && dc<=d+db && si!=sj) break;
        else if (d>=db && d>=dc && d<=dc+db && si!=sj) break;
        else q.push({-db,b});
    }
    printf("%lld %lld %lld\n",a+1,b+1,c+1);
    return 0;
}