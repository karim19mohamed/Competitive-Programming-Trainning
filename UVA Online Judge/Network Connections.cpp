#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
long long t,n,b,c,ansr,ansf;
char a;
long long p[100000],ran[100000];
string s;

//UnionSet
void unionFind(long long N){
    for (long long i=0;i<N;i++){
        p[i]=i;ran[i]=0;
    }
}
long long findSet(long long i){
    return (p[i]==i) ? i : p[i]=findSet(p[i]);
}
bool isSameSet(long long i,long long j){
    return findSet(i)==findSet(j);
}
void unionSet (long long i,long long j){
    long long a=p[i],b=p[j];
    if (ran[a]>ran[b]){
        p[b]=a;
    }else{
        p[a]=b;
        if (ran[a]==ran[b]) ran[b]++;
    }
}

int main()
{
    scanf("%lld",&t);
    for (long long i=0;i<t;i++){
        scanf("\n%d\n",&n);
        unionFind(n);
        while (1){
            if(!getline(cin,s) || s.empty()) break;
            sscanf(s.c_str(),"%c %lld %lld",&a,&b,&c);
            if (a=='c'){
                if (!isSameSet(b-1,c-1)) {
                    unionSet(b-1,c-1);
                }
            }else if (a=='q'){
                if (isSameSet(b-1,c-1)) ansr++;
                else ansf++;
            }
        }
        printf("%lld,%lld\n",ansr,ansf);
        if (i!=t-1) printf("\n");
        ansf=0;ansr=0;
    }
    return 0;
}
