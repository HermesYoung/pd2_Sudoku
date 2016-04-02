#include <stdio.h>
#include<cstdlib>
#include<ctime>
#include "Sudoku.h"
using namespace std;
void Sudoku::initialBoard(){
		int i,j;
			unsigned short initial_map[9][9]={
				{1,2,3,4,5,6,7,8,9},
				{4,5,6,7,8,9,1,2,3},
				{7,8,9,1,2,3,4,5,6},
				{2,1,4,3,6,5,8,9,7},
				{3,6,5,8,9,7,2,1,4},
				{8,9,7,2,1,4,3,6,5},
				{5,3,1,6,4,2,9,7,8},
				{6,4,2,9,7,8,5,3,1},
				{9,7,8,5,3,1,6,4,2}};
				for(i=0;i<9;i++){
					for(j=0;j<9;j++){
							data[i][j]=initial_map[i][j];}
								}
				return;
}
void Sudoku:: readIn(){

		unsigned short temp,i,j;
			for (i=0;i<9;i++){
			 for(j=0;j<9;j++){ 
				cin>>temp;
				data[i][j]=temp;}
				}
return;}
void Sudoku::changeNum(int a, int b){
		unsigned short temp,i,j;
			for(i=0;i<9;i++){
			for(j=0;j<9;j++){
			if(data[i][j]==a){
			data[i][j]=b;
						}
						else if( data[i][j]==b){
								 data[i][j]=a;
									}
							}}
			return;
}
void Sudoku::changeRow(int a, int b){
	unsigned short temp,i,j;
	int c=0,d=0;
	c=3*a;
	d=3*b;
	for(j=0;j<3;j++){
		for(i=0;i<9;i++){
				temp=data[c+j][i];
					data[c+j][i]=data[d+j][i];
						data[d+j][i]=temp;
		}
	}
return;
}
void Sudoku::changeCol(int a,int b){
	unsigned short temp,i,j;
	int c=0,d=0;
	c=3*a;
	d=3*b;
	for(j=0;j<3;j++){
		for(i=0;i<9;i++){
			  temp=data[i][c+j];
			    data[i][c+j]=data[i][d+j];
				  data[i][d+j]=temp;
		}
	}
return;
}
void Sudoku::flip(int n){
	unsigned short temp,i,j;
	if(n==0){
		for(j=0;j<9;j++){
			for(i=0;i<4;i++){
				temp=data[i][j];
				data[i][j]=data[8-i][j];
				data[8-i][j]=temp;

			}
		}
	}
	else{
		for(j=0;j<9;j++){
		for(i=0;i<4;i++){
	temp=data[j][i];
	data[j][i]=data[j][8-i];
	data[j][8-i]=temp;
}
}
}
return;
}
void Sudoku::rotate(int n){
	unsigned short temp,i,j,t;
	for(t=0;t<n;t++){
	for(i=0;(i==4)&(j==4);i++){
	for(j=0;(i==4)&(j==4);j++){
	temp=data[i][j];
	data[i][j]=data[8-j][8-i];
	data[8-j][8-i]=temp;
	}
	}
	
	}
return;
}
void Sudoku::transform(){
		int i,j;
			srand(time(NULL));
				changeNum(rand()%9+1,rand()%9+1);
					changeRow(rand()%3,rand()%3);
						changeCol(rand()%3,rand()%3);
							rotate(rand()%101);
							flip(rand()%2);
								}
void Sudoku::giveQuestion(){
		int i,n,j;
			initialBoard();
				srand(time(NULL));
					n=rand()%81;
transform();
					for(i=0;i<n;i++){
										data[rand()%9][rand()%9]=0;
											}
								for(i=0;i<9;i++){
											for(j=0;j<9;j++){
															cout<<data[i][j]<<' ';
																	}
													         cout<<'\n';
															 				         }
				return;				 }
bool Sudoku::SolveSudoku1(unsigned short grid[N][N])
{
int row, col;
   if (!FindUnassignedLocation(grid, row, col))
					       return true;
					    for (unsigned short num = 1; num <= 9; num++)
							    {
						        if (isSafe(grid, row, col, num))
					        {
				            grid[row][col] = num;
		            if (SolveSudoku1(grid))
		                return true;
            grid[row][col] = UNASSIGNED;
				        }
					    }
			    return false; 
}
 bool Sudoku::SolveSudoku2(unsigned short grid[N][N])
 {
 int row, col;
  if (!FindUnassignedLocation(grid, row, col))
                         return true;
                        for (unsigned short num = 9; num >= 1; num--)
                               {
                                if (isSafe(grid, row, col, num))
                            {
                             grid[row][col] = num;
                     if (SolveSudoku2(grid))
                        return true;
             grid[row][col] = UNASSIGNED;
                        }
                         }
return false;}

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
 bool Sudoku:: equal(unsigned short grid1[N][N],unsigned short grid2[N][N]){
 int i,j;
 for(i=0;i<9;i++){for(j=0;j<9;j++){
 if(grid1[i][j]!=grid2[i][j])return false;
 }}
 return true;
 }
bool  Sudoku::check(){
int i,j;
unsigned short temp;
for(i=0;i<9;i++){
for(j=0;j<9;j++){
if(data[i][j]!=0){
temp=data[i][j];
copy[i][j]=0;
if(!isSafe(copy,i,j,temp)){
	data[i][j]=temp;	return false;}

else{data[i][j]=temp;}}
}}
return true;
}
void Sudoku::solve(){
	int i,j,c=0;
	for(i=0;i<9;i++){for(j=0;j<9;j++){
		copy[i][j]=data[i][j];
		copy2[i][j]=data[i][j];	
		if(data[i][j]!=0)c++;	}}
if(check()){	
	


			if(SolveSudoku1(copy2)&&SolveSudoku2(data)){
				if((c<17)||(!equal(copy2,data))){cout<<'2'<<endl;}
				else{cout<<'1'<<endl;
					for(i=0;i<9;i++){
								for(j=0;j<9;j++){
											cout<<data[i][j]<<' ';
													}
								cout<<endl;	}}}
				else cout<<'0';
}
else{cout<<'0';}

return;} 
