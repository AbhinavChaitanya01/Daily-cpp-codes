// ~~~~~~~~~~~~~~~~~ 1578. Minimum Time to Make Rope Colorful ~~~~~~~~~~~~~~~~~~

// Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.
// Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.
// Return the minimum time Bob needs to make the rope colorful.

class Solution {
public:
    int removeTime(string &colors, int & idx, vector<int>& neededTime){
        int cost=0;
        int currMax=neededTime[idx];
        int i=idx+1;
        while(colors[idx]==colors[i]){
            if(neededTime[i]>currMax){
                cost+=currMax;
                currMax=neededTime[i];
            }
            else cost+=neededTime[i];
            i++;
        }
        idx=i-1;
        return cost;    
    }
    int minCost(string colors, vector<int>& neededTime) {
        int time=0;
        for(int i=0;i<colors.length();i++){
            time+=removeTime(colors, i, neededTime);
        }
        return time;
    }
};
 