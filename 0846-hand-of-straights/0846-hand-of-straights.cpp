class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }

        for(auto it:mp){
            int val=it.first;
            int freq=it.second;
            for(int i=1;i<groupSize;i++){
                if(freq==0) continue;
                if(mp[val+i]>=freq){
                    mp[val+i]-=freq;
                    if(mp[val+i]==0){
                        mp.erase(val+i);
                    }
                }
                else return false;
            }
        }
        return true;

    }
};