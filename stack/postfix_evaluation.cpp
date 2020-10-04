#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    stack<int>st;
    int t=s.size();
    for(int i=0;i<t;i++){
           if(s[i] == '+'|| s[i] == '-'|| s[i] == '*'|| s[i] == '/' || s[i] == '^'){
                   if(s[i]=='+'){
                       int a=st.top();
                       st.pop();
                       int b=st.top();
                       st.pop();
                       int c=b+a;
                       st.push(c);
                   }else if(s[i]=='-'){
                       int a=st.top();
                       st.pop();
                       int b=st.top();
                       st.pop();
                       int c=b-a;
                       st.push(c);
                   }else if(s[i]=='*'){
                       int a=st.top();
                       st.pop();
                       int b=st.top();
                       st.pop();
                       int c=b*a;
                       st.push(c);
                   }else if(s[i]=='/'){
                       int a=st.top();
                       st.pop();
                       int b=st.top();
                       st.pop();
                       int c=b/a;
                       st.push(c);
                   }else if(s[i]=='^'){
                       int a=st.top();
                       st.pop();
                       int b=st.top();
                       st.pop();
                       int c=pow(b,a);
                       st.push(c);
                   }else{}
           
           }
           else{
                st.push(s[i]-48);
                 
           }
    }  
    cout<<st.top()<<endl; 






    return 0;

}