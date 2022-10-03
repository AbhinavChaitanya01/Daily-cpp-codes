// ~~~~~~~~~~~~~~~~~~~~~~ 486. Predict the Winner  ~~~~~~~~~~~~~~~~~~~~~~~~`

// You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.
// Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. 
//The game ends when there are no more elements in the array.
// Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

class Solution {
public:
    int calculateScore(vector<int>& nums,int start, int end){
        if(start>end)return 0;
        if(start==end)return nums[end];
        int option1= nums[start]+min(calculateScore(nums,start+2,end),calculateScore(nums,start+1,end-1));
        int option2= nums[end]+min(calculateScore(nums,start+1,end-1),calculateScore(nums,start,end-2));
        return max(option1, option2);

    }
    bool PredictTheWinner(vector<int>& nums) {
        int player1Score=calculateScore(nums,0, nums.size()-1);
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        if(totalSum-player1Score>player1Score)return false;
        return true;
    }
};