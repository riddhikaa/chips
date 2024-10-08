/*
217. Contains Duplicate

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
Example 1:
Input: nums = [1,2,3,1]
output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Constraints:
1 <= nums.length <= 105
-109 <= nums[i] <= 109

*/
// my approach: this problem can be done without using STLs (map) 
// sort the input vector and compare the adjacent elements 
// time complexity: O(nlogn)
//space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end()); 
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]==nums[i+1]) return true;
                     
            }
            return false;
    }
};
