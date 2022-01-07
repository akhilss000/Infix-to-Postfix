#include<iostream>
#include "stack"
using namespace std;

int priority(char c){
    if(c=='^')
        return 3;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='+' || c=='-')
        return 1;
    else
        return -1;
}

string convert(string s){
    char c;
    stack <char> st;
    string result;

    for(int i=0; i<s.length(); i++){
        c=s[i];

        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
            result+=c;
        else if(c=='(')
            st.push(c);
        else if(c==')'){
            while(st.top()!='('){
                result+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(priority(c)<priority(st.top())){
                result+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty())
    {
        result+=st.top();
        st.pop();
    }
    return result;
}

int main(){
    string s;
    cout<<"Enter infix : ";
    cin>>s;
    cout<<"Post fix : "<<convert(s);
    return 0;
}
