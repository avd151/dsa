/*
Question: Longest Substring with At Most K Distinct Characters
You are given a string 'str' and an integer ‘K’. Your task is to find the length of the largest substring with at most ‘K’ distinct characters.
For example:
You are given ‘str’ = ‘abbbbbbc’ and ‘K’ = 2, then the substrings that can be formed are [‘abbbbbb’, ‘bbbbbbc’]. Hence the answer is 7.
Link: https://www.naukri.com/code360/problems/longest-substring-with-at-most-k-distinct-characters_2221410
*/

int kDistinctChars(int k, string &str)
{
    //similar to longest subarray with atmost k unique characters
    //sliding window + maps
    //TC=O(n), SC=O(1)
    int n = str.size();
    int l = 0, r = 0, mxlen = 0;
    unordered_map<char, int>mp;
    while(r < n){
        mp[str[r]]++;
        if(mp.size() > k){
            mp[str[l]]--;
            if(mp[str[l]] == 0)
                mp.erase(str[l]);
            l++;
        }
        if(mp.size() <= k){
            mxlen = max(mxlen, r-l+1);
        }
        r++;
    }
    return mxlen;
}