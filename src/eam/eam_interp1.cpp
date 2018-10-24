#include <iostream>
#include <vector>
#include <fstream>

#include "eamlib.h"
#include "common.h"

namespace eam 
{
	 std::vector<double> interp1(std::vector<double> &x0, std::vector<double> &y0, std::vector<double> &x, std::string method)
	{
		int nx, nx0, i;
		double xx, yy;
		std::vector<double> y;
		
		nx = x.size();
		nx0 = x0.size();
//		y.resize(nx);
		
		for (i=0; i<nx; i++)
		{
			xx = x[i];
			if (xx<x0[0])
				yy = y0[0];
			else if (xx>x0[nx0-1])
				yy = y0[nx0-1];
			else
				yy = interpolation1(x0,y0,xx,method);
			y.push_back(yy);
		}
		
		return y;
		
	}  // End of "interp1()"
	
	
	double interp1(std::vector<double> &x0, std::vector<double> &y0, double x, std::string method)
	{
		int nx0;
		double y;
		
		nx0 = x0.size();

		if (x<x0[0])
			y = y0[0];
		else if (x>x0[nx0-1])
			y = y0[nx0-1];
		else
			y = interpolation1(x0,y0,x,method);
		
		return y;
		
	}  // End of "interp1()"
	
	
}  // End of "eam"



double interpolation1(std::vector<double> &x0, std::vector<double> &y0, double x, std::string method)
{
	int nx0, i;
	double y;
	
	nx0 = x0.size();
	
	for (i=0; i<nx0; i++)
	{
		if (x0[i] >= x)
			break;
	}
	
	if (method == "linear")
		y = (x - x0[i-1])/(x0[i] - x0[i-1])*(y0[i] - y0[i-1]) + y0[i-1];		
	else if (method == "cubic")
	{}
	  
	return y;
	 
}  // End of "interpolation1()"
