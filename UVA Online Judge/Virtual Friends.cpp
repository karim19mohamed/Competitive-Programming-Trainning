#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <stdio.h>

using namespace std;
long long t,F,ii=1,p[100009],ran[100009],ans[100009],res;
string a,b;
map <string,long long> arr;

void unionFind(long long N){
    for (long long i=0;i<N;i++){
        p[i]=i;ran[i]=0;ans[i]=1;
    }
    arr.erase(arr.begin(),arr.end());
    ii=1;
}
long long findSet(long long i){
    return (p[i]==i)? i : p[i]=findSet(p[i]);
}
bool isSameSet(long long i,long long j){
    return findSet(i)==findSet(j);
}
void unionSet (long long i,long long j){
    long long a=p[i],b=p[j];
    if (ran[a]>ran[b]){
        p[b]=a;ans[a]+=ans[b];res=ans[a];
    }else{
        p[a]=b;ans[b]+=ans[a];res=ans[b];
        if (ran[a]==ran[b]) ran[b]++;
    }
}

int main()
{
    scanf("%lld",&t);
    for (long long i=0;i<t;i++){
        scanf("%lld",&F);
        unionFind(100000);
        for (long long j=0;j<F;j++){
            cin >> a >> b;
            if (arr[a]==0){
                arr[a]=ii;
                ii++;
            }
            if (arr[b]==0){
                arr[b]=ii;
                ii++;
            }
            //cout << a << " " << b << endl;
            if (!isSameSet(arr[a],arr[b])){
                unionSet (arr[a],arr[b]);
            }else if (isSameSet(arr[a],arr[b])){
                res=ans[findSet(arr[a])];
            }
            printf("%lld\n",res);
        }
    }
    return 0;
}
