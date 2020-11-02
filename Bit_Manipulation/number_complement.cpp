class Solution {
public:
    int findComplement(int num) {
       if(num==0) return 1;
        int nofbits=log2(num)+1; //no of bits to find the bitmask value
        int t=(unsigned)(1<<nofbits)-1;
        return num^t;
        //101
        //111 -->>>> 2^3-1 where 3 is no of bits do xor and get answer
        
        
    }
};
