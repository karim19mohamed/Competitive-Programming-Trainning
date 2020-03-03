/*
ID: s-karim1
PROG: friday
LANG: C++14
*/
#include <iostream>
#include <fstream>

using namespace std;
int n;
int ans[7];
int no_days,no_months,no_years;
int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    fin >> n ;
    int indx=3;
    int i=0;
    while (1900+n != 1900+i){
        if((1900+i)%100==0){
            if ((1900+i)%400==0) days[1]=29;
        }else if ((1900+i)%4==0){
            days[1]=29;
        }
        for (int j=0;j<12;j++){
            int t=indx-2;
            while (t<=0) t+=7;
            ans[t-1]+=1;
            t=days[j];
            while (t>7) t-=7;
            indx+=t;
            while (indx>7) indx-=7;
        }
        days[1]=28;
        i=i+1;
    }
    for (int i=0;i<7;i++){
        fout << ans[i];
        if (i!=6) fout << " ";
    }
    fout << endl;
    return 0;
}
