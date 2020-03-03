#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
#include <queue>
#include <fstream>

using namespace std;
const int N=1009;
//int ca[N]; string cb[N]; int lc;
//int ra[N]; string rb[N]; int lr;
//int sta[N]; string stb[N]; int lst;
map<string,int> coach;
map<string,string> re;
map<string,int> st;
priority_queue <pair<int,string> > ans;
int t,n,bb;
string a,b="a";
string aa;

int main()
{
    //freopen("coaches.in", "r", stdin);
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        getline(std::cin,a);
        getline(std::cin,a);
        getline(std::cin,b);
        while (n--){
            if (b=="-1") getline(std::cin,b);
            while (b[0]>'Z' || b[1]>'Z'){
                if (st[b]==0){
                    coach[a]++;
                    st[b]=1;
                    re[b]=a;
                }else if (st[b]==1){
                    if (re[b]!=a){
                        coach[re[b]]--;
                        st[b]=-1;
                    }
                }
                n--;
                if (n==0) break;
                getline(std::cin,b);
            }
            a=b;
            b="-1";
        }
        for (std::map<string,int>::iterator it=coach.begin(); it!=coach.end(); ++it){
            ans.push({it->second,it->first});
            coach.erase(it);
        }
        while (!ans.empty()){
            bb=ans.top().first;
            aa=ans.top().second;
            ans.pop();
            cout << aa << " " << bb << endl;
        }
        st.erase(st.begin(),st.end());
        re.erase(re.begin(),re.end());
    }
    return 0;
}





