struct Node{
    Node *links[26];
    bool flag=false;
    bool containsKey(char ch){
        return (links[ch-'0']!=NULL);
    }

    void put(char ch, Node *node){
        links[ch-'0']=node;
    }

    Node *get(char ch){
        return links[ch-'0'];
    }

    void setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
    private: Node *root;
    public:
    Trie(){
        root=new Node();
    }

    void insert(string word){
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word){
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
    }

    int startWith(string prefix){
        Node *node=root;
        int cnt=0;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i])){
                break;
            }
            node=node->get(prefix[i]);
            cnt++;
        }
        return cnt;
    }
};


class Solution {
public:

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size();
        int n2=arr2.size();

        Trie t;
        for(int i=0;i<n1;i++){
            t.insert(to_string(arr1[i]));
        }
        int ans=0;
        for(int j=0;j<n2;j++){
            ans=max(ans,t.startWith(to_string(arr2[j])));
        }
        return ans;
    }
};