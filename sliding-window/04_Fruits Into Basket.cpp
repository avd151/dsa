/*
Question: Fruit Into Baskets
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.
You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.
Link: https://leetcode.com/problems/fruit-into-baskets/description/

*/

class Solution1 {
public:
    int totalFruit(vector<int>& fruits) {
        //longest subarray with atmost 2 types of elements
        //TC=O(2n), SC=O(3)
        int n = fruits.size();
        unordered_map<int,int>mp;
        int l = 0, r = 0, mxlen = 0;
        while(r < n){
            mp[fruits[r]]++;
            while(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            if(mp.size() <= 2){
                mxlen = max(mxlen, r-l+1);
            }
            r++;
        }
        return mxlen;
    }
};

class Solution2 {
public:
    int totalFruit(vector<int>& fruits) {
        //equivalent to longest subarray with atmost 2 types of elements
        //TC=O(n), SC=O(3)
        int n = fruits.size();
        unordered_map<int,int>mp;
        int l = 0, r = 0, mxlen = 0;
        while(r < n){
            mp[fruits[r]]++;
            if(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            if(mp.size() <= 2){
                mxlen = max(mxlen, r-l+1);
            }
            r++;
        }
        return mxlen;
    }
};