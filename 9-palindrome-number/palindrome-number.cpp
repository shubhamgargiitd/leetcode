class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false; 
        long long result = 0; 
        int copy = x; 
        while(x){
            int digit = x%10;
            x /= 10; 
            result = 10*result + digit; 

            
        }

        return (copy==result);
    }
};