#include<bits/stdc++.h>
using namespace std;

class Stack{
  private:
      int top;
      int arr[10];

  public:   //All the Functions
    Stack(){    //Constructor 
      top=-1;   

    }
    bool isEmpty(){
      if(top==-1){
        return true;
      }else{
        return false;
      }
    }
    bool isFull(){
      if(top==9){    //size-1=9
        return true;
      }else{
        return false;
      }
    }

    void push(int val){
       if(isFull()){
         cout<<"Stack Overflow"<<endl;
       }
       else{
         top++;   
         arr[top]=val;
       }
    }
    int pop(){
      if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
        return 0;
      }else{
        int popvalue=arr[top];
        top--;
        return popvalue;
      }
    }

    int count(){
      return top+1; //the size will +1 of index
    }
    int peek(){
       if(isEmpty()){
         cout<<"Stack Underflow"<<endl;
       }
       else{
         return arr[top];
       }
    }
    void display(){
       cout<<"The values in the Stack are->"<<endl;
       for(int i=top;i>=0;i--){
         cout<<arr[i]<<endl;
       }
    }

};



int main(){
   
    Stack s1;
    int option,value;
    do{
        cout<<"Enter the operation you want to perform otherwise 0 if you want to exit-"<<endl;
        cout<<"1.Push\n2.Pop\n3.Peek\n4.Count\n5.Display\n"<<endl;
        cin>>option;
        switch(option)
        {
          case 0:
          {
            break;
          }
          case 1:{
            cout<<"Enter the Value"<<endl;
            cin>>value;
            s1.push(value);
            break;
          }
          case 2:
          {
            cout<<"The popped value"<<s1.pop()<<endl;
            break;
          }
          case 3:
          {
            s1.peek();
            break;
          }
          case 4:
          {
            cout<<"The Number of items in stack are-"<<s1.count()<<endl;
            break;
          }
          case 5:{
            s1.display();
            break;
          }
          
         
        }

    }while(option!=0);



    return 0;
}