#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
string a,b;
long long oa,za,ob,zb;
long long ans;

int main()
{
    cin >> a >> b;
    if (b.size()>2*(a.size())){
        for (int i=0;i<a.size();++i) ((a[i]=='0')? za++ : oa++) ;
        for (int i=a.size()-1;i<b.size()-a.size()+1;++i) ((b[i]=='0')? zb++ : ob++) ;
        ans=oa*zb+ob*za;
        oa=zb=ob=za=0;
        for (int i=0;i<a.size()-1;++i) ((b[i]=='0')? zb++ : ob++) ;
        for (int i=0;i<a.size()-1;++i){
            ((a[i]=='0')? ans+=ob : ans+=zb) ;
            ((b[i]=='0')? zb-- : ob--) ;
        }
        oa=zb=ob=za=0;
        for (int i=1;i<a.size();++i) ((a[i]=='0')? za++ : oa++) ;
        for (int i=b.size()-a.size()+1;i<b.size();++i){
            ((b[i]=='0')? ans+=oa : ans+=za) ;
            ((a[i]=='0')? za-- : oa--) ;
        }
    }else{
        for (int i=0;i<b.size();++i){
            if (i+a.size()>b.size()) break;
            for (int j=0;j<a.size();++j){
                if (a[j]!=b[i+j]) ans++;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
