// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

map <Node*,Node*> mapping;
Node *main_clone(Node *head,int* dist){
    if (head==NULL) return NULL;
    Node* new_head=new Node(0);
    new_head->data=head->data;
    new_head->arb=head->arb;
    *dist=*dist+1;
    mapping[head]=new_head;
    new_head->next=main_clone(head->next,dist);
}
void final_clone_arb(Node *new_head,int* dist,int m){
    if (m==*dist) return;
    if (new_head->arb!=NULL)
        new_head->arb=mapping[new_head->arb];
    final_clone_arb(new_head->next,dist,m+1);
}
void list_print(Node *head){
    if (head==NULL) return;
    dbg(head->data);
    if (head->next!=NULL) dbg2("  ",head->next->data);
    if (head->arb!=NULL) dbg2("    ",head->arb->data);
    list_print(head->next);
}
Node *copyList(Node *head) {
    // Your code here
    int* dist=new int;
    Node* new_head=new Node(0);
    new_head=main_clone(head,dist);
    final_clone_arb(new_head,dist,0);
    return new_head;
}

int main() {


	return 0;
}















