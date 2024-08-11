/*
70. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. 
In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:
1 <= n <= 45
*/

/*
this question is application of fibonacci series

suppose the no. of ways to reach 1 st level is X
and 2nd level is Y , then no. of ways to reach level 3 
will be X+Y

*/
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int arr[n+1];
        
        memset(arr,0,sizeof(arr));
        arr[0]=1; // 0 is ground level , ways to reach there is 1 only
        arr[1]=1;  // 1 is first level , ways to reach there is 1 only
        for(int i=2;i<=n;i++){
            arr[i]=arr[i-1]+arr[i-2];
        }
        int ans=arr[n]; // nth level tak aane pr kitne ways ho gaye ? == answer
        return ans;
    }
};
