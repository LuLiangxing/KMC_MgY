#include <iostream>
#include <armadillo>
#include <vector>

#include "kmc.h"
#include "mgy.h"

using namespace kmc;
using namespace mgy;

int main()
{
	// loading parameters from input file:
	
	// initiallization:
	KMC *kmc = new KMC;  // new kmc class
	MgY *mgy = new MgY;  // new mgy class
	
	mgy->set_problem_size();  // read input file and set the crystal size: Ny * Nx * Nz
	
	// generating crystalline structure & neighbours:
	mgy->set_crystal_parameter();  // read input file and set crystal parameters: a=? c=?
	mgy->generate_structure();  // generating the hcp crystal with size: Ny * Nx * Nz
	mgy->generate_neighbour();  // generating the neighbours of each crystal site using periodical boundary
	mgy->generate_vacancies();  // generating the vacancies
	mgy->system_energy();  // calculting the system energy
	
	// kmc process:
	mgy->listing_exchange(mgy->vacancies, mgy->neighbours);  // listing all possible events based on current configuration
	mgy->geting_energy_difference(mgy->exchanges,mgy->neighbours);  // calculting the energy difference before and after each individual event
	mgy->seaching_saddle(mgy->exchanges,mgy->neighbours);  // searching saddle points for each event
	kmc->listing_event(mgy->exchanges.npairs());  // set the number of events
	kmc->setting_barrier(mgy->energy_differences,mgy->saddles);  // set the barrier for each event
	kmc->selecting_event(kmc->barriers, kmc->time); // do the kmc process and select only one event each time
	
	// updating MgY crystal:
	mgy->updating(kmc->slected_event, mgy->exchanges);
}
