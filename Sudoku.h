#include <iostream>
#include<cstdlib>
#include<ctime>
#define UNASSIGNED 0
 

#define N 9
using namespace std;
class Sudoku {
		private:
				
			 void initialBoard();


			 bool SolveSudoku1(unsigned short grid[N][N]);
			  bool SolveSudoku2(unsigned short grid[N][N]);

			 bool FindUnassignedLocation(unsigned short grid[N][N], int &row, int &col);
			 bool UsedInRow(unsigned short grid[N][N], int row, int num);
			 bool UsedInCol(unsigned short grid[N][N], int col, int num);
			 bool UsedInBox(unsigned short grid[N][N], int boxStartRow, int boxStartCol, int num);
			 bool isSafe(unsigned short grid[N][N], int row, int col, int num);
			 unsigned short data[N][N];
			 unsigned short copy[N][N];
			bool equal(unsigned short grid1[N][N],unsigned short grid2[N][N]);


			 	public:
			 		 void readIn();
					 void giveQuestion();
					 void solve();
					 void changeNum(int a, int b);
					 void changeRow(int a, int b);
					 void changeCol(int a,int b);
					 void rotate(int n);
					 void flip(int n);
					 void transform();
};
