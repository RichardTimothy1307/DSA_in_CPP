class Solution {
public:
    int majorityElement(vector<int>& v) {
        //MOORE's Voting Algorithm 
        //O(N) time complexity 2N precisely
        int majority_index=0;
        int count=1;
        int N=v.size()/2;
        int maxcount=0;
        for(int i=0;i<v.size();i++){
            
             if(v[i]!=v[majority_index]){
                 count--;
                if(count==0){
                    majority_index=i;
                    count=1;
                }
             }else{
                 count++;
             }
        }
        for(int i=0;i<v.size();i++){
            if(v[i]==v[majority_index]){
               maxcount++;
            }
       }
        if(maxcount>N){
            return majority_element;
        }else{
            return -1;
        }
        
       
       
        
    }
};
