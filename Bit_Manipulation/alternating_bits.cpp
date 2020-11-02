class Solution {
public:
    
    vector<int> dectobinary(int n){
         vector<int> v;
        while(n>0){
            v.push_back(n%2);
            n/=2;
        }
        return v;
    }
    
    
    
    
    bool hasAlternatingBits(int n) {
        bool flag=true;
        vector<int> a= dectobinary(n);
        for(int i=0;i<a.size()-1;i++){
            if((a[i]==0&&a[i+1]==0)||(a[i]==1&&a[i+1]==1)){
                flag=false;
            }     
    }
        if(flag==true){
            return true;
        }
        return false;
    }
};
