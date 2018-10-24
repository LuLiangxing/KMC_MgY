#ifndef MGYKMC_H_
#define MGYKMC_H_

#include <iostream>
#include <vector>

namespace mgykmc
{	
	class MGYKMC_Input
	{
		public:
			MGYKMC_Input(std::string fname);
			
			virtual ~MGYKMC_Input()
			{}
			
			void load_input(std::string fname);
			
			int Nx, Ny, Nz, n_vacancy;  // for periodical, Nx, Ny & Nz must be times of 2;
			double lattice_a, lattice_c, rc_cut, yat, Temp, kb, saddle_hight, vibr_fre;
			
			int max_steps, save_per_nsteps, nthreads;
			bool is_restart;
			std::string saveDir;
			
		private:
		
			
			
	};
	
	
	class MGYKMC_Output
	{
		public:
			MGYKMC_Output()
			{}
			virtual ~MGYKMC_Output()
			{}
			
			std::vector<double> system_energy;
			
		private:
		
			
			
	};
	
	
	void runMGYKMC(MGYKMC_Input *mgykmc_input, MGYKMC_Output *mgykmc_output);

} /* namespace mgykmc */

#endif /* MGYKMC_H_ */




