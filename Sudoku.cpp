#include <iostream>
#include <cstdlib>
#include<ctime>
#include "Sudoku.h"

using namespace std;

void Sudoku::readIn(){
	unsigned short temp,i;
for (i=0;i<81;i++){
	cin>>temp;
	data->map1[i]=temp;
}
};

void Sudoku::giveQuestion(){};

void Sudoku::solve(){};

void Sudoku::changeNum(int a, int b){
	unsigned short temp,i;
	for(i=0;i<81;i++){
	if(data->map1[i]==a){
	data->map1[i]=b;
	}
	if(data->map1[i]==b){
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



void Sudoku::transform(){};
