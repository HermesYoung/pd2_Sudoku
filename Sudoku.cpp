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
unsigned short  Sudoku:: findZero(int x1 ,int y1,int x2,int y2){
int i,j;
for (i=x1;i<=x2;i++){
for (j=y1;j<=y2;j++){
if(data->map2[i][j]==0){return i*9+j;}

}
}
return 81;
};

bool Sudoku:: checkRow(int r){
int i;
unsigned short checker,temp=0x0000;
for (i=0;i<9;i++){
switch(data->map2[r][i]){
	case 0:checker=0x0001;break;
	case 1:checker=0x0002;break;
	case 2:checker=0x0004;break;
	case 3:checker=0x0008;break;
	case 4:checker=0x0010;break;
	case 5:checker=0x0020;break;
	case 6:checker=0x0040;break;
	case 7:checker=0x0080;break;
	case 8:checker=0x0100;break;
	case 9:checker=0x0200;break;
	default:checker=0x0001;break;

}
temp=temp|checker;
}
if(temp==0x0ffe)return true;
else return false;
};
bool Sudoku:: checkCol(int c){
int i;
unsigned short checker,temp=0x0000;
for (i=0;i<9;i++){
switch(data->map2[i][c]){
case 0:checker=0x0001;break;
case 1:checker=0x0002;break;
case 2:checker=0x0004;break;
case 3:checker=0x0008;break;
case 4:checker=0x0010;break;
case 5:checker=0x0020;break;
case 6:checker=0x0040;break;
case 7:checker=0x0080;break;
case 8:checker=0x0100;break;
case 9:checker=0x0200;break;
default:checker=0x0001;break;
}
temp=temp|checker;
}
if(temp==0x0ffe)return true;
else return false;

};
bool Sudoku:: checkBlock(int bx,int by){
	unsigned short map_temp[9];
	unsigned short checker,temp=0x0000;
	int i,j,k=0;
	for(j=by*3;j<by*3+3;j++){
	for(i=bx*3;i<bx*3+3;i++){
	 map_temp[k] =data->map2[j][i];
	k++;
	}
	}
for (i=0;i<9;i++){
switch(map_temp[i]){
case 0:checker=0x0001;break;
case 1:checker=0x0002;break;
case 2:checker=0x0004;break;
case 3:checker=0x0008;break;
case 4:checker=0x0010;break;
case 5:checker=0x0020;break;
case 6:checker=0x0040;break;
case 7:checker=0x0080;break;
case 8:checker=0x0100;break;
case 9:checker=0x0200;break;
default:checker=0x0001;break;
						  }
		   temp=temp|checker;
	 }
	  if(temp==0x0ffe)return true;
	   else return false;

};
bool Sudoku:: check(int r,int c,int bx,int by ){
	return checkRow(r)& checkCol(c)& checkBlock(bx,by);
};

unsigned short writeDigit(bool c,unsigned short){};


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



void Sudoku::transform(){
	int i,j;
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
for(j=0;j<9;j++){
	for(i=0;i<9;i++){
cout<<data->map2[j][i]<<' ';
}
cout<<'\n';
}


};
void Sudoku::giveQuestion(){
int i,n,j;

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
 void Sudoku::solve(){};

