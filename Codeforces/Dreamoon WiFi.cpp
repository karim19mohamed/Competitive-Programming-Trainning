#include <iostream>
#include <stdio.h>
#include <string>
#include <bitset>

using namespace std;
string s1,s2;
int num,sum1,sum2,rem;
double r;
double f=1;
double ans;

int main()
{
    cin >> s1 >> s2;
    for (int i=0;i<s1.size();i++){
        if (s1[i]=='+') sum1++;
        else sum1--;
        if (s2[i]=='+') sum2++;
        else if (s2[i]=='-') sum2--;
        else num--;
    }
    if (num!=0){
        bitset <20> x;
        int q=0;
        for (int i=0;i<-1*num;i++) f*=2;
        for (int i=0;i<f;i++){
            x=q;
            int k=0;
            for (int j=0;j<-1*num;j++){
                if (x[j]==0) k--;
                else k++;
            }
            if (sum1==sum2+k) r++;
            q=q+1;
        }
        ans=(r/f);
        printf("%.10g\n", ans);   // prints 9.000023
    }else{
        if (sum1==sum2) cout << "1" << endl;
        else cout << "0" << endl;
    }
    return 0;
}
