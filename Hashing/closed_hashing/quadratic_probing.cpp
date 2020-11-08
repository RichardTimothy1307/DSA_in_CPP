#include<bits/stdc++.h>
using namespace std;

//TODO:To implement Quadratic probing with arrays
//*Hash function will be key%size  




//*Hash function to return indexes
int hashfunction(int key,int n){
    return (key%10);
}


//*Insert Function 

void insert(int* a,int key,int n){      //*Pushes the key to right indexes according to hashfunction
    bool flag=false;
    int i=1;
    int index=hashfunction(key,n);
    int j;
    if(a[index]==-1){      //*FIrst we initialize all the empty places with -1 
        a[index]=key;
    }else{

        for(j=(index+i*i)%10;j!=index&&i<=9;j=(j+i*i)%10){      //*If the that index is full we check to the (key+i*i)%10 position  0<=i<=size-1
                                                      //* We do index+i*i mod 10 which gives us next position the we increment 
            if(a[j]==-1){
                a[j]=key;
                flag=true;
                break;
            }
            i++;
        }
        if(flag==false){                           //*We keep a boolean if it remains false then after our loop is completed we
            cout<<"HashTable is full"<<endl;        //*We output our hash table is full
        }

    }   

}

//*Search Function

void search(int* a,int key,int n){
    bool flag=false;
    int k=1;
    int i;
    int index=hashfunction(key,n);
    if(a[index]==key){
        cout<<index<<"->"<<key<<endl;
    }
    else{
        for(i=(index+k*k)%10;i!=index&&k<=9;i=(i+k*k)%10){
            if(a[i]==key){
                 cout<<i<<"->"<<key<<endl;
                 flag=true;
                 break;
            }
            k++;
        }
        if(flag==false){                          //*We keep a boolean if our element is not found it remains and false and we output we dont have any element
            cout<<"There's no such element"<<endl;
        }
    }
}


//*Display Function

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