#include<iostream>
#include<string>
using namespace std;
class stk{
    char stack[100];
    int top=-1;
    public:
    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==99;
    }
    void push(char c){
        if(isFull()){
            cout<<"stack overflow!!"<<endl;
            return;
        }
        stack[++top]=c;
    }
    char pop(){
        if(isEmpty()){
            cout<<"Stack underflow!! "<<endl;
            return '0';
        }
        return stack[top--];
    }
    char topChar(){
        if(isEmpty()){
            cout<<"Stack Empty!!"<<endl;
            return '0';
        }
        return stack[top];
    }
    int prior(char c){
        char opr=c;
        if(opr=='*' ||opr=='/') return 2;
        if(opr=='+' || opr=='-') return 1;
        else return -1;
    }
};
void infix_postfix(string s,int length){
        int i=0;
        int n=length;
        stk st;
        string ans="";
        while(i<n){
            //operands add to answer
           if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')||
           (s[i]>='0' && s[i]<='9')){
            ans+=s[i];
           }
           //opening bracket
            else if(s[i]=='('){
            st.push(s[i]);
           }
           //closing bracket
           else if(s[i]==')'){
            while(!st.isEmpty() && st.topChar()!='('){
                ans+=st.pop();
            }
            st.pop();//pop opening bracket
           }
           else{    //operator
            while(!st.isEmpty()&& st.prior(s[i])<= st.prior(st.topChar())){
                ans+=st.pop();
            }
            st.push(s[i]);
           }
            i++;
        } 
        //remaining pop out into ans from the stack after while loop
        while(!st.isEmpty()){
            ans+=st.pop();
        }
        cout<<"Postfix: "<<ans<<endl;
    }
int main(){
    string exp;
    cout<<"Enter Infix expression: ";
    cin>>exp;
    int n=exp.length();
    infix_postfix(exp,n);
    return 0;
}
