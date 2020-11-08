#include<bits/stdc++.h>
using namespace std;

//TODO:To create a hash map with separate chaining
//*Separate chaining has buckets and with linked lists in it
//*We will be using list<int> STL that is doubly linked list for implementation



class Hash{

    int buckets;  //*No of buckets

    list<int> *table;   //*Pointers to an array containing buckets

public:
    Hash(int v);  //Constructor
    void insertItem(int x);  //*insert function
    void deleteItem(int key);  //*Delete the item 

    int hashfunction(int x){
        return x%buckets;
    }

    void display();
    void search(int key);

};

Hash::Hash(int b){
    this->buckets=b;
    table = new list<int>[buckets];  //*assigns a memory block to the table with no of buckets

}

void Hash::insertItem(int key){
    int index=hashfunction(key);
    table[index].push_back(key);  //*push to that particular table at index
}

void Hash::deleteItem(int key){

    //*Index of the key from hash function
    int index=hashfunction(key);

    list<int>:: iterator it;
    for(it=table[index].begin();it!=table[index].end();it++){
        if(*it==key){
            break;
        }
    }

    if(it!=table[index].end()){
        table[index].erase(it);   //*Erase function of stl deletes the element
    }

}

void Hash::display(){
    for(int i=0;i<buckets;i++){
        cout<<i;
        for(auto x:table[i]){
            cout<<"-->"<<x;
        }cout<<endl;
    }
}
void Hash::search(int key){

    int index=hashfunction(key);

    list<int>:: iterator it;
    for(it=table[index].begin();it!=table[index].end();it++){
        if(*it==key){
            cout<<"Element found at "<<index<<"th bucket"<<endl;
            break;
        }
    } 
    if(it==table[index].end()){
        cout<<"Element not found"<<endl;
    }
}


int main(){

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    Hash h(n); //*creates n buckets 

    for(int i=0;i<n;i++){
        h.insertItem(a[i]);
    }

    int x;
    cout<<"Enter element to delete-"<<endl;
    cin>>x;
    h.deleteItem(x);

    h.display();

    cout<<"Enter to search an item"<<endl;
    int y;
    cin>>y;
    h.search(y);







    return 0;
}