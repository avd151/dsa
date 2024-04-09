/* 
Question: Maximum Points You Can Obtain from Cards
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //TC=O(2*k)=O(k), SC=O(1)
        int n = cardPoints.size();
        int lSum = 0, rSum = 0, mxSum = 0;
        for(int i = 0; i < k; i++){
            lSum += cardPoints[i];
        }
        mxSum = lSum;
        int right = n-1;
        for(int i = k-1; i >= 0; i--){
            lSum = lSum - cardPoints[i];
            rSum = rSum + cardPoints[right];
            right = right - 1;
            mxSum = max(mxSum, lSum + rSum);
        }
        return mxSum;
    }
};