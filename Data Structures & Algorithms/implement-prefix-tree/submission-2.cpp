class PrefixTree {
public:
    unordered_set<string> s;
    PrefixTree() {
    }
    
    void insert(string word) {
        s.insert(word);
    }
    
    bool search(string word) {
        return s.count(word);
    }
    
    bool startsWith(string prefix) {
        for (const string& w : s) {
            if (w.compare(0, prefix.size(), prefix) == 0) {
                return true;
            }
        }
        return false;
    }
};
