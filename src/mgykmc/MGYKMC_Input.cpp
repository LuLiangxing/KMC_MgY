#include <iostream>
#include <fstream>

#include "mgykmc.h"

namespace mgykmc 
{
	MGYKMC_Input::MGYKMC_Input(std::string fname)
	{
		load_input(fname);
	}
	
	
	void MGYKMC_Input::load_input(std::string fname)
	{
		std::string instr;
		std::ifstream inFile;
		
//		fname = "../../bin/input/kmc_mgy.inp";

		std::cout<<"loading input file: "<<fname<<std::endl;

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
		inFile >> instr >> instr >> saddle_hight;
		inFile >> instr >> instr >> vibr_fre;
		inFile >> instr >> instr >> yat;
		inFile >> instr >> instr >> n_vacancy;
		inFile >> instr >> instr >> Temp;
		inFile >> instr >> instr >> kb;
		inFile >> instr >> instr >> max_steps;
		inFile >> instr >> instr >> save_per_nsteps;
		inFile >> instr >> instr >> nthreads;
		inFile >> instr >> instr >> saveDir;
		
		is_restart = 0;
		
		inFile.close();
		
		std::cout<<"Nx: "<<Nx<<std::endl;
		std::cout<<"Ny: "<<Ny<<std::endl;
		std::cout<<"Nz: "<<Nz<<std::endl;
		std::cout<<"lattice_a: "<<lattice_a<<std::endl;
		std::cout<<"lattice_c: "<<lattice_c<<std::endl;
		std::cout<<"rc_cut: "<<rc_cut<<std::endl;
		std::cout<<"saddle_hight: "<<saddle_hight<<std::endl;
		std::cout<<"vibr_fre: "<<vibr_fre<<std::endl;
		std::cout<<"yat: "<<yat<<std::endl;
		std::cout<<"n_vacancy: "<<n_vacancy<<std::endl;
		std::cout<<"Temp: "<<Temp<<std::endl;
		std::cout<<"kb: "<<kb<<std::endl;
		std::cout<<"max_steps: "<<max_steps<<std::endl;
		std::cout<<"save_per_nsteps: "<<save_per_nsteps<<std::endl;

	}   // End of "loading_input"
	
}  // End of "mgykmc"
