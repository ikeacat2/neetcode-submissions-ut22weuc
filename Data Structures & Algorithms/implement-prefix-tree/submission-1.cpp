class PrefixTree {
public:
    vector<string> v;
    PrefixTree() {
    }
    
    void insert(string word) {
        v.push_back(word);
    }
    
    bool search(string word) {
        for(string w : v) {
            if(w == word) {
                return true;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        for (string w : v) {
            if (w.substr(0, prefix.size()) == prefix) {
                return true;
            }
        }
        return false;
    }
};
