#include<bits/stdc++.h>
using namespace std;
class node{
        public:
        int data;
        node *next;
        node(int val){
            data=val;
            next=NULL;
        }
};
class Stack{
    node* top;
    public:
    Stack(){
        top=NULL;
    }
    void push(int data){
        node* temp=new node(data);
        if(!temp){
            cout<<"Stack overflow\n";
            exit(1);
        }
        temp->data=data;
        temp->next=top;
        top=temp;
    }
    bool empty(){
        return top==NULL;
    }
    int peek(){
        if(!empty()){
            return top->data;
        }
        else{
            exit(1);
        }
    }
    void pop(){
        node* temp;
        if(top==NULL){
            cout<<"Stack underfollow\n";
            exit(1);
        }
        else{
            temp=top;
            top=top->next;
            free(temp);
        }
    }
    void prints(){
        node* temp;
        if(top==NULL){
            cout<<"Stack underfollow\n";
        }
        else{
            temp=top;
            while(temp!=NULL){
                cout<<temp->data;
                temp=temp->next;
                if(temp!=NULL){
                    cout<<"->";
                }
            }
        }
        cout<<endl;
    }
};
int main(){
    Stack s;
    char a;
    while(scanf("%c",&a)!=EOF){
        if(a=='(' || a=='{' || a=='['){
            s.push(a);
        }
       if(s.empty()){
        cout<<"imbalance\n";
        return 0;
       }
        else{
        if(a==')' && s.peek()=='('){
            s.pop();
        }
        if(a=='}' && s.peek()=='{'){
            s.pop();
        }
        if(a==']' && s.peek()=='['){
            s.pop();
        }
        }
        
        
    }
    if(!s.empty()){
        cout<<"imbalance\n";
    }
    else{
        cout<<"balance\n";
    }
    
   return 0;
}