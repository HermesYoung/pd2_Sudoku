#include <iostream>
class Sudoku {
	private:
		 unsigned short data[9][9];
	public:
		 void readIn();
		 void giveQuestion();
		 void solve();
		 void changeNum(int a, int b);
		 void changeRow(int a, int b);
		 void changeCol(int a,int b)
			 void rotate(int n);
		 void flip(int n);
		 void transform();



};
