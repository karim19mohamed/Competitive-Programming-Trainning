#include <iostream>
#include <string>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;

using namespace std;
long long arr[109];
int i_max,j_max,s_i;
int f_neg=-1;
int e_neg=-1;
long long sum_1,sum_2,tot_sum,ans,no_neg,no_zero,no_pos;
string res;
int last_indx;
long long small_ans=1;
void arrange(long long r,long long k);
mp::cpp_int S("1");

int main()
{
    int ind=0;
    while (1){
        cin >> arr[ind];
        if (arr[ind]==-999999) break;

        tot_sum+=abs(arr[ind]);
        if (arr[ind]<0) no_neg++;
        if (arr[ind]>0) no_pos++;
        if (f_neg==-1) sum_1+=abs(arr[ind]);
        if (e_neg!=-1) sum_2+=abs(arr[ind]);
        if (arr[ind]<0 && f_neg==-1) f_neg=ind;
        if (arr[ind]<0 && f_neg!=-1){
            e_neg=ind;
            sum_2=abs(arr[ind]);
        }
        if (arr[ind]==0){
            no_zero++;
            if (no_neg%2==0){
                if (ans<tot_sum){
                    ans=tot_sum;
                    i_max=s_i;
                    j_max=ind-1;
                }
            }else{
                if (ans<tot_sum-sum_1){
                    ans=tot_sum-sum_1;
                    i_max=f_neg+1;
                    j_max=ind-1;
                }else if (ans<tot_sum-sum_2){
                    ans=tot_sum-sum_2;
                    i_max=s_i;
                    j_max=e_neg-1;
                }
            }
            s_i=ind+1;
            tot_sum=0;
            sum_1=0;
            sum_2=0;
            f_neg=-1;
            e_neg=-1;
        }

        ind++;
    }
    if (no_zero==0){
        if (no_neg%2==0){
            if (ans<tot_sum){
                ans=tot_sum;
                i_max=s_i;
                j_max=ind-1;
            }
        }else{
            if (ans<tot_sum-sum_1){
                ans=tot_sum-sum_1;
                i_max=f_neg+1;
                j_max=ind-1;
            }else if (ans<tot_sum-sum_2){
                ans=tot_sum-sum_2;
                i_max=s_i;
                j_max=e_neg-1;
            }
        }
    }
    //cout << f_neg << "  " << e_neg << "  " << tot_sum << "  " << i_max << "  " << j_max << endl;
    if (no_pos!=0){

        for (int i=i_max;i<=j_max;i++){
            std::string s = to_string(abs(arr[i]));
            mp::cpp_int s1(s);
            S=S*s1;
        }
        cout << S << endl;
    }else if (no_zero!=0){
        cout << "0" << endl;
    }else{
        cout << arr[i_max] << endl;
    }
    return 0;
}

void arrange(long long r,long long k){
    int remender=0;
    last_indx=0;
    while (1){
        k=k/10;
        int qqq=small_ans-k*r*10;
        res[last_indx]=res[last_indx]+(qqq/r)+remender;
        remender=0;
        if (res[last_indx]>9){
            remender=res[last_indx]/10;
            res[last_indx]=res[last_indx]-remender*10;
        }
        //cout << res[last_indx] << "  ";
        last_indx++;
        r*=10;
        if (k==0) break;
    }
}

