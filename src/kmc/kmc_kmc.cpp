#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

#include "kmclib.h"
#include "eamlib.h"
#include "mgykmc.h"

using namespace eam;
using namespace mgykmc;

namespace kmc 
{
	KMC::KMC()
	{
	}
	
	KMC::KMC(double T, double kb1, double vibr_fre1)
	{
		setting_parameters(T,kb1,vibr_fre1);
	}
	
	KMC::KMC(MGYKMC_Input *mgykmc_input)
	{
		setting_parameters(mgykmc_input);
	}
	/////////////////////////////////////////////
	void KMC::setting_parameters(double T,double kb1, double vibr_fre1)
	{
		Temperature = T;
		kb = kb1;
		kbT = kb*Temperature;
		vibr_fre = vibr_fre1;
	}  // End of "setting_temperature"
	
	
	/////////////////////////////////////////////
	void KMC::setting_parameters(MGYKMC_Input *mgykmc_input)
	{
		
		Temperature = mgykmc_input->Temp;
		kb = mgykmc_input->kb;
		kbT = kb*Temperature;
		vibr_fre = mgykmc_input->vibr_fre;
	}  // End of "setting_temperature"
	
	
	/////////////////////////////////////////////
	void KMC::setting_Temperature(double T)
	{
		Temperature = T;
		kbT = kb*Temperature;
	}

	/////////////////////////////////////////////
	void KMC::listing_event(int nevents1)
	{
		nevents = nevents1;
		barriers.resize(nevents);
		probabilities.resize(nevents);
		probabilities_accumulate.resize(nevents+1);
		vibration_frequencies.resize(nevents);
	}  // End of "listing_event"
	
	
	/////////////////////////////////////////////
	void KMC::setting_vibration_frequency()
	{
		for (int i=0; i<nevents; i++)
			vibration_frequencies[i] = vibr_fre;
	}
	
	
	/////////////////////////////////////////////
	void KMC::setting_barrier_probability(std::vector<double> &energy_original, std::vector<double> &energy_exchanged, std::vector<double> &saddles_points)
	{
		int i;
		
		tot_probability = 0.;
		for (i=0;i<nevents;i++)
		{
			if (saddles_points[i] >= energy_exchanged[i])
				barriers[i] = saddles_points[i] - energy_original[i];
			else
				barriers[i] = energy_exchanged[i] - energy_original[i];
			
			probabilities[i] = std::exp(-barriers[i]/kbT) * vibration_frequencies[i];
			tot_probability += probabilities[i];
		}
		
		for (i=0;i<nevents;i++)
			probabilities[i] /= tot_probability;
		
		probabilities_accumulate[0] = 0.;
		for (i=1;i<nevents;i++)
			probabilities_accumulate[i] = probabilities_accumulate[i-1] + probabilities[i-1];
		probabilities_accumulate[nevents] = 1.;
		
		dtime = -std::log(randu())/tot_probability;	
		
//		std::cout<<"barriers:"<<std::endl;
//		for (i=0;i<nevents;i++)
//			std::cout<<"["<<i<<"]: "<<barriers[i]<<" ";
//		std::cout<<std::endl;
//		std::cout<<"probabilities:"<<std::endl;
//		for (i=0;i<nevents;i++)
//			std::cout<<"["<<i<<"]: "<<probabilities[i]<<" ";
//		std::cout<<std::endl;
//		std::cout<<"probabilities_accumulate:"<<std::endl;
//		for (i=0;i<=nevents;i++)
//			std::cout<<"["<<i<<"]: "<<probabilities_accumulate[i]<<" ";
//		std::cout<<std::endl;
//		std::cout<<"dtime: "<<dtime<<std::endl;
		
	}  // End of "setting_barrier_probability"
	
	
	/////////////////////////////////////////////
	int KMC::selecting_event()
	{
		int i;
		double rr;
		
		rr = randu();
		for (i=1; i<=nevents;i++)
		{
			if (rr <= probabilities_accumulate[i])
				break;
		}
		
		return i-1;
		
	}  // End of "selecting_event"
	
	
	/////////////////////////////////////////////
	int KMC::DoKMC_from_EAM(EAM *eam)
	{
		listing_event(eam->exchange_pair.size());
		
		setting_vibration_frequency();
		
		setting_barrier_probability(eam->energy_original, eam->energy_exchanged, eam->saddles_points);
		
//		system_time += dtime;

		return selecting_event();
		
	}  // End of "DoKMC_from_EAM"
	
	
	/////////////////////////////////////////////
	double randu()
	{
		std::srand ( time(NULL) ); //initialize the random seed
		return std::rand()/(double)RAND_MAX;
	}  // End of "randu"
	
}  // End of "am"
	
