#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <fstream>

#include "mgylib.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////
void print_vector(std::vector<double> &vec, std::string fname)
{
	std::ofstream outFile;
	
	outFile.open(fname);
	
	int sizevec = vec.size();
	
	for (int i=0; i<sizevec; i++)
		outFile<<vec[i]<<"\n";
	
	outFile.close();
	
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
void print_vector(std::vector<int> &vec, std::string fname)
{
	std::ofstream outFile;
	
	outFile.open(fname);
	
	int sizevec = vec.size();
	
	for (int i=0; i<sizevec; i++)
		outFile<<vec[i]<<"\n";
	
	outFile.close();
	
};


////////////////////////////////////////////////////////////////////////////////////////////////////////
void print_vector(std::vector<std::vector<int> > &mat, std::string fname)
{
	int sizemat, sizevec, i, j;
	std::ofstream outFile;
	
	outFile.open(fname);
	
	sizemat = mat.size();
	
	for (i=0; i<sizemat; i++)
	{
		sizevec = mat[i].size();
		for (j=0; j<sizevec; j++)
			outFile<<mat[i][j]<<" ";
		outFile<<"\n";
	}
		
	outFile.close();
	
};


////////////////////////////////////////////////////////////////////////////////////////////////////////
void print_vector(std::vector<std::vector<double> > &mat, std::string fname)
{
	int sizemat, sizevec, i, j;
	std::ofstream outFile;
	
	outFile.open(fname);
	
	sizemat = mat.size();
	
	for (i=0; i<sizemat; i++)
	{
		sizevec = mat[i].size();
		for (j=0; j<sizevec; j++)
			outFile<<mat[i][j]<<" ";
		outFile<<"\n";
	}
		
	outFile.close();
	
};
