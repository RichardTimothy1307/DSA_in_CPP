#include<bits/stdc++.h>
using namespace std;

//TODO:To implement linear probing with arrays
//*Hash function will be key%size  




//*Hash function to return indexes
int hashfunction(int key,int n){
    return (key%10);
}


void insert(int* a,int key,int n){      //*Pushes the key to right indexes according to hashfunction
    int index=hashfunction(key,n);
    int j;
    if(a[index]==-1){      //*FIrst we initialize all the empty places with -1 
        a[index]=key;
    }else{

        for(j=(index+1)%10;j!=index;j=(j+1)%10){      //*If the that index is full we check to the +1 position
                                                      //* We do index+1 mod 10 which gives us next position the we increment 
            if(a[j]==-1){
                a[j]=key;
                break;
            }

        }
         if(j==index){
                cout<<"The hash table is full"<<endl;    //*If we reach that index again that means we have traversed through all the indexes
            }

    }   

}


void search(int* a,int key,int n){

    int i;
    int index=hashfunction(key,n);
    if(a[index]==key){
        cout<<index<<"->"<<key<<endl;
    }
    else{
        for(i=(index+1)%10;i!=index;i=(i+1)%10){
            if(a[i]==key){
                 cout<<i<<"->"<<key<<endl;
                 break;
            }
        }
        if(i==index){
            cout<<"There's no such element"<<endl;
        }
    }
}

void display(int* a){
    for(int i=0;i<10;i++){
            if(a[i]==-1){
                cout<<i<<"-->"<<"NULL"<<endl;
            }else{
                cout<<i<<"-->"<<a[i]<<endl;
            }
    }
}

int main(){
      int hashtable[10];
      memset(hashtable,-1,sizeof(hashtable));

      int n;
      cin>>n;
      int a[n];

      for(int i=0;i<n;i++){
          cin>>a[i];
          insert(hashtable,a[i],n);
      }

     int x;
     cout<<"Enter the element to search-";
     cin>>x;
     search(hashtable,x,10);
    
     cout<<endl;

     cout<<"The HashTable"<<endl;
     display(hashtable);       





    return 0;
}