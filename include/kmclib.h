#ifndef KMCLIB_H_
#define KMCLIB_H_

#include <iostream>
#include <vector>

#include "eamlib.h"
#include "mgykmc.h"

using namespace eam;
using namespace mgykmc;

namespace kmc 
{	
	class KMC 
	{
		public:
			KMC();
			KMC(double T, double kb1, double vibr_fre1);
			KMC(MGYKMC_Input *mgykmc_input);
			virtual ~KMC()
			{}
			
			void setting_parameters(double T, double kb1, double vibr_fre1);

			void setting_parameters(MGYKMC_Input *mgykmc_input);
			
			void setting_Temperature(double T);

			void listing_event(int nevents1);
			
			void setting_barrier_probability(std::vector<double> &energy_original, std::vector<double> &energy_exchange, std::vector<double> &saddles_points);
			
			void setting_vibration_frequency();
			
			int selecting_event();
			
			int DoKMC_from_EAM(EAM *eam);

			double dtime;
			
//			std::vector<double> system_time;

		private:
			int nevents;
			double tot_probability, Temperature, kb, kbT, vibr_fre;
			std::vector<double> barriers, probabilities, probabilities_accumulate, vibration_frequencies;
			
	};
	
	double randu();

} /* namespace kmc */

#endif /* KMCLIB_H_ */




