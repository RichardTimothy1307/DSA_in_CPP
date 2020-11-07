#include<bits/stdc++.h>
using namespace std;

//TODO:To implement radix sort 
//*This sorting algorithm sorts according to each digit again and again
//*Until the max no of digit finally we get sorted array

void counting_sort(int* a,int n,int pos){
    int count[10];
    int final[n];
    memset(count,0,sizeof(count));

    for(int i=0;i<n;i++){
        ++count[(a[i]/pos)%10];     //*The count of element at that pos 
    }

    //*Cumulative frequency
    for(int i=1;i<=9;i++){
        count[i]=count[i]+count[i-1];
    }

    for(int i=n-1;i>=0;i--){
        final[count[(a[i]/pos)%10]-1]=a[i];   //*Fill the final array according to the digit at pos each time
        count[(a[i]/pos)%10]--;
    }


    for(int i=0;i<n;i++){
        a[i]=final[i];
    }

}

void radix_sort(int* a,int n){
    int max=a[0];
    for(int i=1;i<n;i++){
        if(max<a[i]){
            max=a[i];
        }
    }
    for(int pos=1;(max/pos)>0;pos*=10){
            counting_sort(a,n,pos);
    }
}





int main(){

   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
       cin>>a[i];

   }
   radix_sort(a,n);

   for(auto x:a){
       cout<<x<<" ";
   }








    return 0;
}