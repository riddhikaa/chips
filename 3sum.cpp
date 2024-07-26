
/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:
3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol; // To store the result triplets
        int n = nums.size();
        
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Iterate through the array with the first pointer 'i'
        for (int i = 0; i < n - 2; i++) {
            // Avoid duplicate solutions by skipping the same value
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Step 3: Initialize two pointers
            int j = i + 1; // Second pointer starts just after 'i'
            int k = n - 1; // Third pointer starts at the end of the array

            // Step 4: While second pointer is less than third pointer
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k]; // Calculate the sum of the triplet

                // Step 5: Check if the sum is zero
                if (sum == 0) {
                    // Add the triplet to the result
                    sol.push_back({nums[i], nums[j], nums[k]});

                    // Avoid duplicates for the second and third numbers
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;

                    // Move the second and third pointers inward
                    j++;
                    k--;
                } else if (sum < 0) {
                    // If the sum is less than zero, move the second pointer to the right
                    j++;
                } else {
                    // If the sum is greater than zero, move the third pointer to the left
                    k--;
                }
            }
        }
        // Return the list of triplets
        return sol;
    }
};
