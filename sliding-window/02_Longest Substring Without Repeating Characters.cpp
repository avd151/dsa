/*
Question: Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without repeating characters.
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256, -1);
        int n = s.length();
        int l = 0, r = 0, mxLen = 0;
        while(r < n){
            if(hash[s[r]] != -1){
                //already occuring
                if(hash[s[r]] >= l){
                    l = hash[s[r]]+1;
                }
            }
            mxLen = max(mxLen, r-l+1);
            hash[s[r]] = r;
            r++;
        }
        return mxLen;
    }
};

