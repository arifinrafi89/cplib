#define ll long long

struct TrieNode {
    vector<TrieNode*> next;
    ll prefixCount;
    bool end;

    TrieNode() {
        next.assign(26, nullptr);
        prefixCount = 0;
        end = false;
    }

    ~TrieNode() {
        for (TrieNode* t : next) {
            delete t;
        }
    }

};

class Trie {
private:
    TrieNode* root;
    string prefixString;
    void print(TrieNode* cur, string &prefixString) {
        if (cur->end == true) {
            cout << prefixString << '\n';
        }
        for (ll i = 0; i < 26; i++) {
            if (cur->next[i] != nullptr) {
                prefixString += (char)(i + 'a');
                print(cur->next[i], prefixString);
                prefixString.pop_back();
            }
        }         
    }

public:

    Trie() {
        root = new TrieNode;
    }

    ~Trie() {
        delete root;
    }

    void insert(string &s) {
        TrieNode* cur = root;
        for (char &c : s) {
            if (cur->next[c - 'a'] == nullptr) {
                cur->next[c - 'a'] = new TrieNode;
            }
            cur = cur->next[c - 'a'];
            cur->prefixCount++;
        }
        cur->end = true;
    }

    bool search(string &s) {
        TrieNode* cur = root;
        for (char &c : s) {
            if (cur->next[c - 'a'] == nullptr) {
                return false;
            }
            cur = cur->next[c - 'a'];
        }
        return cur->end;
    }

    ll countPrefix(string &s) {
        TrieNode* cur = root;
        for (char &c : s) {
            if (cur->next[c - 'a'] == nullptr) {
                return 0;
            }
            cur = cur->next[c - 'a'];
        }
        return cur->prefixCount;
    }

    void print() {
        print(root, prefixString);
    }
};
