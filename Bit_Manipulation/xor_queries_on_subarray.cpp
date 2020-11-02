class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int xors[arr.size()];
        xors[0]=arr[0]; //initialize the first value
        for(int i=1;i<arr.size();i++){
            xors[i]=xors[i-1]^arr[i];   //takes the prvs xors and does the xors with the next value
            
}
          vector<int> v;
         for(int i=0;i<queries.size();i++){
             int L=queries[i][0];
             int R=queries[i][1];
             if(L==0){
                 v.push_back(xors[R]);  //1 2 3 4 5 ...R which is pre calculated and stored at Rth index of xors array
                 
             }else if(L>0){
                 v.push_back(xors[R]^xors[L-1]);  //(0..3..4..L-1,L,...R)^(0,1,2,....L-1)=(L,L+1.....R) becuz A^A=0 and 0^A=A
             }
         }
        return v;
        
    }
};
