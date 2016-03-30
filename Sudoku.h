#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class Sudoku {
	private:
	union map {
   		unsigned short map1[81];
		unsigned short map2[9][9];
	};
	unsigned short findZero(int,int,int,int);
	bool check(int,int,int,int);
	bool checkRow(int);
	bool checkCol(int);
	bool checkBlock(int,int);
	unsigned short writeDigit(bool,unsigned short);
 union map* data;
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
