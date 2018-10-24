#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

#include "mgylib.h"

namespace mgy 
{
	MGY::MGY(std::string fname)
	{
		std::cout<<"Creating new MGY class"<<std::endl;
		std::cout<<"before loading parameters, Nx: "<<Nx<<", Ny: "<<Ny<<", Nz: "<<Nz<<", Nxy: "<<Nxy<<", Nxyz: "<<Nxyz<<std::endl;
		set_parameter(fname);
		std::cout<<"MGY: parameters loaded"<<std::endl;
		std::cout<<"after loading parameters and beofre generating structure, Nx: "<<Nx<<", Ny: "<<Ny<<", Nz: "<<Nz<<", Nxy: "<<Nxy<<", Nxyz: "<<Nxyz<<std::endl;
		generate_structure();
		std::cout<<"MGY: structure generated"<<std::endl;
		std::cout<<"after generating structure and before generating neighbours, Nx: "<<Nx<<", Ny: "<<Ny<<", Nz: "<<Nz<<", Nxy: "<<Nxy<<", Nxyz: "<<Nxyz<<std::endl;
		generate_neighbour();
		std::cout<<"MGY: neighbours generated"<<std::endl;
		std::cout<<"after generating neighbours, Nx: "<<Nx<<", Ny: "<<Ny<<", Nz: "<<Nz<<", Nxy: "<<Nxy<<", Nxyz: "<<Nxyz<<std::endl;
		generate_nearest_neighbour();
		std::cout<<"MGY: nearest neighbours generated"<<std::endl;
		std::cout<<"after generating neighbours, Nx: "<<Nx<<", Ny: "<<Ny<<", Nz: "<<Nz<<", Nxy: "<<Nxy<<", Nxyz: "<<Nxyz<<std::endl;
		std::cout<<"new MGY class created"<<std::endl;
		
	}
	


	MGY::MGY(MGYKMC_Input *mgykmc_input)
	{
		set_parameter(mgykmc_input);
		generate_structure();
		generate_neighbour();
		generate_nearest_neighbour();
	}
}
