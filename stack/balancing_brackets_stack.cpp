#include<bits/stdc++.h>
using namespace std;
int main(){
     string s;
     cin>>s;
     stack<char> st;
    for(int i=0;i<s.length();i++){
            if (s[i] == '{' || s[i] == '[' || s[i] == '('){    //If we encounter a opening bracket we push to stack
                st.push(s[i]);
            }
            if(!st.empty()){
                 if(s[i]==')'&&st.top()=='('){     //If we encounter a closing bracket and if our top of stack in equal to that then we pop
                     st.pop();
                     continue;
                 }if(s[i]==']'&&st.top()=='['){    // Similarly for Square Bracket
                     st.pop();
                     continue;
                 }if(s[i]=='}'&&st.top()=='{'){    //also curly bracket
                         st.pop();   
                         continue;
                    
                 } 
            }else{            //we break because the opened bracket should be closed thats why we everytime encounter bracket of same type in a valid one
                break;
            }
                
    }
      
         if(st.empty()){         //finally if all the brackets are closed thats is they are popped corresponding to their closing one its valid
             cout<<"Balanced"<<endl;
         }else if(!st.empty()){                  //if not there are brackets unclosed that means its not balanced
             cout<<"Not Balanced"<<endl;
         }else{}




    return 0;
}