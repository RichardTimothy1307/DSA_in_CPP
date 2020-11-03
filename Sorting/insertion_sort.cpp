#include<bits/stdc++.h>
using namespace std;

//TODO:To implement insertion sort
//*There are 2 parts one is sorted and one is unsorted
//*we take element one by one from unsorted and compare with all the one present in sorted
//*Then finally insert it to correct position

void Insertion_sort(int a[],int n){

    
    
    for(int i=1;i<n;i++){

         int value=a[i];
         int hole=i;

        while(hole>0 && a[hole-1]>value){  //*hole goes till 1 checking all the values till end
             a[hole]=a[hole-1]; //*if the hole-1 is greater we swap the hole value with hole-1s value 
             hole--;  //*we make hole-- which goes side by side the hole-1 to take its value
        }
        //*if it is the smallest element hole becomes 0 at end
        //*finally if the condition fails we get hole value to be given to our target
        a[hole]=value;

    }


}


int main(){


  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
      cin>>a[i];
  }

  Insertion_sort(a,n);

  for(auto x:a){
      cout<<x<<" ";
  }

    return 0;
}