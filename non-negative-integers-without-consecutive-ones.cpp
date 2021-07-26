/*
Given a positive integer n, return the number of the integers in the range [0, n] whose binary representations do not contain consecutive ones.
*/

/* // time limit exceeded 
class Solution {
public:
    int findIntegers(int n) {
        int count = 0;
        for(int i = 0; i <= n; i++) {
            if(check(i)) {
                count++;
            }
        }
        return count;
    }
    bool check(int n) {
        int i = 31;
        while(i > 0) {
            if((n & (1 << i)) != 0 && (n & (1 << (i - 1))) != 0) {                
                return false;
            }
            i--;
        }
        return true;
    }
};
*/
class Solution {
public:
    int findIntegers(int n) {
        // add extra 1 for 0
        // find the count of valid integers in the range [1, n]
        return 1 + countValidInts(1, n);
    }
    
private:
    int countValidInts(int integer, int limit) {
        // do not add to total count if current integer exceeds limit
        if (integer > limit) {
            return 0;
        }
        
        if (integer & 1) {
            // current integer ends with bit 1
            // one option - append bit 0
            
            // add 1 to count current valid integer
            // add count of valid integers when appending 0 to current integer
            
            return 1 + countValidInts((integer << 1) | 0, limit);
        } else {
            // current integer ends with bit 0
            // two options - append bit 0 or bit 1
            
            // add 1 to count current valid integer
            // add count of valid integers when appending 0 to current integer and
            // add count of valid integers when appending 1 to current integer
            
            return 1 + countValidInts((integer << 1) | 0, limit) + countValidInts((integer << 1) | 1, limit);
        }
    }
};