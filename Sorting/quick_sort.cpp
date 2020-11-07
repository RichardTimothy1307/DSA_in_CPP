#include<bits/stdc++.h>
using namespace std;

//TODO:To implement Quicksort
//*Quicksort is an in place sorting Algorithm 
//*Takes a pivot and makes the array such that all greater than it comes to right of it and smaller to left
//*Recursively (Divide and Conquer)


//*Partition Function to get the index and the pivot at the correct position


int Partition(int* a,int start,int end){

        int pivot=a[end];  //*The pivot assigned as the last element
        int pindex=start;  //*The index for pivot
        int j;
        for(j=start;j<end;j++){
            if(a[j]<pivot){
                int temp=a[j];       //*If the element is less than pivot we swap that with 
                a[j]=a[pindex];      //*pivot so that it falls before pindex if greater we do nothing
                a[pindex]=temp;
                pindex++;
            }

        }
        int temp=a[pindex];  //*Finally we swap the pivot with its correct position that is parition index 
        a[pindex]=a[end];
        a[end]=temp;

        return pindex;


}



//*QuickSort function which is halve itself and gets called recursively

void QuickSort(int* a,int start,int end){
    if(start>=end){
        return;  //*base case
    }

    int PartitionIndex= Partition(a,start,end);   //*gets the the correct partion index 
    QuickSort(a,start,PartitionIndex-1);          //*Left Half
    QuickSort(a,PartitionIndex+1,end);            //*Right Half



}



int main(){

   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
       cin>>a[i];
   }

    QuickSort(a,0,n-1);



   for(auto v:a){
       cout<<v<<" ";
   }




    return 0;
}