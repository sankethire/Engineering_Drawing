#include<stdio.h>
#include<iostream>
#include<vector>

class point{
	double point_arr[4];


  point(double coordinates[4]){
		point_arr[0] = coordinates[0];
		point_arr[1] = coordinates[1];
		point_arr[2] = coordinates[2];
		point_arr[3] = coordinates[3];
		}

  point(double p_x, double p_y, double p_z){
 			point_arr[0] = p_x; point_arr[1] = p_y; point_arr[2] = p_z; point_arr[3] = 1;
 		}




void translation(double x, double y)
		{
			double translation_matrix[3][3] = {{1,0,x},
			                                   {0,1,y},
					                           {0,0,1}};

			double sum[3] = {0,0,0};
			for(int i = 0;i<3;i++){
				for(int j=0;j<3;j++){
					sum[i] = sum[i] + translation_matrix[i][j] * point_arr[j];
				}
			}
		}

void scaling(double factor)
		{
			point_arr[0] = point_arr[0]*factor;
			point_arr[1] = point_arr[1]*factor;
		}



}