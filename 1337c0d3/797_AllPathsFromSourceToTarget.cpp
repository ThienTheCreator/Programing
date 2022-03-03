/* 797. All Paths From Source to Target

Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

Example 1:


Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Example 2:


Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 

Constraints:

n == graph.length
2 <= n <= 15
0 <= graph[i][j] < n
graph[i][j] != i (i.e., there will be no self-loops).
All the elements of graph[i] are unique.
The input graph is guaranteed to be a DAG.

*/

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<vector<int>> tempVec;
        
        for(int i = 0; i < graph[0].size(); i++){
            res.push_back(vector<int>{0});
            res[i].push_back(graph[0][i]);
        }
        
        bool tf = true;
        
        while(tf){
            tf = false;
            vector<int> temp;
            for(int i = 0; i < res.size(); i++){
                if(res[i].back() == graph.size()-1){
                    tempVec.push_back(res[i]);
                }else{
                    int j = res[i].back();
                    for(int k = 0; k < graph[j].size(); k++){
                        temp = res[i];
                        temp.push_back(graph[j][k]);
                        tempVec.push_back(temp);
                    }
                    tf = true;
                }
            }
            res = tempVec;
            tempVec.clear();
        }
        
        return res;
    }
};

/* Note

I remember the solution to this problem is backtracking. I tried to implement a iterative solution
to solve the problem instead of recurive way. Iterative took some time to figure out the logic.

*/

