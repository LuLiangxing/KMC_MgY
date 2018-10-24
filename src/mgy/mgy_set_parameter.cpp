#include <iostream>
#include <fstream>

#include "mgylib.h"
#include "mgykmc.h"

using namespace mgykmc;

namespace mgy 
{
	void MGY::set_parameter(std::string fname)
	{
		std::string instr;
		std::ifstream inFile;
		
//		fname = "../../bin/input/kmc_mgy.inp";

		std::cout<<"loading file: "<<fname<<std::endl;

		inFile.open(fname);
		if (!inFile) 
		{
			std::cout << "Unable to read input file: "<<fname;
			exit(1);   // call system to stop
		}
		
		inFile >> instr >> instr >> Nx;
		inFile >> instr >> instr >> Ny;
		inFile >> instr >> instr >> Nz;
		inFile >> instr >> instr >> lattice_a;
		inFile >> instr >> instr >> lattice_c;
		inFile >> instr >> instr >> rc_cut;
		inFile >> instr >> instr >> yat;
		inFile >> instr >> instr >> yat;
		inFile >> instr >> instr >> yat;
		inFile >> instr >> instr >> n_vacancy;
		
		Nxy = Nx*Ny;
		Nxyz = Nxy*Nz;
		
		std::cout<<"Nx: "<<Nx<<", Ny: "<<Ny<<", Nz: "<<Nz<<", Nxy: "<<Nxy<<", Nxyz: "<<Nxyz<<", lattice_a: "<<lattice_a<<", lattice_c: "<<lattice_c<<", rc_cut: "<<rc_cut<<", yat: "<<yat<<std::endl;		
		
		inFile.close();
		
	}   // End of "set_parameter"
	
	
	void MGY::set_parameter(MGYKMC_Input *mgykmc_input)
	{
		Nx = mgykmc_input->Nx;
		Ny = mgykmc_input->Ny;
		Nz = mgykmc_input->Nz;
		Nxy = Nx*Ny;
		Nxyz = Nxy*Nz;
		
		lattice_a =  mgykmc_input->lattice_a;
		lattice_c =  mgykmc_input->lattice_c;
		rc_cut =  mgykmc_input->rc_cut;
		yat =  mgykmc_input->yat;
		n_vacancy =  mgykmc_input->n_vacancy;
		
	}   // End of "set_parameter"
	
}  // End of "mgy"
