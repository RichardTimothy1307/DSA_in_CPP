#include<bits/stdc++.h>
using namespace std;

//TODO:To implement shell sort
//*Compares the element in gap before and after
//*Starts with N/2 and then N/4 ...until 1
//*Two pointer i and j and distance of gap compares and swaps

void shell_sort(int* a,int n){

    for(int gap=n/2;gap>=1;gap/=2){   //*creates gaps N/2 N/4.....1

        for(int j=gap;j<n;j++){     //*j pointer initialized at gap

            for(int i=j-gap;i>=0;i=i-gap){   //*i pointer gap distance behind j
                if(a[i+gap]>a[i]){           //*break because we need to go back and increment j since comparison is over 
                    break;
                }
                else{
                    int temp=a[i+gap];    //*Otherwise swap and compare ith element with gap distance behind it
                    a[i+gap]=a[i];
                    a[i]=temp;
                }
            }

        }

    }





}


int main(){


    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
       cin>>a[i];

    }
    shell_sort(a,n);

    for(auto x:a){
       cout<<x<<" ";
    }







    return 0;
}