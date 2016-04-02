#include <iostream>
#include<cstdlib>
#include<ctime>
#define UNASSIGNED 0
 

#define N 9
using namespace std;
class Sudoku {
	private:
	union map {
   		unsigned short map1[81];
		unsigned short map2[9][9];
	};
int findZero();
bool haveZero();	
	bool check(int,int,int,int);
 unsigned short checkRow(int);
 unsigned short checkCol(int);
 unsigned short checkBlock(int,int);	
 void initialBoard();


bool SolveSudoku(unsigned short grid[N][N]);
bool FindUnassignedLocation(unsigned short grid[N][N], int &row, int &col);
bool UsedInRow(unsigned short grid[N][N], int row, int num);
bool UsedInCol(unsigned short grid[N][N], int col, int num);
bool UsedInBox(unsigned short grid[N][N], int boxStartRow, int boxStartCol, int num);
bool isSafe(unsigned short grid[N][N], int row, int col, int num);
union map* data;


unsigned short trackpoint;
 unsigned short copy[81];
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
