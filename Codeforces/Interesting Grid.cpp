#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;
int t,r,c,arr[509][509],ans,indx;
int aa,bb,cc;
vector <pair<pair<int,int>,int> > q;

int main()
{
    //freopen("interesting.in", "r", stdin);
    for (int i=0;i<509*509;i++){
        q.push_back({{0,0},0});
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&r,&c);
        indx=0;bb=0;aa=0;cc=0;
        for (int i=0;i<r;i++){
            for (int j=0;j<c;j++){
                scanf("%d",&arr[i][j]);
                if (arr[i][j]!=0){
                    q[indx++]={{i,j},arr[i][j]};
                    aa=max(aa,i);bb=max(bb,j);cc=max(cc,arr[i][j]);
                }
            }
        }
        cout << aa << "  " << bb << "  " << cc << endl;
        ans=r*c;
        for (int i=0;i<r;i++){
            for (int j=0;j<c;j++){
                if (arr[i][j]!=0){
                    ans--;
                    continue;
                }else{
                    bool w=1;
                    if (i+j<=cc+aa+bb || i-j<=cc+aa+bb || -i-j<=cc+aa+bb || j-i<=cc+aa+bb){
                        w=0;
                    }
                    /*for (int k=0;k<indx;k++){
                        int a=q[k].first.first,b=q[k].first.second,c=q[k].second;
                        if (abs(a-i)+abs(b-j)<=c){
                            w=0;
                            break;
                        }
                    }*/
                    if (w==0) ans--;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
