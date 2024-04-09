/*
Question: Max Consecutive Ones III
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
Link: https://leetcode.com/problems/max-consecutive-ones-iii/

*/

class Solution1 {
public:
    int longestOnes(vector<int>& nums, int k) {
        //TC=O(2n), SC=O(1)
        int n = nums.size();
        int l = 0, r = 0, zero = 0, mxlen = 0;
        while(r < n){
            if(nums[r] == 0)
                zero++;
            while(zero > k){
                if(nums[l] == 0)
                    zero--;
                l++;
            }
            if(zero <= k){
                int len = r-l+1;
                mxlen = max(mxlen, len);
            }
            r++;
        }
        return mxlen;
    }
};

class Solution2 {
public:
    int longestOnes(vector<int>& nums, int k) {
        //TC=O(n), SC=O(1)
        int n = nums.size();
        int l = 0, r = 0, zero = 0, mxlen = 0;
        while(r < n){
            if(nums[r] == 0)
                zero++;
            if(zero > k){
                if(nums[l] == 0)
                    zero--;
                l++;
            }
            if(zero <= k){
                int len = r-l+1;
                mxlen = max(mxlen, len);
            }
            r++;
        }
        return mxlen;
    }
};