// https://practice.geeksforgeeks.org/problems/check-for-bst/1

#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

//template<struct T>;
struct Node{
	int data;
	Node* left=NULL,* right=NULL;
	bool has_children=0;
}tree[100];
int n,edge,a,b,c;

bool chk(Node* root,int mn=-1000000000,int mx=1000000000){
    if (root->data>=mx || root->data<=mn) return false;
	bool ans=true;
	if (root->right!=NULL) ans &= chk(root->right,root->data,mx);
	if (root->left!=NULL)ans &= chk(root->left,mn,root->data);
	return ans;
}
bool isBST(Node* root){
	// Your code here
	bool ans=chk(root);
	return ans;
}

void print_tree(Node tree[],int &n){
	for (int i=0;i<n;++i){
		if (!tree[i].has_children) continue;
		int data=tree[i].data;
		int left=tree[i].left->data,right=tree[i].right->data;
		dbg4(i,data,left,right);
		dbg(tree[i].has_children);
	}
}

int main() {
	scanf("%d %d",&n,&edge);
	for (int i=0;i<n;++i){
		scanf("%d",&a);
		tree[i].data=a;
	}
	for (int i=0;i<edge;++i){
		scanf("%d %d %d",&a,&b,&c);
		tree[a].left=&tree[b];
		tree[a].right=&tree[c];
		tree[a].has_children=1;
	}
	//print_tree(tree,n);
	(isBST(&tree[0]))? puts("Binary Search Tree"):puts("Not Binary Search Tree");
	return 0;
}
















