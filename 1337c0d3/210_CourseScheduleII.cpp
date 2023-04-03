/* 210. Course Schedule II

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are
given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course
bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid
answers, return any of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 
Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.

*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> um;

        for(int i = 0; i < prerequisites.size(); i++){
            um[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        unordered_set<int> visit;
        unordered_set<int> cycle;
        
        vector<int> res;
        
        for(int course = 0; course < numCourses; course++){
            if(!dfs(course, um, visit, cycle, res)){
                return {};
            }
        }

        return res; 
    }

    bool dfs(int course, unordered_map<int, vector<int>>& um, unordered_set<int>& visit, unordered_set<int>& cycle, vector<int>& res){

        if(cycle.find(course) != cycle.end()) {
            return false;
        }
        
        if(visit.find(course) != visit.end()){
            return true;
        }
        
        cycle.insert(course);
        for(int i = 0; i < um[course].size(); i++){
            int nextCourse = um[course][i];
            if(!dfs(nextCourse, um, visit, cycle, res)){
                return false;
            }
        }
        cycle.erase(course);
        visit.insert(course);
        res.push_back(course);

        return true;
    }
};

/* Note

V nodes and E Edges
Time: O(V + E) 
Space: O(V + E)

Was not able to sovle. The answer above is from neet code. Was stuck using a 2d vector instead of a
map to a vector. Did not know that the problem would require a dfs and how to implement it.

The solution involve keeping track of the visited course and the path taken or the cycle. 
Dfs to search for if there is a cycle for each course number. If there is a cycle than return false
and at the end return empty vector. If there is not a cycle then add path to the result vector. 

*/