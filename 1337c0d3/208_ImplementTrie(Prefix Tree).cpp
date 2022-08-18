/* 208. Implement Trie (Prefix Tree)

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and
retrieve keys in a dataset of strings. There are various applications of this data structure, such
as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie
(i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that
has the prefix prefix, and false otherwise.
 
Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 
Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.

*/

class Trie {
public:
    Trie() {
        
    }
    
    void insert(string word) {
        Trie* node = this;
        for(char c: word){
            if(!node->next.count(c))
                node->next[c] = new Trie();
            
            node = node->next[c];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char c: word){
            if(!node->next.count(c))
                return false;
            
            node = node->next[c];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char c: prefix){
            if(!node->next.count(c))
                return false;
            
            node = node->next[c];
        }
        
        return true;
    }
private:
    unordered_map<char, Trie*> next = {};
    bool isWord = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


/* Note

Time: insert O(n), search O(n), prefix O(n)
Space: insertO(n), search O(1), prefix O(1)

Could not solve in 20 minutes. Had to look at a solution to be able to code it out. I was thinking
of implementing a linked list but a hash map was easier and can be expanded to include other char.

The solution from neetcode was:

class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isWord = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        int curr = 0;
        
        for (int i = 0; i < word.size(); i++) {
            curr = word[i] - 'a';
            if (node->children[curr] == NULL) {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
        }
        
        node->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        int curr = 0;
        
        for (int i = 0; i < word.size(); i++) {
            curr = word[i] - 'a';
            if (node->children[curr] == NULL) {
                return false;
            }
            node = node->children[curr];
        }
        
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        int curr = 0;
        
        for (int i = 0; i < prefix.size(); i++) {
            curr = prefix[i] - 'a';
            if (node->children[curr] == NULL) {
                return false;
            }
            node = node->children[curr];
        }
        
        return true;
    }
private:
    TrieNode* root;
};

The solution made a node and use word[i] - 'a';

*/