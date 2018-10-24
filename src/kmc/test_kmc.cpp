#include <iostream>
#include <vector>

#include "kmclib.h"

using namespace kmc;

int main(void)
{	
	int nevents, selected_event, i;
	double T, kb1, vibr_fre1;
	std::vector<double> energy_original, energy_exchange, saddles_points;
//	KMC *kmc;
	KMC *kmc = new KMC;  // new kmc class
	
	T=300.;
	kb1 = 1.;
	vibr_fre1 = 1.;
	nevents = 3;
	
	energy_original.resize(nevents);
	energy_exchange.resize(nevents);
	saddles_points.resize(nevents);
	
	for (i=0; i<nevents; i++)
		energy_original[i] = 0.;
	energy_exchange[0] = .1;
	energy_exchange[1] = .1;
	energy_exchange[2] = .1;
	saddles_points[0] = .12;
	saddles_points[1] = .12;
	saddles_points[2] = .12;
	
	std::cout<<"setting_temperature:"<<std::endl;
 	kmc->setting_parameters(T,kb1,vibr_fre1); 
	std::cout<<"listing_event:"<<std::endl;
 	kmc->listing_event(nevents);
	std::cout<<"setting_vibration_frequency:"<<std::endl;
 	kmc->setting_vibration_frequency();
	std::cout<<"setting_barrier_probability:"<<std::endl;
 	kmc->setting_barrier_probability(energy_original, energy_exchange, saddles_points);
	std::cout<<"selecting_event:"<<std::endl;
 	selected_event = kmc->selecting_event();
	
	std::cout<<"selected_event: "<<selected_event<<std::endl;

	return(0);	
}
