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
    int scannum(char c){
        int n;
        n=c;
        return int(n-'0');
    }
    bool isoperator(char c){
        if(c=='+' || c=='-' || c=='*' || c=='/'||c=='^'){
            return true;
            
        }
        return false;
    }
    bool operand(char ch){
        if(ch>='0' && ch<='9'){
            return true;
        }
        return false;
    }
    int operation(int a,int b,char op){
        if(op=='+'){
            return b+a;
        }
        else if(op=='-'){
            return b-a;
        }
        else if(op=='*'){
            return b*a;
        }
        else if(op=='/'){
            return b/a;
        }
        else if(op=='^'){
            return pow(a,b);
        }
        else 
        return INT_MIN;
    }

    int postfix(string post){
        Stack s;
        int a,b;
        
        for(int i=0;i<post.size();i++){
               if(isoperator(post[i])){
                 a=s.peek();
                 s.pop();
                b=s.peek();
                s.pop();
                s.push(operation(a,b,post[i]));
               }
               else if(operand(post[i])>0){
                s.push(scannum(post[i]));
               }

        }
        return s.peek();
    }
int main(){
    string s;
    cin>>s;
    cout<<postfix(s);

    
   return 0;
}