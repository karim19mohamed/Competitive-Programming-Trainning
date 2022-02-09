#include <bits/stdc++.h>
using namespace std;
class Node{
private:
    int value;
    Node *Next;
public:
    Node(){
        value=0;
        Next=NULL;
    }
    Node(int val){
        value=val;
        Next=NULL;
    }
    void set_val(int val){
        value = val;
    }
    int get_val(){
        return value;
    }
    void set_next(Node *next){
        Next = next;
    }
    Node* get_next(){
        return Next;
    }
};
class linked_list{
private:
    Node *Start,*Last;
    int Size;
    Node* getNode(int idx){
        assert(idx<Size && idx>=0);
        Node *temp=Start;
        for(int c=0;c<idx;c++){
            temp = temp->get_next();
        }
        return temp;
    }
public:
    linked_list(){
        Start=Last=NULL;
        Size=0;
    }
    linked_list(int _size){
        Start=Last=NULL;//
        Size=0;
        for(int i=0;i<_size;i++)
            Add();
    }
    void Add(int val=0){
        Node *newNode = new Node(val);
        if(Size==0){
            Start=Last=newNode;
        }else{
            Last->set_next(newNode);
            Last = newNode;
        }
        Size++;
    }
    int get_idx(int idx){
        if(idx==0)
            return Start->get_val();
        else if(idx==Size-1)
            return Last->get_val();
        Node *temp=getNode(idx);
        return temp->get_val();
    }
    int get_size(){
        return Size;
    }
    void Set(int idx,int val){
        Node *temp=getNode(idx);
        temp->set_val(val);
    }
    void Insert(int idx,int val){
        assert(idx<=Size && idx>=0);
        Node *temp=NULL,*newNode=new Node(val);
        if(idx==0){
            newNode->set_next(Start);
            Start = newNode;
            if(Size==0)
                Last = Start;
        }else if(idx==Size){
            Last->set_next(newNode);
            Last = newNode;
        }else{
            temp = getNode(idx-1);
            newNode->set_next(temp->get_next());
            temp->set_next(newNode);
        }
        Size++;
    }
    void Erase(int idx){
        assert(idx<Size && idx>=0);
        Node *temp=NULL,*badNode=NULL;
        if(idx==0){
            badNode = Start;
            Start = Start->get_next();
            if(Size==1)
                Last=Start=NULL;
        }
        else if(idx==Size-1){
            badNode = Last;
            Last = getNode(idx-1);
            Last->set_next(NULL);
        }
        else{
            temp = getNode(idx-1);
            badNode = temp->get_next();
            temp->set_next(badNode->get_next());
        }
        Size--;
        delete badNode;
    }
};
class Stack{
private:
    linked_list L;
public:
    int get_size(){
        return L.get_size();
    }
    void Push(int val){
        L.Insert(L.get_size(),val);
    }
    void Pop(){
        L.Erase(L.get_size()-1);
    }
    int Top(){
        return L.get_idx(L.get_size()-1);
    }
};
class Queue{
private:
    linked_list L;
public:
    int get_size(){
        return L.get_size();
    }
    void Push(int val){
        L.Insert(L.get_size(),val);
    }
    void Pop(){
        L.Erase(0);
    }
    int Front(){
        return L.get_idx(0);
    }
};
class De_queue{
private:
    linked_list L;
public:
    int get_size(){
        return L.get_size();
    }
    void Push_front(int val){
        L.Insert(0,val);
    }
    void Push_back(int val){
        L.Insert(L.get_size(),val);
    }
    void Pop_front(){
        L.Erase(0);
    }
    void Pop_back(){
        L.Erase(L.get_size()-1);
    }
    int Front(){
        return L.get_idx(0);
    }
    int Back(){
        return L.get_idx(L.get_size()-1);
    }
};
int main()
{
    linked_list L(5);
    L.Insert(3,4);
    L.Erase(2);
    L.Add(12);
    for(int i=0;i<L.get_size();i++)
        cout<<L.get_idx(i)<<" ";
}
