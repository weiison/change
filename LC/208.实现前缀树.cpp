class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        for(int i=0;i<26;++i)
            Node[i]=nullptr;
        isend=false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* now=this;
        for(auto ch:word)
        {
            int idx=ch-'a';
            if(now->Node[idx]==nullptr) now->Node[idx]=new Trie();
            now=now->Node[idx];
        }
        now->isend=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* now=this;
        for(auto ch:word)
        {
            int idx=ch-'a';
            if(now->Node[idx]==nullptr) return false;
            now=now->Node[idx];
        }
        return now->isend;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* now=this;
        for(auto ch:prefix)
        {
            int idx=ch-'a';
            if(now->Node[idx]==nullptr) return false;
            now=now->Node[idx];
        }
        return true;
    }
private:
    Trie* Node[26];
    bool isend;
};
