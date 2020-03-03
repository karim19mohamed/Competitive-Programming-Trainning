#include <iostream>
#include <stdio.h>

using namespace std;
int L1[10005];
int L2[10005];
int ans[20005];
int multi(int indx_1,int indx_2,int x);

int main()
{
    int n;
    char y=0;
    scanf("%d",&n);
    scanf("%c",&y);
    for (int i=0;i<n;i++){
        char x;
        int ind=0;
        int indx_1=0;
        int indx_2=0;
        int k=indx_1+indx_2-2;
        while(1){
            scanf("%c",&x);
            if (x=='\n'){
                if (ind==1){
                    break;
                }else{
                    x=' ';
                }
            }
            if (x==' ') {
                ind=1;
                continue;
            }
            if(ind==0){
                L1[indx_1]=x-'0';
                indx_1++;
            }else{
                L2[indx_2]=x-'0';
                indx_2++;
            }
        }
        //cout << indx_1 << "  " << indx_2 << endl;
        int zero_ind=1;
        for (int i=k;i>=0;i--){
            multi(i,0,i);
            if (ans[i]!=0) zero_ind=0;
            if(i==0) continue;
            if (ans[i]/10){
                ans[i-1]=ans[i-1]+ans[i]/10;
                ans[i]=ans[i]-(ans[i]/10)*10;
            }
            //cout << ans[i]<<endl;
            //ans[i]=0;
        }
        //cout << ans[0]<<endl;
        //ans[indx_1+indx_2-2]=0;
        for(int i=0;i<=k;i++){
            if (zero_ind==1){
                printf ("%d",zero_ind-1);
                zero_ind=zero_ind+5;
            }else if (zero_ind==0){
                printf ("%d",ans[i]);
            }
            ans[i]=0;
            L1[i]=0;
            L2[i]=0;
        }
        printf("\n");
    }
    return 0;
}

int multi(int indx_1,int indx_2,int x){
    if (indx_1==-1) return 0;

    //cout << L1[indx_1] << "  " << L2[indx_2] <<endl;

    ans[x]=ans[x]+L1[indx_1]*L2[indx_2];
    multi(indx_1-1,indx_2+1,x);
    //cout << "    " << ans[x] << endl;
}
