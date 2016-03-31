#include <iostream>
#include <cstdlib>
#include<ctime>
#include "Sudoku.h"

using namespace std;
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

void Sudoku::initialBoard(){
int i;
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
bool Sudoku:: checkRow(int r,int n){
int i;
for (i=0;i<9;i++){
if(data->map2[r][i]==n)return false;
}
return true;
}
bool Sudoku::checkCol(int c,int n){
	 int i;
	  for (i=0;i<9;i++){
	 if(data->map2[i][c]==n)return false;
	 }
	 return true;
	}
bool Sudoku::checkBlock(int x,int y,int n){
int i,j;
	for(i=x;i<x+3;i++){
	for(j=y;j<y+3;j++){
	if(data->map2[i][j]==n)return false;
	}
	}
return true;
}
bool Sudoku::check( int r,int c,int x,int y,int n){
return checkRow(r,n)&checkCol(c,n)&checkBlock(x,y,n);
}
unsigned short  Sudoku:: findZero(int x ){
unsigned short i;
for (i=x;i<81;i++){
if(data->map1[i]==0)return i;
}
return 81;
};
bool Sudoku::isZero(unsigned short n){
if(n!=81)return true;
else return false;
}

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
/*for(j=0;j<9;j++){        
	for(i=0;i<9;i++){
cout<<data->map2[j][i]<<' ';
}
cout<<'\n';
}

*/
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
 void Sudoku::solve(){
 int i,j,temp=0,x,y,bx,by;
 while(isZero(findZero(temp))){
 temp=findZero(temp);
	 for(i=1;i<=9;i++){
	 x=temp%9;
	 y=temp/9;
	 bx=x%3;
	 by=y%3;
	if(check(x,y,bx,by,i))
	{ data->map1[temp]=i;
	break;}

 }}
 for(i=0;i<9;i++){
 for(j=0;j<9;j++){
 cout<<data->map2[i][j]<<' ';
 }
 cout<<'\n';
 }
 };
