#include<bits/stdc++.h>
using namespace std;

class Queue{
private:
    int front;
    int rear;
    int arr[20];

public:
    Queue(){    //constructor will always get called first so whenever we create class we initialize front and rear to -1
        front=-1;
        rear=-1;
    }
    
bool isEmpty(){
  if(front==-1&&rear==-1){   //the start condition
      return true;
  }else{
      return false;
  }
}
bool isFull(){
   if(rear==19){     //i.e size-1 which is 19 here
       return true;
   }else{
       return false;
   }
}
void Enqueue(int value){

if(isFull()){
    cout<<"Queue is Full"<<endl;
}
else if(front==-1&&rear==-1){
    front++;  //initialize to start i.e 0
    rear++;    //Rear to 0 start position
    arr[rear]=value;   //arr[0]=value
    rear++;            //increment the rear to 1;
}
else{
    arr[rear]=value;
    rear++;
}

}
int Dequeue(){
    int x=0;   //to take the deleted value
    if(isEmpty()){
        cout<<"Queue is Empty"<<endl;
        return 0;
    }else if(front==rear){   //for 0 the only element at 1st pos
        x=arr[front];
        front=rear=-1;
        return x;
    }
    else{
        x=arr[front];
        front++;
         return x;
    }
   
}
int count(){
        if(rear==-1 && front==-1)
			return 0;
		else
		return rear-front+1;
}

void display(){
    for(int i=front;i<rear;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}



};

int main(){
int cont=1;
int value;
Queue q1;

 do{
     cout<<"Enter-"<<endl;
     cout<<"1.Enqueue"<<endl;
     cout<<"2.Dequeue"<<endl;
     cout<<"3.isEmpty()"<<endl;
     cout<<"4.isFull()"<<endl;
     cout<<"5.count"<<endl;
     cout<<"6.Display"<<endl;
     cout<<"7.Exit"<<endl;
    int option;
    cin>>option;
    switch(option){
        case 1:{
            cout<<"Enter the value to Enqueue-"<<endl;
            cin>>value;
            q1.Enqueue(value);
            break;
        }
        case 2:{
            cout<<"The Dequeue value is-"<<q1.Dequeue()<<endl;
            break;
        }
        case 3:{
            if(q1.isEmpty()){
                cout<<"Queue is empty"<<endl;
            }else{
                cout<<"Queue is not empty"<<endl;
            }
            break;
        }
        case 4:{
            if(q1.isFull()){
                cout<<"Queue is Full"<<endl;
            }else{
                cout<<"Queue is not Full"<<endl;
            }
            break;
        }
        case 5:{
            cout<<"The no. of element in Queue is"<<q1.count()<<endl;
            break;
        }
        case 6:{
            cout<<"The element in Queue are-"<<endl;
            q1.display();
            break;
        }
        case 7:{
            cont=0;
            break;
        }
    }

 }while(cont==1);

    return 0;
}