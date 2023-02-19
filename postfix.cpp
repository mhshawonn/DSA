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
        n=c-'0';
        return n;
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
    int prec(char c) {
        if(c=='^'){
            return 3;
        }
        else if(c=='/' || c=='*'){
            return 2;
        }
        else if(c=='+' || c=='-'){
            return 1;
        }
        return -1;
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
       string infinixtopostfix(string s){
        Stack st;
        string result;
        for(int i=0;i<s.size();i++){
        char c=s[i];
        if(c>='a' && c<='z' || c>='A' && c<='Z' || c>='0' && c<='9'){
                result+=c;
        }
        else if(c=='(' ){
            st.push('(');
        }
        else if(c=='{'){
            st.push('{');
        }
        else if(c=='['){
            st.push('[');
        }
        else if(c==')'){
            while(st.peek()!='('){
                result+=st.peek();
                st.pop();
            }
            st.pop();
        }
        else if(c=='}'){
            while(st.peek()!='{'){
                result+=st.peek();
                st.pop();
            }
            st.pop();
        }
        else if(c==']'){
            while(st.peek()!='['){
                result+=st.peek();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && prec(s[i]) <= prec(st.peek())){
                result+=st.peek();
                st.pop();
            }
            st.push(c);
        }
        
        }
        return result;
    }
int main(){
    string s;
    cin>>s;
    
    string ss;
    ss=infinixtopostfix(s);
    cout<<postfix(ss);
    
    
    
   return 0;
}