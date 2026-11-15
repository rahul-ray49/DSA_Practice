class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int maxScore=0;

        int score=0;
        sort(tokens.begin(),tokens.end());

        int n=tokens.size();
        int i=0;
        int j=n-1;
        while(i<=j){
            if(power>=tokens[i]){
                score++;
                maxScore=max(maxScore,score);
                power=power-tokens[i];
                ++i;
            }
            else{
                if(score>=1){
                   score--;
                   power=power+tokens[j];
                   --j;
                }
                else{
                    break;
                }
                
            }
        }
        return maxScore;
    }
};