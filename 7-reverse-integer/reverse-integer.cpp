class Solution {
public:
    int reverse(int x) {
        long long result = 0; 
        while(x){
            int digit = x%10; 
            x /= 10; 
            result = result*10 + digit; 
            if(result > INT_MAX || result < INT_MIN){
                return 0;
            }
        }
        return result; 
    }
};