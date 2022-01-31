/* 535. Encode and Decode TinyURL

Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as 
https://leetcode.com/problems/design-tinyurl and it returns a short URL such as 
http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.

There is no restriction on how your encode/decode algorithm should work. 
You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL 
can be decoded to the original URL.

Implement the Solution class:

Solution() Initializes the object of the system.
String encode(String longUrl) Returns a tiny URL for the given longUrl.
String decode(String shortUrl) Returns the original long URL for the given 
shortUrl. It is guaranteed that the given shortUrl was encoded by the same 
object.
 

Example 1:

Input: url = "https://leetcode.com/problems/design-tinyurl"
Output: "https://leetcode.com/problems/design-tinyurl"

Explanation:
Solution obj = new Solution();
string tiny = obj.encode(url); // returns the encoded tiny url.
string ans = obj.decode(tiny); // returns the original url after deconding it.

*/
class Solution {
public:
    // 
    const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    
    unordered_map<string,string> LToS;
    unordered_map<string,string> SToL;
    
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string temp = "http://tinyurl.com/";
        for(int i = 0; i < 6; i++){
            temp += charset[rand() % charset.size()];
        }
        LToS[longUrl] = temp;
        SToL[temp] = longUrl;
        return temp;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return SToL[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

/* Note

I reimplement the solution again after looking at the solution because 
I did not do what the prompt state with tinyUrl. So we generated a tinyUrl for
every longUrl. The last 6 char of tinyUrl are randomly generated. The solution
use two unordered_map to store longUrl and shortUrl so we can retrive both 
types of url.  

*/