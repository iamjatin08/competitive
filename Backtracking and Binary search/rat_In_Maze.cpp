#include <bits/stdc++.h>
using namespace std;

void printSolution(int** solution, int n){
	for(int i = 0 ; i<n ; i++){
		for(int j = 0 ; j<n ; j++){
			if(solution[i][j]) cout<<"+ ";
			else cout<<"_ ";
		}
		cout<<endl;
	}
	return;
}

void mazeHelper(int maze[4][4],int n , int** solution,int x, int y){
	if(x == n-1 and y == n-1) {
		solution[x][y] = 1;
		printSolution(solution,n);
		cout<<"-----------------"<<endl;
		return;
	}
	if(x>=n || x<0 || y>=n || y<0 || maze[x][y] == 0 || solution[x][y]==1)
	{
		return;
	}
	solution[x][y] = 1;
	mazeHelper(maze,n,solution,x-1,y);
	mazeHelper(maze,n,solution,x+1,y);
	mazeHelper(maze,n,solution,x,y-1);
	mazeHelper(maze,n,solution,x,y+1);
	solution[x][y] = 0;
}

void ratInMaze(int maze[4][4] , int n){
	int ** solution = new int*[n];
	for(int i = 0 ; i<n ; i++){
		solution[i] = new int[n];
		for(int j = 0 ; j<n ; j++){
			solution[i][j] = 0;
		} 
	}
	mazeHelper(maze,n,solution,0,0);
	for(int i = 0 ; i<n ; i++){
		delete [] solution[i];
	}
	delete []  solution;
	return;

}



int main(int argc, char const *argv[])
{
	int maze[4][4] = {
		{1,1,0,1},
		{0,1,1,1},
		{1,1,1,0},
		{1,0,1,1}
	};
	ratInMaze(maze,4);
	return 0;
}