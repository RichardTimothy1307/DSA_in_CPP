class Solution {
public:
    bool isPowerOfFour(int num) {
       if(num <= 0) 
           return false;
    return (((int)log2(num)+1)%2) && (num & num - 1) == 0;  //power of 4 has odd no of bits in it so log function gives us the no of bits 
}
};
