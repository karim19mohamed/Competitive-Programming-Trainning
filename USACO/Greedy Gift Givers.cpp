/*
ID: s-karim1
PROG: gift1
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
//vector <int> give[2005];
int NP;
int gain[15];

int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    fin >> NP;
    string frend[NP];
    int money[NP];
    for (int i=0;i<NP;i++){
        fin >> frend[i];
    }
    for (int i=0;i<NP;i++){
        string x;
        fin >> x;
        int num=0;
        int no_frend=0;
        for (int j=0;j<NP;j++){
            if (x.compare(frend[j])==0){
                num=j;
                break;
            }
        }
        fin >> money[num] >> no_frend;
        string y;
        if (no_frend==0){
            gain[num]+=money[num];
            continue;
        }
        int dis=floor((float)(money[num])/(float)(no_frend));
        gain[num]+=money[num]-dis*no_frend;
        for (int j=0;j<no_frend;j++){
            fin >> y;
            for (int j=0;j<NP;j++){
                if (y.compare(frend[j])==0){
                    num=j;
                    break;
                }
            }
            gain[num]+=dis;
            //cout << num << "   " <<dis <<"   "<< gain[num] << endl;
        }
    }
    for (int i=0;i<NP;i++){
        fout << frend[i] << " " << gain[i]-money[i] << endl;
    }
    return 0;
}
