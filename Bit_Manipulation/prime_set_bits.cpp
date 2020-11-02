class Solution {
public: 
    bool isprime(int x){

    if(x==1){
        return false;
    }else{
        for(int i=2;i*i<=x;i++){ //till sqrt of n i=n^1/2
            if(x%i==0){
                return false;
            }
        }
    }
    
    return true;
    
    }
    

    int countPrimeSetBits(int L, int R) {
        int cnt=0;
        for(int i=L;i<=R;i++){
            int a=__builtin_popcount(i);
            if(isprime(a)==true){
                cnt++;
            }else{
                //
            }
        }
        return cnt;
    }
};
