#include<bits/stdc++.h>
using namespace std;

//*Defining our own data type for data and address

class Node
{
    public:
        int data;
        Node *next;  //*pointer to node
};

//TODO:Create a function to insert a data at the beginning of the Linked List
//*Here we pass reference to the head node pointer to pointer because we pass by address in the function 

void insert_at_front(Node** head_ref,int new_data)
{
    Node* new_node=new Node();  //*Created a new node
    new_node->data=new_data;    //*put in the data
    new_node->next=(*head_ref);  //*The next will point to the head
    *head_ref=new_node;           //*Later head will change to new_node
}

//TODO:Create a function to push value after a position

void insert_at_position(Node** head_ref,int value,int pos)
{
     Node* temp=*head_ref;
     Node* new_node=new Node();
     new_node->data=value;

     if(temp==NULL){    //*The list is empty
         new_node->next=*head_ref;
         *head_ref=new_node;
         return;

     }
     if(pos==1){   //*Pos = 1 means at beginning
         new_node->next=(*head_ref);
         *head_ref=new_node;
         return;
     }
     for(int i=0;i<pos-1;i++){
            temp=temp->next;
     }
     new_node->next=temp->next;  //*Creating the link of new with the next node of temp
     temp->next=new_node;           //*Breaking the link of temp node n-1th node with nth and creating with new_node
     return;

}
//TODO: Insert at the end

void append(Node** head_ref,int new_data){
    Node* new_node=new Node();
    Node *temp=*head_ref;
    new_node->data=new_data;
    new_node->next=NULL;   //*It is going to be at the last so NULL 
    if(temp==NULL){
        new_node->next=*head_ref;   //*If the list is empty
        *head_ref=new_node;
        return;
    }
    while(temp->next!=NULL){   //*Otherwise iterate till end
        temp=temp->next;

    }
    temp->next=new_node;   //*Creating the link of the last node with the new node
    return;

}

//TODO:To create a function to delete from front and end and by key and by position


void delete_from_front(Node** head_ref){
    Node* temp=*head_ref;
    if(temp==NULL){
        cout<<"The List is empty"<<endl;
        return;
    }
    cout<<"The element deleted will be-"<<temp->data<<endl;
    *head_ref=temp->next;
    delete(temp);
    return;

}


void delete_from_end(Node** head_ref){
    Node* temp=*head_ref;
    Node* new_last;
    if(temp==NULL){
        cout<<"The List is empty"<<endl;
        return;
    }
    while(temp->next!=NULL){
        new_last=temp;
        temp=temp->next;
    }

    cout<<"The element deleted will be-"<<temp->data<<endl;
     new_last->next=NULL;
    delete(temp);
    return;

}

void delete_by_key(Node** head_ref,int key){
    Node* temp=*head_ref;
    Node* prev;  
    if(temp!=NULL && temp->data==key){  //*if the element is first that means if head has the key 
        *head_ref=temp->next;
        delete(temp);
        return;
    }
        //*Traverse the list and delete

        while(temp!=NULL&&temp->data!=key){
            prev=temp;     //!Always keep track of the previous node
            temp=temp->next;
        }
        if(temp==NULL) return;  //*if the element isnt present

        prev->next=temp->next;
        delete(temp);
        return;
}

void delete_by_position(Node** head_ref,int position){
   if(*head_ref==NULL){
       cout<<"The List is empty"<<endl;
       return;
   }
   Node* temp= *head_ref;

   if(position==0){    //*If to delete from front
       *head_ref=temp->next;
       delete(temp);
       return;
   }
   for(int i=0;temp!=NULL&&i<position-1;i++){  //*We have to get to previous element that is n-1 and also check that temp has some value it is not null
        temp=temp->next;
   }
  //*If the position is after the last node that is temp doesnt have anything
    if(temp==NULL||temp->next==NULL){   //*because we will be at position before last node if we want to delete last node the next of it cant be null
        cout<<"Out of range"<<endl;
        return;
    }
    //* Initialize a new variable to point to the node after the target node to make link with the prev node
    Node *nextnew=temp->next->next;
    delete(temp->next); //* Because we have the address of the next node in temp and It will go to the memory after prev that is target node and delete it
    temp->next=nextnew;

}


void printlist(Node *node){
    while(node!=NULL){
        cout<<"->"<<node->data;
        node=node->next;
    }
    cout<<endl;
}

//TODO: The main function will have all the function implemented

int main(){
     
     Node* head=NULL;

     append(&head,6);  //*6->NULL

     insert_at_front(&head,7);    //* 7->6->NULL

     insert_at_front(&head,1);  //* 1->7->6->NULL

     append(&head,4);     //* 1->7->6->4->NULL

     insert_at_position(&head,5,3);    //* 1->7->6->5->4

     cout<<"The Linked List is ";
     printlist(head);
     

     delete_by_position(&head,4);
     cout<<"The list after deleting 4rd position"<<endl;
     printlist(head);

     delete_from_front(&head);   //* 7->6->5->4
     cout<<"The list after deleting from front"<<endl;
     printlist(head);

     delete_from_end(&head);     //* 7->6->5
     cout<<"The list after deleting from end"<<endl;
     printlist(head);
     
     delete_by_key(&head,6);
     cout<<"The list after deleting key=6"<<endl;
     printlist(head);
     

     




    return 0;
}