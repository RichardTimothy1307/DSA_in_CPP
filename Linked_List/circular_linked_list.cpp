#include<bits/stdc++.h>
using namespace std;

//TODO:To implement circular linked list with push and deletion operations


class Node{
    public:
      int data;
      Node* next;
};

//*Function to insert a node at beginning and the last node will always point to head

void push(Node** head_ref,int value){

    Node* new_node=new Node();
    new_node->data=value;
    new_node->next=*head_ref;

    //*If the linked list is not null
    if(*head_ref!=NULL){
        Node* temp=*head_ref;
        //*find last node and make it point towards the new head

        while(temp->next!=*head_ref){
            temp=temp->next;
        }
        temp->next=new_node;
    }else{
     new_node->next=new_node;  //*the first node only
    }
    *head_ref=new_node;

}

//*function to delete a node given its key

void deleteNode(Node** head,int key){
    if(*head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    //*If the list has only one node
    if((*head)->data==key&&(*head)->next==*head){
        delete(*head);
        *head=NULL;
        return;
    }

    Node *last=*head,*target;

    if((*head)->data==key){
        while(last->next!=*head){
            last=last->next;
        }
        last->next=(*head)->next;
        delete(*head);
        *head=last->next;
    }

    //*traversing through the whole list till the end or key is found
    while(last->next!=*head && last->next->data!=key){
        last=last->next;
    }
    //*If node is found
    if(last->next->data==key){
        target=last->next;
        last->next=target->next;
        delete(target);
    }else{
        cout<<"Key not found"<<endl;
    }
}

//*Function to print the list

void printList(Node* head){
    Node* temp=head;
    if(head!=NULL){
        do{
            cout<<"->"<<temp->data;
            temp=temp->next;
        }while(temp!=head);
    }
    cout<<endl;
}


int main(){
    

    //*Creating the linked list

    Node* head=NULL;

    push(&head,2);
    push(&head, 3); 
    push(&head, 4); 
    push(&head, 5); 
    push(&head, 6); 
  
    cout << "List Before Deletion: "; 
    printList(head); 
  
    deleteNode(&head, 5); 
  
    cout << "List After Deletion: "; 
    printList(head); 






    return 0;
}