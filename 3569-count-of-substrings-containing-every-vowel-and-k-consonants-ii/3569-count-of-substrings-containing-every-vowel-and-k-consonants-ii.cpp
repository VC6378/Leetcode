class Solution {
public:

    bool isVowel(char ch){
        if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u') return true;
        return false;
    }

    long long f(string word,int k){
        int n=word.size();
        int consonants=0;
        int left=0;
        unordered_map<char,int> mp;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(isVowel(word[i])){
                mp[word[i]]++;
            }
            else{
                consonants++;
            }

            while(mp.size()==5 && consonants>=k){
                ans+=n-i;
                if(isVowel(word[left])){
                    mp[word[left]]--;
                    if(mp[word[left]]==0){
                        mp.erase(word[left]);
                    }
                }
                else{
                    consonants--;
                }
                left++;
            }
        }
        return ans;
    }

    long long countOfSubstrings(string word, int k) {
        return f(word,k)-f(word,k+1);
    }
};