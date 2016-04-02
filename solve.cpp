#include <stdio.h>
#include "Sudoku.h"
void Sudoku::initialBoard(){
	int i;
	unsigned short initial_map[81]={
		1,2,3,4,5,6,7,8,9,
		4,5,6,7,8,9,1,2,3,
		7,8,9,1,2,3,4,5,6,
		2,1,4,3,6,5,8,9,7,
		3,6,5,8,9,7,2,1,4,
		8,9,7,2,1,4,3,6,5,
		5,3,1,6,4,2,9,7,8,
		6,4,2,9,7,8,5,3,1,
		9,7,8,5,3,1,6,4,2};
	for(i=0;i<81;i++){
		data->map1[i]=initial_map[i];
	}
};
void Sudoku:: readIn(){

	unsigned short temp,i;
	for (i=0;i<81;i++){
			cin>>temp;
				data->map1[i]=temp;
	}
};
void Sudoku::giveQuestion(){
	int i,n,j;
	initialBoard();
	srand(time(NULL));
	n=rand()%81;



	transform();
	for(i=0;i<n;i++){
		data->map1[rand()%81]=0;
	}
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			cout<<data->map2[i][j]<<' ';
		}
		         cout<<'\n';
				         }
	 };
 void Sudoku::changeNum(int a, int b){
	 	unsigned short temp,i;
			for(i=0;i<81;i++){
					if(data->map1[i]==a){
							data->map1[i]=b;
								}
						else if(data->map1[i]==b){
								data->map1[i]=a;
									}
							}
 };

void Sudoku::changeRow(int a, int b){
	unsigned short temp,i,j;
	int c=0,d=0;
	c=3*a;
	d=3*b;
	for(j=0;j<3;j++){
		for(i=0;i<9;i++){
				temp=data->map2[c+j][i];
					data->map2[c+j][i]=data->map2[d+j][i];
						data->map2[d+j][i]=temp;
		}
	}
};

void Sudoku::changeCol(int a,int b){
	unsigned short temp,i,j;
	int c=0,d=0;
	c=3*a;
	d=3*b;
	for(j=0;j<3;j++){
		for(i=0;i<9;i++){
			  temp=data->map2[i][c+j];
			    data->map2[i][c+j]=data->map2[i][d+j];
				  data->map2[i][d+j]=temp;
		}
	}

};
void Sudoku::flip(int n){
	unsigned short temp,i,j;
	if(n==0){
		for(j=0;j<9;j++){
			for(i=0;i<4;i++){
				temp=data->map2[i][j];
				data->map2[i][j]=data->map2[8-i][j];
				data->map2[8-i][j]=temp;

			}
		}
	}
	else{
		for(j=0;j<9;j++){
				for(i=0;i<4;i++){
							temp=data->map2[j][i];
									data->map2[j][i]=data->map2[j][8-i];
											data->map2[j][8-i]=temp;
												}
		}
	}
};

void Sudoku::rotate(int n){
	unsigned short temp,i,j;
	for(j=0;j<n;j++){
		for (i=0;i<40;i++){
			temp=data->map1[i];
			data->map1[i]=data->map1[80-i];
			data->map1[80-i]=temp;
		}
		flip(0);
	}
};



void Sudoku::transform(){
		int i,j;
			srand(time(NULL));
				changeNum(rand()%9+1,rand()%9+1);
					changeRow(rand()%3,rand()%3);
						changeCol(rand()%3,rand()%3);
							rotate(rand()%101);
								flip(rand()%2);
								//for print out transform result
								///*for(j=0;j<9;j++){        
								//	for(i=0;i<9;i++){
								//	cout<<data->map2[j][i]<<' ';
								//	}
								//	cout<<'\n';
								//	}
								//	*/
									};
bool Sudoku::SolveSudoku(unsigned short grid[N][N])
{
	    int row, col;
		 
		    if (!FindUnassignedLocation(grid, row, col))
				       return true;
			 
			    
			    for (unsigned short num = 1; num <= 9; num++)
					    {
							        
							        if (isSafe(grid, row, col, num))
										        {

													            grid[row][col] = num;
																 
																            
																            if (SolveSudoku(grid))
																				                return true;
																			 
																			            grid[row][col] = UNASSIGNED;
																						        }
									    }
				    return false; 
}
 

bool Sudoku::FindUnassignedLocation(unsigned short grid[N][N], int& row, int& col)
{
	    for (row = 0; row < N; row++)
			        for (col = 0; col < N; col++)
						            if (grid[row][col] == UNASSIGNED)
										                return true;
		    return false;
}
 

bool Sudoku::UsedInRow(unsigned short grid[N][N], int row, int num)
{
	    for (int col = 0; col < N; col++)
			        if (grid[row][col] == num)
						            return true;
		    return false;
}
 

bool Sudoku::UsedInCol(unsigned short grid[N][N], int col, int num)
{
	    for (int row = 0; row < N; row++)
			        if (grid[row][col] == num)
						            return true;
		    return false;
}
 

bool Sudoku::UsedInBox(unsigned short grid[N][N], int boxStartRow, int boxStartCol, int num)
{
	    for (int row = 0; row < 3; row++)
			        for (int col = 0; col < 3; col++)
						            if (grid[row+boxStartRow][col+boxStartCol] == num)
										                return true;
		    return false;
}
 

bool Sudoku::isSafe(unsigned short grid[N][N], int row, int col, int num)
{
	   
	    return !UsedInRow(grid, row, num) &&
			           !UsedInCol(grid, col, num) &&
					              !UsedInBox(grid, row - row%3 , col - col%3, num);
}
void Sudoku::solve(){
int i,j,c=0;
unsigned short temp[9][9];
for(i=0;i<9;i++){
	for(j=0;j<9;j++){
temp[i][j]=data->map2[i][j];
if(temp[i][j]!=0)c++;	}}
if(c<17){cout<<'2'<<endl;}
else{
	if(SolveSudoku(temp)){cout<<'1'<<endl;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
		cout<<temp[i][j]<<' ';
		}
cout<<endl;	}}
	else cout<<'0';
	
}} 
