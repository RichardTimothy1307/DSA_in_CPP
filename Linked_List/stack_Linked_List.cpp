#include<bits/stdc++.h>
using namespace std;

//TODO:Implement stack using linked list

//*Declaring node which will act as datatype for stack

class Node{

public:
    int data;
    Node* next;

};
//*Implement it as pushing a value at front
void push(Node** head,int value){
     Node* new_node=new Node();
     new_node->data=value;
     new_node->next=*head;
     *head=new_node;

}
//*Check if head==null or not
bool isempty(Node** head){
    if(head==NULL){
        return true;
    }else{
        return false;
    }
}

//*The data part of first node
int peek(Node** head){
    Node* temp=*head;
    if(isempty(head)==false){
        return temp->data;
    }else{
        cout<<"The list is empty"<<endl;
    }
    return 0;
}

//*Implement it as deleting from front
void pop(Node** head){
    Node* temp=*head;
    if(*head==NULL){
        cout<<"The List is empty"<<endl;
        return;
    }
     *head=temp->next;
     delete(temp);
     return;
}


//*Just traverse till temp==null and print the data part of each node
void display(Node** head){

        Node* temp=*head;
        if(*head==NULL){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        cout<<"The stack is-";
        while(temp!=NULL){
            cout<<"->"<<temp->data;
            temp=temp->next;
        }
        cout<<endl;

}

//TODO:The function will have the working of all the functions created

int main(){
     Node* head=NULL;

     push(&head,1);
     push(&head,2);
     push(&head,3);
     push(&head,4);
     display(&head);
     cout<<"The top element is-"<<peek(&head)<<endl;

     pop(&head);
     display(&head);

     pop(&head);
     display(&head);







    return 0;
}