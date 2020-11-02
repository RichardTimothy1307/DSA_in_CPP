
       class Solution {
public:
    char findTheDifference(string s, string t) {
        char becomenull=0;
        int i=0;
        for(i=0;i<s.size();i++){
            
            becomenull^=s[i]^t[i];  //will make all character null till n-1
    }
        return becomenull^t[i];  //null xor with last char will give char
    }
};
            
           
