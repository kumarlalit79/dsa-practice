#include<iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;



class Rat_in_a_Maze
{

    private:

        // 3 condn jo hamne likhi thi : matrix ke andar,visited=0,m[k][l]=0 uska function hai
        bool isSafe(int x, int y, int n, vector<vector<int>>& visited,vector<vector<int>>& m){
            if ( (x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] ==0 && m[x][y] == 1)
            {
                return true;
                // in conditons pe jana safe hai to true return kar diya
            }
            else{
                return false;
            }
        }

        void solve(vector<vector<int>>& m, int n,vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path){

            // base case - aap destination pe pahuch chuke ho
            if (x == n-1 && y == n-1)
            {
                // ans mai path store karwao
                ans.push_back(path);
                return;
            }
            
            // RR
            // base case se bahar hoon means mai x,y pe pahuch chuka hoon
            visited[x][y] = 1;

            // 4 choice h mere pe : L, R, U, D

            // 1 -> down: down jane pe mujhe pata hai x,y cordinate change ho jate : x+1, y
            int new_x = x+1;
            int new_y = y;

            // check kr ra jana safe hai ya nahi : 3 condn jo hamne likhi thi : matrix ke andar,visited=0,m[k][l]=0. check above fn
            if (isSafe(new_x, new_y,n ,visited, m))
            {
                // jana safe hai , path mai include karlo
                path.push_back('D');
                // aage recursion sambhal lega RR call kardo
                solve(m , n , ans, new_x, new_y, visited, path);

                // backtrack
                path.pop_back(); // ye D ko pata dega path mai se
            }


            // 2 -> left: left jane pe mujhe pata hai x,y cordinate change ho jate : x, y-1
            new_x = x;
            new_y = y-1;            
            if (isSafe(new_x, new_y,n ,visited, m))
            {
                path.push_back('L');
                solve(m , n , ans, new_x, new_y, visited, path);
                path.pop_back(); 
            }

            // 3 -> right: right jane pe mujhe pata hai x,y cordinate change ho jate : x, y+1
            new_x = x;
            new_y = y+1;            
            if (isSafe(new_x, new_y,n ,visited, m))
            {
                path.push_back('R');
                solve(m , n , ans, new_x, new_y, visited, path);
                path.pop_back(); 
            }
            
            // 4 -> Up: Up jane pe mujhe pata hai x,y cordinate change ho jate : x-1, y
            new_x = x-1;
            new_y = y;            
            if (isSafe(new_x, new_y,n ,visited, m))
            {
                path.push_back('U');
                solve(m , n , ans, new_x, new_y, visited, path);
                path.pop_back(); 
            }

            // wapas jaoge to 0 mark kr dena, backtrack
            visited[x][y] = 0;
        }

    public:
        vector<string> findPath(vector<vector<int>> &m, int n){
        vector<string> ans;

        // agr src (0,0) pe hi 0 pada hua ho to return kardo
        if (m[0][0] == 0)
        {
            return ans;
        }
        

        int src_x = 0;
        int src_y = 0;

        // visited vector bana re or initilize kr re 0 se
        vector<vector<int>> visited = m;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                visited[i][j] = 0;        
            }
        }
        
        // path
        string path = "";
        solve(m , n , ans, src_x, src_y, visited, path);

        // jo answer aayga usko sort karna hai increasing order mai
        sort(ans.begin() , ans.end());
        return ans;
    }
};



int main() {
    // Example input
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    Rat_in_a_Maze solver;
    vector<string> paths = solver.findPath(maze, maze.size());

    if (paths.empty()) {
        cout << "No path found\n";
    } else {
        cout << "Possible paths:\n";
        for (auto &p : paths) {
            cout << p << "\n";
        }
    }

    return 0;
}