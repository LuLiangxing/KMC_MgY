#include <iostream>
#include <fstream>

#include "mgylib.h"
#include "common.h"

using namespace mgy;

int main(void)
{
	MGY *mgy = new MGY("../../bin/input/kmc_mgy.inp");  // new mgy class
	
//	std::cout<<"size of neighbours: "<<mgy->neighbours.size()<<std::endl;
//	std::cout<<"neighbours number of site 0: "<<mgy->neighbours[0].size()<<std::endl;
//	std::cout<<"neighbours number of site 1: "<<mgy->neighbours[1].size()<<std::endl;
	
//	std::cout<<"distance to neighbours: \n";
//	for (int i=0; i<mgy->distance_nbs[0].size(); i++)
//	{
//		std::cout<<mgy->distance_nbs[0][i]<<", ";
//	}
//	std::cout<<std::endl;
	
//	std::cout<<"lattice_x.size(): "<<mgy->lattice_x.size()<<std::endl;
//	std::cout<<"lattice_y.size(): "<<mgy->lattice_y.size()<<std::endl;
//	std::cout<<"lattice_z.size(): "<<mgy->lattice_z.size()<<std::endl;
	
	print_vector(mgy->lattice_x, "lattice_x.dat");
	print_vector(mgy->lattice_y, "lattice_y.dat");
	print_vector(mgy->lattice_z, "lattice_z.dat");
	print_vector(mgy->elements, "elements.dat");
	std::cout<<"elements writen"<<std::endl;
	print_vector(mgy->sittype, "sittype.dat");
	std::cout<<"sittype writen"<<std::endl;
	print_vector(mgy->neighbours, "neighbours.dat");
	std::cout<<"neighbour.size(): "<<mgy->neighbours.size()<<std::endl;
	print_vector(mgy->nearest_neighbours, "nearest_neighbours.dat");
	std::cout<<"nearest_neighbour.size(): "<<mgy->nearest_neighbours.size()<<std::endl;
	std::cout<<"nearest_neighbour[0].size(): "<<mgy->nearest_neighbours[0].size()<<std::endl;
	
	return(0);
	
}
