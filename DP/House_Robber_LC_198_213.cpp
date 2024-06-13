#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// //198 House Robber
// You are a professional robber planning to rob houses along a street. 
//Each house has a certain amount of money stashed, 
//the only constraint stopping you from robbing each of them is that 
//adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
// Given an integer array nums representing the amount of money of each house, 
//return the maximum amount of money you can rob tonight without alerting the police.
//
// Example 1:
//
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
//
// Example 2:
//
// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.

class Solution {
public:

    int solve(vector<int> &nums, int index, vector<int> &dp){
        if(index >= nums.size()){
            return 0;
        }

        // checking DP
        if(dp[index] != -1){
            return dp[index];
        }

        // robbed current house
        int robbed = nums[index] + solve(nums, index + 2,dp);
        int not_robbed = 0 + solve(nums, index + 1, dp);

        dp[index] = max(robbed, not_robbed) ;
        return dp[index];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0){
            return -1;
        }
        int index = 0;
        vector<int> dp(nums.size() + 1, -1);
        int ans = solve(nums, index, dp);

        return ans;
        
    }
};



//  213 -House Robber - 2
//  You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. 
//All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. 
//Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
//
// Example 1:
// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
//
// Example 2:
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

class Solution {
public:

    int solve(vector<int> &nums, int index, vector<int> &dp){
        if(index >= nums.size()){
            return 0;
        }

        // checking DP
        if(dp[index] != -1){
            return dp[index];
        }

        // robbed current house
        int robbed = nums[index] + solve(nums, index + 2,dp);
        int not_robbed = 0 + solve(nums, index + 1, dp);

        dp[index] = max(robbed, not_robbed) ;
        return dp[index];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
    
        int index = 0;
        vector<int> dp1(nums.size() + 1, -1);
        vector<int> dp2(nums.size() + 1, -1);

        dp1[nums.size()-1] = 0;
        int case1 = solve(nums,0, dp1);
        int case2 = solve(nums,1, dp2);
        
        return max(case1,case2);
        
    }
};