/* 950. Reveal Cards In Increasing Order

You are given an integer array deck. There is a deck of cards where every card has a unique
integer. The integer on the ith card is deck[i].

You can order the deck in any order you want. Initially, all the cards start face down (unrevealed)
in one deck.

You will do the following steps repeatedly until all cards are revealed:

Take the top card of the deck, reveal it, and take it out of the deck.
If there are still cards in the deck then put the next top card of the deck at the bottom of the
deck. If there are still unrevealed cards, go back to step 1. Otherwise, stop.
Return an ordering of the deck that would reveal the cards in increasing order.

Note that the first entry in the answer is considered to be the top of the deck.

Example 1:

Input: deck = [17,13,11,2,3,5,7]
Output: [2,13,3,11,5,17,7]
Explanation: 
We get the deck in the order [17,13,11,2,3,5,7] (this order does not matter), and reorder it.
After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is the top of the deck.
We reveal 2, and move 13 to the bottom.  The deck is now [3,11,5,17,7,13].
We reveal 3, and move 11 to the bottom.  The deck is now [5,17,7,13,11].
We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
We reveal 13, and move 17 to the bottom.  The deck is now [17].
We reveal 17.
Since all the cards revealed are in increasing order, the answer is correct.

Example 2:

Input: deck = [1,1000]
Output: [1,1000]
 
Constraints:

1 <= deck.length <= 1000
1 <= deck[i] <= 106
All the values of deck are unique.

*/

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        
        deque<int> d;
        d.push_back(deck[deck.size()-1]);
        
        for(int i = deck.size()-2; i >= 0; i--){
            d.push_front(d.back());
            d.pop_back();
            d.push_front(deck[i]);
        }
        
        vector<int> res(d.begin(), d.end());
        return res;
    }
};

/* Note

Could not solve this problem need to look over it again.

The solution below is from lee215:
https://leetcode.com/problems/reveal-cards-in-increasing-order/discuss/200515/JavaC%2B%2BPython-Simulate-the-Reversed-Process

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.rbegin(),deck.rend());
        
        deque<int> d;
        d.push_back(deck[0]);
        for(int i = 1; i < deck.size(); i++){
            d.push_front(d.back());
            d.pop_back();
            d.push_front(deck[i]);
        }
        
        vector<int> res(d.begin(), d.end());
        return res;
    }
};

The solution below is from votrubac:
https://leetcode.com/problems/reveal-cards-in-increasing-order/discuss/201574/C%2B%2B-with-picture-skip-over-empty-spaces

vector<int> deckRevealedIncreasing(vector<int>& deck) {
  sort(begin(deck), end(deck));
  vector<int> res(deck.size(), 0);
  res[0] = deck[0];
  for (auto i = 1, p = 0; i < deck.size(); ++i) {
    for (auto j = 0; j < 2; p %= res.size(), j += (res[p] == 0 ? 1 : 0)) ++p;
    res[p] = deck[i];
  }
  return res;
}

vector<int> deckRevealedIncreasing(vector<int>& deck) {
  sort(begin(deck), end(deck));
  list<int> l(deck.size());
  iota(begin(l), end(l), 0);    
  vector<int> res(deck.size());
  auto lp = l.begin();
  for (int i = 0, skip = 0; !l.empty(); skip = !skip) {
      if (lp == l.end()) lp = l.begin();
      if (skip) ++lp;
      else {
          res[*lp] = deck[i++];
          l.erase(lp++);
      }
  }
  return res;
}

The solution works by doing the instructions backwards.
Sort the array.
Start with the highest number and implement the algorithm backwards 2->1->3. 

*/