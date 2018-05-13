#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include "point_2D.h"

using namespace std;

class point_3D{

 double point_arr_3D[3];


  point_3D(double coordinates[3]){
		point_arr_3D[0] = coordinates[0];
		point_arr_3D[1] = coordinates[1];
		point_arr_3D[2] = coordinates[2];
		}

  point_3D(double p_x, double p_y){
 			point_arr_3D[0] = p_x; point_arr_3D[1] = p_y; point_arr_3D[2] = 1;
 		}




void translation(double x, double y, double z)
		{
			double translation_matrix[4][4] = {{1,0,0,x},
			                                   {0,1,0,y},
					                           {0,0,1,z}
					                           {0,0,0,1}};

			double sum[3] = {0,0,0,0};
			for(int i = 0;i<4;i++){
				for(int j=0;j<4;j++){
					sum[i] = sum[i] + translation_matrix[i][j] * point_arr_3D[j];
				}
			}
		}

void scaling(double factor)
		{
			point_arr_3D[0] = point_arr_3D[0]*factor;
			point_arr_3D[1] = point_arr_3D[1]*factor;
			point_arr_3D[2] = point_arr_3D[2]*factor;
		}

// t is angle here

void rotation_aboutX(double t){
	double rotation_matrix[4][4] = {{1,    0     ,       0     ,0},
									{1,cos(t),-1*sin(t),0},
									{1,sin(t),   cos(t),0},
									{0,    0     ,       0     ,1}};

		double sum[3] = {0,0,0,0};
			for(int i = 0;i<4;i++){
				for(int j=0;j<4;j++){
					sum[i] = sum[i] + rotation_matrix[i][j] * point_arr_3D[j];
				}
			}							
}

void rotation_aboutY(double t){
	double rotation_matrix[4][4] = {{cos(t) ,    0     ,sin(t) ,0},
									{0          ,    1     ,     0     ,0},
									{-sin(t),    0     ,cos(t) ,0},
									{0          ,    0     ,       0   ,1}};

		double sum[3] = {0,0,0,0};
			for(int i = 0;i<4;i++){
				for(int j=0;j<4;j++){
					sum[i] = sum[i] + rotation_matrix[i][j] * point_arr_3D[j];
				}
			}	
}

void rotation_aboutZ(double t){
	double rotation_matrix[4][4] = {{cos(t) ,-1*sin(t)          ,0 ,0},
									{sin(t) ,    cos(t)         ,0 ,0},
									{0      ,        0          ,1 ,0},
									{0      ,        0          ,0 ,1}};

		double sum[3] = {0,0,0,0};
			for(int i = 0;i<4;i++){
				for(int j=0;j<4;j++){
					sum[i] = sum[i] + rotation_matrix[i][j] * point_arr_3D[j];
				}
			}	
}

point xyProj(){point point = point(point_arr_3D[0],point_arr_3D[1]); return point;}
point yzProj(){point point = point(point_arr_3D[1],point_arr_3D[2]); return point;}
point xzProj(){point point = point(point_arr_3D[2],point_arr_3D[0]); return point;}

};



