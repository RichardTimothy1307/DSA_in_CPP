#include<bits/stdc++.h>
using namespace std;

//TODO:To implement selection sort

//*It has two parts one sorted and unsorted 
//*It starts from the first element as counter searches for the minimum in whole array and swaps it
//*This continues till end of the array


void selection_sort(int a[],int n){
   
    int min;

    for(int i=0;i<n-1;i++){
        int min=i;

        for(int j=i+1;j<n;j++){

            if(a[min] > a[j]){
                min=j;
            }

        }
        int temp=a[i];  //*Swapping the min from unsorted with target in sorted array left hand side
        a[i]=a[min];
        a[min]=temp;

    }



}



int main(){

  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
      cin>>a[i];
  }

  selection_sort(a,n);

  for(auto x:a){
      cout<<x<<" ";
  }



    return 0;
}