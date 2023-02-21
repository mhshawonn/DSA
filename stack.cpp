#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int> sym={{'[',-1},{'{',-2},{'(',-3},{']',1},{'}',2},{')',3}};
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

    // bool isbalance(string s){
    //     Stack st;
    //     string result;
    //     for(int i=0;i<s.size();i++){
    //        char c=s[i];
    //        if(c=='(' || c=='{' || c=='['){
    //             st.push(c);
    //        }
    //        if(c==')'){
    //         if(st.peek()=='('){
    //             st.pop();
    //         }
    //         if(st.peek()=='[' || st.peek()=='{'){
    //             return false;
    //         }
    //        }
    //         if(c=='}'){
    //         if(st.peek()=='{'){
    //             st.pop();
    //         }
    //         if(st.peek()=='['){
    //             return false;
    //         }
    //        }
    //        if(c==']' && st.peek()=='['){
    //         st.pop();
    //        }


    //     }
    //     return (st.empty());
            
            
    // }
bool isBalance(string s){
    Stack st;
    for(int i=0;i<s.size();i++){
        if(sym[s[i]]<0){
            st.push(s[i]);
        }else{
            if(st.empty()) return false;
            char ch=st.peek();
            st.pop();
            if(sym[ch] + sym[s[i]] !=0){
                return false;
            }
            
            
        }
    }
    return (st.empty());
}


int main(){
    string s;
    cin>>s;
    if(isBalance(s)){
        cout<<"balance\n";
    }
    else{
        cout<<"imbalance\n";
    }
    
   return 0;
}