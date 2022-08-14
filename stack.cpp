#include <bits/stdc++.h>
using namespace std;

int inStackpre(char x){
    if (x=='+' || x=='-')
        return 2;

    else if (x=='*' || x=='/')    
        return 4;

    else if (x=='^')    
        return 5;

    return 0;  
}


int outStackpre(char x){
    if (x=='+' || x=='-')
        return 1;

    else if (x=='*' || x=='/')    
        return 3;

    else if (x=='^')    
        return 6;

    else if (x=='(')    
        return 7;

    return 0;    
}


bool isoperand(char x){
    if ((x>=65 && x<=90) || (x>=48 && x<=57) || (x>=97 && x<=122))
        return true;
    return false;    
}


string infixtopostfix(string infix){
    string postfix;
    stack<char> st;
    int i=0;
    char s;

    while (infix[i]!='\0'){
        if (isoperand(infix[i]))       
            postfix+=infix[i++];

        else{
            if (st.empty() || (outStackpre(infix[i]) > inStackpre(st.top())))
                st.push(infix[i++]);

            else{
                s=st.top();
                st.pop();

                if (infix[i]==')'){
                    while (s!='('){
                        postfix+=s;
                        s=st.top();
                        st.pop();
                    }
                    i++;
                }

                else
                    postfix+=s;
            }    
        }    
    }

    while (!st.empty()){
        s=st.top();
        st.pop();
        postfix+=s;
    }

    return postfix;
}


int main(){
    string s;
    cout<<endl<<"Enter Infix Expression : ";
    cin>>s;

    cout<<endl<<endl<<"Infix Expression : "<<s;
    cout<<endl<<"Postfix Expression : "<<infixtopostfix(s);
    return 0;
}