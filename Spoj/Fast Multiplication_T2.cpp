#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cmath>

using namespace std;
int L1[20005];
int L2[20005];
int ans[40005];
//int multi(int indx_1,int indx_2,int x);

int main()
{
    int n;
    char y=0;
    scanf("%d",&n);
    char num_1[20005];
    char num_2[20005];
    for (int j=0;j<n;j++){
        scanf("%s" ,&num_1[0]);
        scanf("%s" ,&num_2[0]);
        //cout << num_1[0] << endl;
        int indx_1=strlen(num_1);
        int indx_2=strlen(num_2);
        //cout << indx_1 << "  " << indx_2 << endl;
        int zero_ind=1;
        int k=indx_1+indx_2-2;
        for (int i=k;i>=0;i--){
            int inx_1=i;
            int inx_2=0;
            while (inx_1!=-1){
                //cout << L1[inx_1] << "    " << L2[inx_2] << endl;
                ans[i]=ans[i]+(max(num_1[inx_1]-'0',0))*(max(num_2[inx_2]-'0',0));
                //cout << ans[i] << endl;
                inx_1=inx_1-1;
                inx_2=inx_2+1;
            }
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
            num_1[i]=0;
            num_2[i]=0;
        }
        printf("\n");
    }
    return 0;
}
/*
int multi(int indx_1,int indx_2,int x){
    if (indx_1==-1) return 0;

    //cout << L1[indx_1] << "  " << L2[indx_2] <<endl;

    ans[x]=ans[x]+L1[indx_1]*L2[indx_2];
    multi(indx_1-1,indx_2+1,x);
    //cout << "    " << ans[x] << endl;
}
*/
