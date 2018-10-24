#include <iostream>
#include <fstream>

#include "mgylib.h"
#include "eamlib.h"
#include "common.h"

using namespace mgy;
using namespace eam;

int main(void)
{
	MGY *mgy = new MGY("../../bin/input/kmc_mgy.inp");  // new mgy class
	EAM *eam = new EAM(mgy);
	
	std::cout<<"mgy->rr_type1.size(): "<<mgy->rr_type1.size()<<std::endl;
	
	std::cout<<"eam->roMg_nbs.size(): "<<eam->roMg_nbs.size()<<", eam->roMg_nbs[0].size(): "<<eam->roMg_nbs[0].size()<<std::endl;
	
	std::cout<<"total system energy: "<<eam->syseng<<std::endl;
	
	std::cout<<"num of vacancies: "<<eam->n_vacancy<<std::endl;
	for (int i=0; i<eam->n_vacancy; i++)
		std::cout<<"site of vacancy "<<i<<": "<<eam->site_vacancy[i]<<"\n";
	std::cout<<std::endl;
	
	std::cout<<"neighbour elements of vacancy 0:"<<std::endl;
	int ab = 1; 
	int sitv0 = eam->site_vacancy[0];
	int sumv0=0;
	for (int i=0; i < mgy->neighbours[sitv0].size(); i++)
	{
		sumv0 += mgy->elements[ mgy->neighbours[sitv0][i] ] - ab;
	}
	
	for (int i=0; i < mgy->nearest_neighbours[sitv0].size(); i++)
	{
		int sumv = 0;
		int sitev0nb = mgy->nearest_neighbours[sitv0][i];
		for (int j=0; j < mgy->neighbours[sitev0nb].size(); j++)
			sumv += mgy->elements[ mgy->neighbours[sitev0nb][j] ] - ab;
		std::cout<<sitv0<<", "<<sitev0nb<<", "<<sumv0<<", "<<sumv-2+ab<<std::endl;
	}
	
	if (eam->site_vacancy.size()>1)
	{
		int sitv1 = eam->site_vacancy[1];
		int sumv1=0;
		for (int i=0; i < mgy->neighbours[sitv1].size(); i++)
		{
			sumv1 += mgy->elements[ mgy->neighbours[sitv1][i] ] - ab;
		}
		
		for (int i=0; i < mgy->nearest_neighbours[sitv1].size(); i++)
		{
			int sumv = 0;
			int sitev1nb = mgy->nearest_neighbours[sitv1][i];
			for (int j=0; j < mgy->neighbours[sitev1nb].size(); j++)
				sumv += mgy->elements[ mgy->neighbours[sitev1nb][j] ] - ab;
			std::cout<<sitv1<<", "<<sitev1nb<<", "<<sumv1<<", "<<sumv-2+ab<<std::endl;
		}
	}
	std::cout<<"eam->charge_density.size(): "<<eam->charge_density.size()<<", eam->F_emb.size(): "<<eam->F_emb.size()<<std::endl;
	
	eam->listing_exchange(mgy);
	
	std::cout<<"eam->exchange_pair.size(): "<<eam->exchange_pair.size()<<std::endl;
	
	mgy->elements[eam->exchange_pair[0][1] ] = 2;
	eam->system_energy(mgy);
	eam->listing_exchange(mgy);
	
	for (int i=0; i<eam->exchange_pair.size(); i++)
		std::cout<<eam->exchange_pair[i][0]<<", "<<eam->exchange_pair[i][1]<<", "<<mgy->elements[eam->exchange_pair[i][1] ]<<std::endl;
		
	eam->energy_difference(mgy);
	eam->seaching_saddle();
	
	std::cout<<"eam->energy_exchanged.size(): "<<eam->energy_exchanged.size()<<std::endl;
	for (int i=0; i<eam->energy_exchanged.size(); i++)
		std::cout<<eam->energy_original[i]<<", "<<eam->energy_exchanged[i]<<", "<<eam->saddles_points[i]<<", "<<eam->energy_exchanged[i]-eam->energy_original[i]<<std::endl;
	
	eam->DoExchange(mgy, 0);
	
	double syseng0 = eam->syseng;
	eam->system_energy(mgy);
	std::cout<<"syseng0: "<<syseng0<<", eam->syseng: "<<eam->syseng<<", difference: "<<eam->syseng-syseng0<<std::endl;
	
	return(0);
	
}
