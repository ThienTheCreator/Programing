/* 211. Design Add and Search Words Data Structure

Design a data structure that supports adding new words and finding if a string matches any
previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or
false otherwise. word may contain dots '.' where dots can be matched with any letter.

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 
Constraints:

1 <= word.length <= 25
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 3 dots in word for search queries.
At most 104 calls will be made to addWord and search.

*/

class TrieNode{
    public:
    TrieNode* next[26] = {NULL};
    bool isWord = false;
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char c: word){
            if(node->next[c - 'a'] == NULL)
                node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a']; 
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return helper(word, 0, root);
    }
    
    bool helper(string &word, int i, TrieNode* node){
        if(node == NULL)
            return false;
        
        if(i == word.size())
            return node->isWord;
        
        char c = word[i];
        if(c != '.'){
            return helper(word, i + 1, node->next[c - 'a']);
        }
        
        for(int j = 0; j < 26; j++){
            if(helper(word, i + 1, node->next[j]))
                return true;
        }
        
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


/* Note

Time: O(n^2)
Space: O(n)

Wasn't able to solve it within 20 minutes. Looked over neetcode solution to see because my solution
had some errors. The solution makes another class so I feel like the code is cleaner. Passing the
word by reference was faster than passing it by value. I thought I did not need to use the boolean
is word, but the problem checks to see if it is a value word not just if it is a prefix of a word.

Solution implements a trie and dfs.

*/