//
// Created by Lucky_E on 2023-07-23.
//
#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int row, int col,vector<int>& placement)
{
    for(int i = 0; i < row; i++)
    {
        if(placement[i] == col||(abs(placement[i] - col)) == abs(i-row))
        {
            return false;
        }
    }
    return true;
}

void Solve(int row, int n,vector<vector<string>>& solutions,vector<int>& placement)
{
    if(row == n)
    {
        vector<string> solution(n,string(n,'.'));
        for(int i = 0; i < n; i++)
        {
            solution[i][placement[i]] = 'Q';
        }
        solutions.push_back(solution);
        return;
    }

    for(int col = 0; col < n; col++)
    {
        if(isSafe(row,col,placement))
        {
            placement[row] = col;
            Solve(row+1,n,solutions,placement);
            placement[row] = -1;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> solutions;
    vector<int> placement(n,-1);
    Solve(0,n,solutions,placement);
    return solutions;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> Solutions = solveNQueens(n);

    for(const auto& solution : Solutions)
    {
        for(const auto& row : solution)
        {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}