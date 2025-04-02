class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();
        vector<long long> first(n+1,0);
        for(int i=1;i<=n;i++){
            first[i] = (long long)skill[i-1]*(long long)mana[0];
            if(i>1){
                first[i]+=first[i-1];
            }
        }

        for(int i=1;i<m;i++){
            vector<long long> second(n+1,0);
            //initialize second
            for(int j=1;j<=n;j++){
                second[j] = (long long)skill[j-1]*(long long)mana[i];
                if(j>1){
                    second[j]+=second[j-1];
                }
            }


            //finding offset
            long long offset = INT_MIN;
            for(int j=1;j<=n;j++){
                long long diff = first[j]-second[j-1];
                offset = max(offset,diff);
            }

            for(int j=0;j<=n;j++){
                second[j]+=offset;
            }

            first = second;
        }

        return first[n];
    }
};