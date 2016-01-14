#include <iostream>
#include <limits.h>
using namespace std;

int MinPathCost(int rowpos, int colpos, int total);
int NumPaths(int rowpos, int colpos, int total);
int matrix[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
int totalPaths[4][4] = {-1, -1, -1, -1, -1, -1, -1, -1, -1,-1, -1, -1, -1, -1, -1, -1};
int MinCost[4][4] = {-1, -1, -1, -1, -1, -1, -1, -1, -1,-1, -1, -1, -1, -1, -1, -1};
int MAXROW = 4;
int MAXCOL = 4;

int main()
{
    for (size_t i=0; i<4; ++i)
    {
        for (size_t j=0; j<4; ++j)
        {
            cout << matrix[i][j];
        }
    }
    cout << "Enter Path total " << endl;
    int total = 0;
    cin >> total;
    int rowpos =0, colpos = 0;
    NumPaths(rowpos, colpos, total);
    cout << totalPaths[0][0] << endl;
    cout << "Min Path cost is " << MinPathCost(rowpos, colpos, 0) << endl;
    for (size_t i=0; i<4; ++i)
    {
        for (size_t j=0; j<4; ++j)
        {
            cout << "Total Paths from row " << i << " col " << j << " is " <<  totalPaths[i][j] << endl;
            cout << "Min Cost from row " << i << " col " << j << " is " <<  MinCost[i][j] << endl;
        }
    }
}

int NumPaths(int rowpos, int colpos, int total)
{
    if (total < 0 || rowpos == MAXROW || colpos == MAXCOL)
        return 0;
    if (total >= 0 && (rowpos == MAXROW-1) && colpos == MAXCOL-1)
        return 1;
    if (totalPaths[rowpos][colpos] != -1)
    {
        cout << "Returning from known value " << endl;
        return totalPaths[rowpos][colpos];
    }
    totalPaths[rowpos][colpos] = NumPaths(rowpos+1, colpos, total-matrix[rowpos][colpos])+
        NumPaths(rowpos, colpos+1, total-matrix[rowpos][colpos]);
    return totalPaths[rowpos][colpos];
}


int MinPathCost(int rowpos, int colpos, int total)
{
    if ((rowpos == MAXROW-1) && colpos == MAXCOL-1)
        return 0;
    if (MinCost[rowpos][colpos] != -1)
    {
        cout << "Returning from known value " << endl;
        return MinCost[rowpos][colpos];
    }
    if (rowpos == MAXROW-1)
        MinCost[rowpos][colpos] = matrix[rowpos][colpos] + MinPathCost(rowpos, colpos+1, total);
    else if (colpos == MAXCOL-1)
        MinCost[rowpos][colpos] = matrix[rowpos][colpos] + MinPathCost(rowpos+1, colpos, total);
    else
        MinCost[rowpos][colpos] = min(matrix[rowpos][colpos] + MinPathCost(rowpos+1, colpos, total),
         matrix[rowpos][colpos] + MinPathCost(rowpos, colpos+1, total));
    return MinCost[rowpos][colpos];
}
