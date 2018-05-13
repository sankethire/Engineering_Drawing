#include<iostream>
#include<stdio.h>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){

vector<int> points;

fstream file;
int vertices;
string filename = "3D_vertices.txt";

file.open(filename.c_str());
while(file >> vertices){
	//cout << vertices ;
	points.push_back(vertices);

}
printf("%ld\n",points.size() );
for(int i =0;i<points.size();i = i+3){
	printf("%d %d %d\n",points[i],points[i+1],points[i+2] );
}

return 0;

}