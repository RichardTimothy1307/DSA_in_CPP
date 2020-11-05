#include<bits/stdc++.h>
using namespace std;

//TODO:Create a Merge Sort Function -> mergesort to divide and merge to merge the divided array
//*Comes under the category divide and conquer 



//*Merge Function

void Merge(int *a,int start,int end){


int mid=(start+end)/2;

int temp[100];  //*Temp array to store the sorted elements after the merge
int i=start;    //*The start pointer for left half of the array going till mid
int j=mid+1;      //*The end pointer for Right half of the array going till end from mid+1
int k=start;          //*Used to assign elements of the divided array to temp array

//*Start comparing

while(i<=mid&&j<=end){

        if(a[i]<a[j]){      //*If the element at left halve is smaller then we copy that

            temp[k]=a[i];
            k++;
            i++;

        }else{    //*If the element at right halve is smaller then we copy that

            temp[k]=a[j];
            k++;
            j++;
        }
}


        //*If some element is left then we copy that 

        while(i<=mid){
            temp[k]=a[i];
            k++;
            i++;
        }
        while(j<=end){
            temp[k]=a[j];
            k++;
            j++;

        }

        for(int x=start;x<=end;x++){
            a[x]=temp[x];
        }
           

    


}


//*MergeSort function
void MergeSort(int a[],int start,int end){

       if(start>=end){  //*If we have only one element left we return *Base case*
           return;
       }
       
       int mid=(start+end)/2;   //*To divide the array from 0 to mid and mid+1 to end 

       //*Call the MergeSort Function on the divided arrays separately

       MergeSort( a,start,mid);
       MergeSort(a,mid+1,end);

       //*Call the merge function

       Merge(a,start,end);






}


int main(){


   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
       cin>>a[i];
   }

    MergeSort(a,0,n-1);


   for(auto v:a){
       cout<<v<<" ";
   }


    return 0;
}