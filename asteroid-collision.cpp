/*
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
Example 4:

Input: asteroids = [-2,-1,1,2]
Output: [-2,-1,1,2]
Explanation: The -2 and -1 are moving left, while the 1 and 2 are moving right. Asteroids moving the same direction never meet, so no asteroids will meet each other.
*/

// Approach 1: Using a vector and use it as a Stack.

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if(asteroids.size() == 0)
		    return {};
        
        vector<int> ans = {asteroids[0]};
        
        for(int i = 1; i < asteroids.size(); i++){
            
            // If the two stones are collideable
            if(ans.size() > 0 && (ans.back() > 0 && asteroids[i] < 0) ){
                
                // Case 1: If asteroid size > ans back size, they will collide & we keep colliding.
                if(abs(asteroids[i]) > abs(ans.back())){
                    ans.pop_back();
                    i--; // so that again the same check happens for the same asteroid[i]
                }
                // Case 2: If asteroid size == ans back size, they will collide & both will be discarded
                else if(abs(asteroids[i]) == abs(ans.back())){
                    ans.pop_back();
                }
            }
            // If they are not collideable, we just push it in the ans.
            else {
                ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};