// ~~~~~~~~~~~~~~~~~~~~  2416. Sum of Prefix Scores of Strings  ~~~~~~~~~~~~~~~~~~~~~
// ----------------------------- Using Tries --------------------------------
class Solution {
public:
    struct TrieNode
    {
        // Structure modification according to question
        TrieNode* child[26];
        int count;
        
        TrieNode()
        {
            for(int i=0;i<26;i++)
            {
                child[i]=NULL;
            }
            count=0;
        }
        
        
    };
    
    TrieNode* root = new TrieNode();
    
    void insert(string str)
    {
        TrieNode* curr=root;
        
        for(int i=0;i<str.size();i++)
        {
            int idx=str[i]-'a';
            
            if(curr->child[idx]==NULL)
            {
                curr->child[idx]=new TrieNode();
            }
            
            curr=curr->child[idx];
            curr->count++;
        }
    }
    
    int find(string str)
    {
        TrieNode* curr=root;
        
        int res=0;
        
        for(int i=0;i<str.size();i++)
        {
            int idx=str[i]-'a';
            if(curr->child[idx]==NULL)
            {
                break;
            }
            curr=curr->child[idx];
            res+=curr->count;
            
        }
        
        return res;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        
        for(auto x : words)
        {
            insert(x);
        }
        
        vector<int> res(words.size());
        
        for(int i=0;i<words.size();i++)
        {
            res[i]=find(words[i]);
        }
        
        return res;
    }
};