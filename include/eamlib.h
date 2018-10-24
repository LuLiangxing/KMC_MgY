#ifndef EAMLIB_H_
#define EAMLIB_H_

#include <iostream>
#include <vector>

#include "mgylib.h"
#include "mgykmc.h"

using namespace mgy;
using namespace mgykmc;

namespace eam
{	
	class EAM
	{
		public:
			EAM(MGY *mgy);
			EAM(MGY *mgy, MGYKMC_Input *mgykmc_input);
			virtual ~EAM()
			{}

			void interp_at_nbs(MGY *mgy);
			
			void read_raw_data();
			
			void system_energy(MGY *mgy);
			
			void listing_exchange(MGY *mgy);
			
			void energy_difference(MGY *mgy);
			
			double exchange_de(MGY *mgy, std::vector<int> &cpair);
			
			void density_change(MGY *mgy, std::vector<int> &cpair, std::vector<int> &nbs_all, std::vector<double> &change_density);
			
			void seaching_saddle();

			void PreparingKMC(MGY *mgy);
			
			void DoExchange(MGY *mgy, int selected_pair);


			double syseng;
			
			int n_vacancy, nthreads;
			
			std::vector<int> site_vacancy;
			
			std::vector<double> F_emb, charge_density;
			
			std::vector<std::vector<int> > exchange_pair;
			
			std::vector<double> energy_original, energy_exchanged, saddles_points;
			
			std::vector<double> eam_fitting_distance, eam_fitting_edensity, eam_FY, eam_FMg, eam_FMgY, eam_FMgMg, eam_FYY, eam_roMg, eam_roY;
		
			std::vector<std::vector<double> > roMg_nbs, roY_nbs, FMgY_nbs, FMgMg_nbs, FYY_nbs;
			
		private:
		
			
			
	};
	
	void read_data(std::string fname, std::vector<double> &store_vector);
	std::vector<double> interp1(std::vector<double> &x0, std::vector<double> &y0, std::vector<double> &x, std::string method);
	double interp1(std::vector<double> &x0, std::vector<double> &y0, double x, std::string method);

} /* namespace kmc */

#endif /* MGYLIB_H_ */




