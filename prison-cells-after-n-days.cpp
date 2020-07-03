/*
There are 8 prison cells in a row, and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.

Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)
Example 1:

Input: cells = [0,1,0,1,1,0,0,1], N = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: 
The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

Example 2:

Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
Output: [0,0,1,1,1,1,1,0]

Typical finite state machine, you will have to build an automata that changes states at each tick; given that we are basically only changing 6 bits (since after the first step the first and the last are always going to be 0, this is why I only loop in the 1 - 6 range) and that initial state will always match the same following state, for bigger values of n you can expect cycles to be come over and over again (after all, your state can only have 64 (2 ** 6) different values.

Once a cycle is detected (ie: it matches the first value in my seen container - here some discussion about it, feel free to expand upon it!), I just return the pre-stored state in seen with index equal to n % seen.size(), with seen.size() telling me how big is my loop interval (for this specific exercise, the loop seems to always be 14 steps large, but forgive me for using a more general approach and discuss the logic altogether at the cost of computing an extra % operation for each execution).

*/

class Solution {
public:
    
    vector<int> prisonAfterNDays(vector<int>& res, int n) {
        vector<int> tmp(8);
        vector<vector<int>> seen;
        while (n--) {
            for (int i = 1; i < 7; i++) {
                tmp[i] = (res[i - 1] == res[i + 1]);
            }
            if (seen.size() && seen.front() == tmp) 
                return seen[n % seen.size()]; 
            else seen.push_back(tmp);
            res = tmp;
        }
        return res;
    }

};