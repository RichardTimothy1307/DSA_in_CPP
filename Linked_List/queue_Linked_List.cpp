#include<bits/stdc++.h>
using namespace std;

//TODO:Implementation of Queue using Linked List

class QNode{    //* A node for queue 

    public:
         int data;
         QNode* next;

         QNode(int d){
             data=d;
             next=NULL;
         }
};

class Queue{   //*The main class with all function we store element in the Qnode class
public:
    QNode *front,*rear;
    Queue(){
        front=rear=NULL;
    }
  public:
    void enqueue(int value){
      QNode* new_node=new QNode(value);

      if(rear==NULL){
          front=rear=new_node;
          return;
      }

      //Adding the queue at the end of node and changing the rear
      rear->next=new_node;
      rear=new_node;
    
    }

  public: 
    void dequeue(){

        if(front==NULL){
            cout<<"Queue is empty"<<endl;
            return;
        }
        QNode* temp=front;   //*storing the previous front and moving front to the next node;
        front=front->next;
   
         if(front==NULL){  //*the next to it is null nothing
             rear=NULL;
         }
            delete(temp);


    }
};





int main(){
   Queue q;

   q.enqueue(10);
   q.enqueue(100);
   q.enqueue(1000);
   q.dequeue();

   cout<<"The front of queue"<<(q.front)->data<<endl;
   cout<<"The rear of queue"<<(q.rear)->data<<endl;






    return 0;
}