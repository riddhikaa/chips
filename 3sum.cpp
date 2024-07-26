
/*
QUES:
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
        return sol;
    }
};

 /*
Detailed Explanation
Initialization:
vector<vector<int>> sol; 
initializes an empty 2D vector to store the resulting triplets.
int n = nums.size(); 
stores the size of the input vector for easy reference.

Sorting the Array:
sort(nums.begin(), nums.end()); sorts the array in non-decreasing order. 
Sorting helps in efficiently avoiding duplicates and utilizing the two-pointer technique.

Iterating through the Array:
for (int i = 0; i < n - 2; i++) iterates through the array using the first pointer i. 
We loop until n-2 because we need at least three elements for a triplet.

Skipping Duplicates for the First Element:
if (i > 0 && nums[i] == nums[i - 1]) continue; skips the iteration if the current element is the same as the previous one. This helps avoid duplicate triplets.

Two-Pointer Technique:
int j = i + 1; sets the second pointer j to the element right after i.
int k = n - 1; sets the third pointer k to the last element of the array.

Finding Triplets:
while (j < k) iterates as long as the second pointer is less than the third pointer.
int sum = nums[i] + nums[j] + nums[k]; calculates the sum of the current triplet.

checking the Sum:
If sum == 0, we found a valid triplet. Add it to the result vector using sol.push_back({nums[i], nums[j], nums[k]});.
To avoid duplicates, we increment the second pointer j as long as the next element is the same using while (j < k && nums[j] == nums[j + 1]) j++;.
Similarly, decrement the third pointer k as long as the previous element is the same using while (j < k && nums[k] == nums[k - 1]) k--;.
Finally, move the second pointer j to the right and the third pointer k to the left.

Adjusting Pointers Based on Sum:
If sum < 0, it means the sum is too small, so we move the second pointer j to the right to increase the sum.
If sum > 0, it means the sum is too large, so we move the third pointer k to the left to decrease the sum.

Returning the Result:
After the loops finish, return sol; returns the 2D vector containing all unique triplets that sum to zero.
This method efficiently finds all unique triplets in the array that sum to zero, leveraging sorting and the two-pointer technique to avoid unnecessary calculations and duplicates
 */
