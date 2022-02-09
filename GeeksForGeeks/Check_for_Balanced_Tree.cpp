// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int treeHeight(Node *root,bool* ans){
    if (root==NULL){
        return 0;
    }
    int res1=0,res2=0;
    res1=max(res1,1+treeHeight(root->left,ans));
    res2=max(res2,1+treeHeight(root->right,ans));
    if (abs(res1-res2)>1) *ans=0;
    return max(res1,res2);
}
bool isBalanced(Node *root){
    bool* ans=new bool(1);
    int tmp=treeHeight(root,ans);
    return *ans;
}

int main() {
	//code

	return 0;
}
















