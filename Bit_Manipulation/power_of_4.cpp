class Solution {
public:
    bool isPowerOfFour(int num) {
       if(num <= 0) 
           return false;
    return ( num%3==1 && (num & num - 1) == 0);  //all the powers of 4 when divided by leaves the remainder 1 and the base check num&num-1 is to check power of 2 or 4
}
};
