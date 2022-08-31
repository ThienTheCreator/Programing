/* 207. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are
given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course
bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have
finished course 1. So it is impossible. 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.

*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> um;
        
        for(int i = 0; i < prerequisites.size(); i++){
            um[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        unordered_set<int> visited;
        for(int i = 0; i < numCourses; i++){
            if(!dfs(um, visited, i))
                return false;
        }
        
        return true;
    }
    
    bool dfs(unordered_map<int, vector<int>>& um, unordered_set<int>& v, int n){
        if(v.find(n) != v.end())
            return false;
        
        if(um[n].empty())
            return true;
        
        v.insert(n);
        for(int i = 0; i < um[n].size(); i++){
            int x = um[n][i];
            if(!dfs(um, v, x)){
                return false;
            }
        }
        
        um[n].clear();
        v.erase(n);
        
        return true;
    }
};

/* Note

V is the vertex and E is the edges
Time: O(V + E)
Space: O(V + E)

Could not solve this question. I used a 2-d vector instead of a hashmap which made it difficult to
erase values when done. The solution creates a hashmap of a number connection to other numbers. Go
through and check if there is a cycle keeping track of the visited values. Delete the connection
with other number if we have checked it already.

*/