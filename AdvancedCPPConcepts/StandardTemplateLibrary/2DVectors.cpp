#include <iostream>
#include <vector>
using namespace std;

int main(){

    //outer vector is rows, 3
    //inner vector is a specific row which in iteself is a vector of size 4, each initialized to 0
    vector<vector<int>> grid(3, vector<int>(4, 7));

    grid[1].push_back(8);
    for(int row = 0; row<grid.size(); row++){
        for(int col = 0; col<grid[row].size(); col++){
            cout<<grid[row][col]<<" ";
        }
        cout<<endl;
    }
    return 0;


}