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
}}}
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
unsigned short rot[9][9];
for(t=0;t<n;t++){
for(i=0;i<9;i++){
for(j=0;j<9;j++){
rot[i][j]=data[8-j][8-i];
}
}
for(i=0;i<9;i++){
for(j=0;j<9;j++){data[i][j]=rot[i][j];}}
flip(0);
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
for(i=0;i<9;i++){
for(j=0;j<9;j++){
cout<<data[i][j]<<' ';
}
cout<<endl;
}	
}
void Sudoku::giveQuestion(){
int i,n,j;
initialBoard();
srand(time(NULL));
n=rand()%81;
for(i=0;i<n;i++){
data[rand()%9][rand()%9]=0;
}
for(i=0;i<9;i++){
for(j=0;j<9;j++){
cout<<data[i][j]<<' ';
}
cout<<'\n';
}
return;}
bool Sudoku::SolveSudoku1(unsigned short grid[9][9]){
int r, c;
if (!FindUnassignedLocation(grid, r, c))
return true;
for (unsigned short num = 1; num <= 9; num++){
if (isSafe(grid, r, c, num)){
grid[r][c] = num;
if (SolveSudoku1(grid))
return true;
grid[r][c] = 0;
}
}
return false; 
}
bool Sudoku::SolveSudoku2(unsigned short grid[9][9]){
int r, c;
if (!FindUnassignedLocation(grid, r, c))
return true;
for (unsigned short num = 9; num >= 1; num--){
if (isSafe(grid, r, c, num)){
grid[r][c] = num;
if (SolveSudoku2(grid))
return true;
grid[r][c] = 0;
}
}
return false;}
bool Sudoku::FindUnassignedLocation(unsigned short grid[9][9], int& r, int& c){
for (r = 0; r< 9; r++)
for (c= 0; c < 9; c++)
if (grid[r][c] == 0)
return true;
return false;
}
bool Sudoku::UsedInRow(unsigned short grid[9][9], int r, int num){
for (int c = 0; c < N; c++)
if (grid[r][c] == num)
return true;
return false;
}
bool Sudoku::UsedInCol(unsigned short grid[9][9], int c, int num){
for (int r = 0; r< 9; r++)
if (grid[r][c] == num)
return true;
return false;
}
bool Sudoku::UsedInBox(unsigned short grid[9][9], int boxStartRow, int boxStartCol, int num){
for (int r = 0; r < 3; r++)
for (int c = 0; c < 3; c++)
if (grid[r+boxStartRow][c+boxStartCol] == num)
return true;
return false;
}
bool Sudoku::isSafe(unsigned short grid[9][9], int r, int c, int num){
 return !UsedInRow(grid, r, num) &&!UsedInCol(grid, c, num) &&!UsedInBox(grid, r - r%3 , c - c%3, num);
}
 bool Sudoku:: equal(unsigned short grid1[9][9],unsigned short grid2[9][9]){
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
