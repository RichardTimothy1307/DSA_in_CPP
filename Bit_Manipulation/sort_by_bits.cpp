class Solution {
public:
    static bool comp(int a,int b){
        bitset<16> b1(a),b2(b);
        if(b1.count()==b2.count()){
            return a<=b;
        }
        return b1.count()<b2.count(); //return true for true and false for false
    }
  
    
    vector<int> sortByBits(vector<int>& arr) {
          sort(arr.begin(),arr.end(),comp);
          return arr;
    }
};
