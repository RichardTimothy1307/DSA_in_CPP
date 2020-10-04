#include<bits/stdc++.h>
using namespace std;
bool isOperator(char c)      //to check if the string character is operator or not 
{
 if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
 {
 return true;
 }
 else
 {
 return false;
 }
}
 
int precedence(char c)      //Here we assigned numbers to operators according to their precedance to be compared
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
 
string InfixToPostfix(stack<char> s, string infix)
{
 string postfix;
 for(int i=0;i<infix.length();i++)
 {
 if((infix[i] >= 'a' && infix[i] <= 'z')
 ||(infix[i] >= 'A' && infix[i] <= 'Z'))
 {
 postfix+=infix[i];               //If the string character is operand it will directly give output to the screen
 }
 else if(infix[i] == '(')          //If the character is opening braces it will push to the stack
 {
 s.push(infix[i]);
 }
 else if(infix[i] == ')')        //If it is a closing brace it will append the content of stack to our postfix string or till the stack is empty
 {
 while((s.top()!='(') && (!s.empty()))
 {
 char temp=s.top();        //appending the top value 
 postfix+=temp;
 s.pop();         //and also popping the values from stack the one we appended
 }
 if(s.top()=='(')
 {
 s.pop();        //if we encounter an opening brace at last we pop it 
 }
 }
 else if(isOperator(infix[i]))     //Here starts the condition to check operators and perform operations on it
 {
 if(s.empty())               //if stack is empty we will directly push to the stack
 {
 s.push(infix[i]);     
 }
 else
 {
 if(precedence(infix[i])>precedence(s.top()))        //if the precedence of the incoming operator is higher we push to the stack
 {
 s.push(infix[i]);
 } 
 else if((precedence(infix[i])==precedence(s.top()))&&(infix[i]=='^'))      //If the precedence is equal but it is exponential func we will push to the stack
 {
 s.push(infix[i]);
 }
 else
 {
 while((!s.empty())&&( precedence(infix[i])<=precedence(s.top())))    //If it is lower we will pop and append to the our final answer till we encounter a bracet
 {
 postfix+=s.top();
 s.pop();
 }
 s.push(infix[i]);       //finally we push our incoming new operator in stack
 }
 }
 }
 }
 while(!s.empty())
 {
 postfix+=s.top();    //finally at last we append all the values to the postfix variable
 s.pop();
 }
 
 return postfix;
}
 
int main() 
{  
 
  	string infix, postfix;
  	cout<<"Enter a Infix Expression :"<<endl;
  	cin>>infix;
  	stack <char> stack;
 cout<<"INFIX EXPRESSION: "<<infix<<endl;
  	postfix = InfixToPostfix(stack, infix);
  	cout<<endl<<"POSTFIX EXPRESSION: "<<postfix;
   
 return 0;
}