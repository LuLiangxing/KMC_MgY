#include <iostream>
#include <fstream>

#include "mgylib.h"
#include "eamlib.h"
#include "kmclib.h"
#include "common.h"
#include "mgykmc.h"

using namespace mgy;
using namespace eam;
using namespace kmc;
//using namespace mgykmc;

namespace mgykmc
{
	void runMGYKMC(MGYKMC_Input *mgykmc_input, MGYKMC_Output *mgykmc_output)
	{
		int step, max_steps, save_per_nsteps, frame = 0;
		double system_time = 0.;
		std::string fname;
		std::vector<double> system_energy, time_for_frames;
		
		MGY *mgy = new MGY(mgykmc_input);  // new mgy class
		EAM *eam = new EAM(mgy, mgykmc_input);  // new eam class
		KMC *kmc = new KMC(mgykmc_input);  // new kmc class
		
		print_vector(mgy->lattice_x, "../../bin/results/lattice_x.dat");
		print_vector(mgy->lattice_y, "../../bin/results/lattice_y.dat");
		print_vector(mgy->lattice_z, "../../bin/results/lattice_z.dat");
//		print_vector(mgy->elements, "../../bin/results/elements.dat");

		max_steps = mgykmc_input->max_steps;
		save_per_nsteps = mgykmc_input->save_per_nsteps;
		
		for (step=0; step<max_steps; step++)
		{
			system_energy.push_back(eam->syseng);
			
//			std::cout<<"step: "<<step<<", system time: "<<system_time<<std::endl;
			eam->PreparingKMC(mgy);
			eam->DoExchange(mgy, kmc->DoKMC_from_EAM(eam));
			
			system_time += kmc->dtime;
			
			if (step % save_per_nsteps == 0)
			{
				time_for_frames.push_back(system_time);
				fname = mgykmc_input->saveDir+"elements_"+"frame_"+std::to_string(frame)+".dat";
				std::cout<<"saving results to "<<fname<<std::endl;
				print_vector(mgy->elements, fname);
				frame++;
			}
		}


	}  // End of "runMGYKMC()"

}  // End of "mgykmc"
