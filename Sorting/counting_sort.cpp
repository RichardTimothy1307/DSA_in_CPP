#include<bits/stdc++.h>
using namespace std;

//TODO:Implement counting sort works well with element withing a range and need to modify for negative elements

//*Not a comparison algorithm it uses a hashing type approach
//*Counts the number of elements and then cumulative array of count to get the number of  numbers before it
//*Then we get the index after that 
//*Stable sorting algorithm

void counting_sort(int* a,int n){
    int max=a[0];
    int final[n];

for(int i=1;i<n;i++){

    if(a[i]>max){
        max=a[i];    //*To find the max to get the max size of our array
    }
}

int count[max+1];
memset(count,0,sizeof(count));  //*Makes all elements 0 of our count array

for(int i=0;i<n;i++){

++count[a[i]];     //*counts the no. of occurences of each element 


}

for(int i=1;i<=max;i++){

count[i]=count[i]+count[i-1];  //*Cumulative frequency to get the index of our element
    
}


for(int i=n-1;i>=0;i--){

    final[count[a[i]] - 1]=a[i];     //*Start traversing from the end to maintain the relative order
    --count[a[i]];
}


for(auto v:final){
    cout<<v<<" ";
}




}



int main(){

   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
       cin>>a[i];

   }
   counting_sort(a,n);





    return 0;
}