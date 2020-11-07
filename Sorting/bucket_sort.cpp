#include<bits/stdc++.h>
using namespace std;

//TODO:Bucket Sort 
//*In a vector of 10 elements from 0 to 9 we store decimals with first
//*digit after 0 as index and sorts the bucket separately and then combine them

void bucket_sort(float* a,int n){

    vector<float> v[10];

    for(int i=0;i<n;i++){
        int index=10*a[i];
        v[index].push_back(a[i]);
    }

    for(int i=0;i<10;i++){
        sort(v[i].begin(),v[i].end());
    }

    int finalindex=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<v[i].size();j++){
            a[finalindex++]=v[i][j];
        }
    }





}


int main(){
    
   int n;
   cin>>n;
   float a[n];
   for(int i=0;i<n;i++){
       cin>>a[i];

   }
   bucket_sort(a,n);

   for(auto x:a){
       cout<<x<<" ";
   }

}