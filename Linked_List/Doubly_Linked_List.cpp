#include<bits/stdc++.h>
using namespace std;

//TODO:To implement doubly linked list 
//TODO:Insert at front,back,after a position,before a position

//*Linked List node or user defined data type
class Node{

     public:
        int data;
        Node* next;
        Node* prev;

};

//*Function to insert at the beginning of the linked list

void insert_at_beginning(Node** head_ref,int value){

    Node* new_node = new Node(); //*creating a node dynamically
    new_node->data=value;        //*setting the data part to the given value

    new_node->next=*head_ref; //*takes the value stored in head previously
    new_node->prev=NULL;      //*Default

    if(*head_ref!=NULL){   //*If the list is not empty
        (*head_ref)->prev=new_node;  //*The node present before will take the address of the new node to prev arg
    }
    *head_ref=new_node; //*finally change the head to the newly created node
}


//*Function to insert after a given position

void insert_after_pos(Node** head_ref,int value,int pos){

        Node* temp=*head_ref;
        Node* new_node=new Node();
        new_node->data=value;

        if(temp==NULL){ //*the list is empty
            new_node->next=*head_ref;
            new_node->prev=NULL;
            *head_ref=new_node;
             return;
        }
        if(pos==0){  //*Insert at beginning when there is already a node present
            new_node->next=*head_ref;
            (*head_ref)->prev=new_node;
            *head_ref=new_node;
            return;
        }

        for(int i=0;i<pos;i++){
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"The previous node cannot be null"<<endl;
            return;
        }
        //*Assign next of new node to the next of prev node that means n-1th node's next(n+1th (after new node)) to the new node 
        new_node->next=temp->next;

        //*prev node's next as new node
        temp->next=new_node;

        //*Previous node arg of new node as temp i.e prev node
        new_node->prev=temp;

        //*N+1th prev arg as new node the one which came after n-1th node
        if(temp->next!=NULL){
            new_node->next->prev=new_node;
        }


}

//*Function to insert before a position

void insert_before_pos(Node** head_ref,int value,int pos){

    Node* temp=*head_ref;
    Node* new_node=new Node();
    new_node->data=value;

    if(temp==NULL){ //*the list is empty
        new_node->next=*head_ref;
        new_node->prev=NULL;
        *head_ref=new_node;
         return;
    }
    if(pos==0){
        new_node->next=*head_ref;
        new_node->prev=NULL;
        *head_ref=new_node;
         return;
    }
    for(int i=0;i<pos;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<"The next of new node cannot be null"<<endl;
        return;
    }
    new_node->prev=temp->prev;  //*Will take the value of prev of temp because its getting inserted before it
    temp->prev=new_node;  //*the prev arg of temp will take the new_node address
    new_node->next=temp; //*The new node's next will take the temp address
    
    if(new_node->prev!=NULL){ //*the node before new node is not null then we set its next as new node
        new_node->prev->next=new_node;
    }//*If it is null then it is the new head node
    else{
        (*head_ref)=new_node;
    }

}

//*Function to insert at last


void append(Node** head_ref,int value){

   Node* temp=*head_ref;
   Node* new_node=new Node();

   new_node->data=value;

   new_node->next=NULL; //*Since its last node

   if(temp==NULL){
       new_node->prev=NULL;
       *head_ref=new_node;
       return;
   }
   //*Go till end of the list

   while(temp->next!=NULL){
       temp=temp->next;
   }
   temp->next=new_node;

   new_node->prev=temp;

   return;

}

void printlist(Node** head_ref){
 
    Node* last;
    Node* temp=*head_ref;
    cout<<"Traversal in Forward direction"<<endl;
    while(temp!=NULL){
        cout<<"->"<<temp->data;
        last=temp;
        temp=temp->next;
    }
    cout<<endl;
    cout<<"Backward Traversal"<<endl;
    while(last!=NULL){
        cout<<"->"<<last->data;
        last=last->prev;
    }


}

//TODO:All the deletion operations 

void delete_from_front(Node** head_ref){

    Node* temp=*head_ref;
    if(temp==NULL){
        cout<<"The List is empty"<<endl;
        return;
    }
    cout<<"Element going to be deleted-"<<temp->data<<endl;
    temp->next->prev=NULL;
    *head_ref=temp->next;
    delete(temp);
}

void delete_from_end(Node** head_ref){
    Node* temp=*head_ref;
    if(temp==NULL){
        cout<<"The list is empty"<<endl;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    cout<<"Element going to be deleted-"<<temp->data<<endl;
    temp->prev->next=NULL;
    delete(temp);
    
}


void delete_at_pos(Node** head_ref,int pos){

        Node* temp=*head_ref;
        if(temp==NULL){
            cout<<"The list is empty"<<endl;
        }
        if(pos==0){
            cout<<"Element going to be deleted-"<<temp->data<<endl;
            temp->next->prev=NULL;
            *head_ref=temp->next;
            delete(temp);
            return;
        }
        for(int i=0;i<pos;i++){
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete(temp);





}


int main(){

        Node* head=NULL;

        append(&head,6);

        insert_at_beginning(&head,7);

        insert_at_beginning(&head,1);

        append(&head,4);

        insert_after_pos(&head,8,2);

        insert_before_pos(&head,5,1);

         
        cout<<"Linked List is-"<<endl;
        printlist(&head);

        cout<<endl;


        cout<<"Deleting from given position element"<<endl;
        delete_at_pos(&head,3);

        cout<<"Linked List is-"<<endl;
        printlist(&head);

        cout<<endl;

        cout<<"Deleting the first element"<<endl;
        delete_from_front(&head);

        cout<<"Linked List is-"<<endl;
        printlist(&head);
 
        cout<<endl;
    
        cout<<"Deleting the Last element"<<endl;
        delete_from_end(&head);

        cout<<endl;

        cout<<"Linked List is-"<<endl;
        printlist(&head);






    return 0;
}