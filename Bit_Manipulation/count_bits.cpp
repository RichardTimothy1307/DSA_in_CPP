class Solution {
public:
    int nofbit(int i){  //Brian Kerningahn Algo in logn time complexity
        int cnt=0;
        while(i>0){
            cnt++;
            i=i&(i-1);
        }
        return cnt;
    }
    vector<int> countBits(int num) {
        vector<int> v;
        for(int i=0;i<=num;i++){
    
            v.push_back(nofbit(i));
            
        }
        return v;
    }
};
