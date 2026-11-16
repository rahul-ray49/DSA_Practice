class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time=0;
        int idx=0;
        while(idx<colors.size()){
            char c=colors[idx];
            int adjacentSameColorballoonTimeremovaluSum=0;
            int maxTime=0;
            int adjacentSeriesCount=0;
            while(idx<colors.size()&&colors[idx]==c){
            adjacentSameColorballoonTimeremovaluSum+=neededTime[idx];
            maxTime=max(maxTime,neededTime[idx]);
            ++idx;   
            adjacentSeriesCount++;  
            }
            if(adjacentSeriesCount>1){
                time+=adjacentSameColorballoonTimeremovaluSum-maxTime;
            }

        }
        return time;
    }
};