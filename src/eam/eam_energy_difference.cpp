#include <iostream>
#include <vector>
#include <omp.h>
#include <fstream>

#include "eamlib.h"
#include "mgylib.h"

namespace eam 
{
	 void EAM::energy_difference(MGY *mgy)
	{
		int n_pair, i;
		
//		std::vector<double> energy_pair(2);
		
		n_pair = exchange_pair.size();
		energy_original.resize(n_pair);
		energy_exchanged.resize(n_pair);
		
		#pragma omp parallel for private(i) num_threads(nthreads)
		for (i=0; i<n_pair; i++)
		{
			energy_original[i] = syseng;
			
			energy_exchanged[i] = syseng + exchange_de(mgy, exchange_pair[i]);
		}
		
		
	}  // End of "energy_difference()"
	
	
	
	////////////////////////////////////////////////////////////////
	double EAM::exchange_de(MGY *mgy, std::vector<int> &cpair)
	{
		int i, n_nbs, nb, site_v, site_e, element_e, element_nb, sittype;
		double de, eng_emb, edensity;
		std::string method;
		std::vector<int> nbs_all;
		std::vector<double> change_density;
		
		method = "linear";
		
		site_v = cpair[0];
		site_e = cpair[1];
		element_e = mgy->elements[site_e];
		
		de = 0.;
		
		// cuting links between the exchanged atom with it's current neighbours
		n_nbs = mgy->neighbours[site_e].size();
		sittype = mgy->sittype[site_e]-1;
		for (i=0; i<n_nbs; i++)
		{
			nb = mgy->neighbours[site_e][i];
			// deducting pair-wise potential:
			element_nb = mgy->elements[nb];
			if (element_nb != 2)
			{
				switch (element_e+element_nb)
				{
					case 0:  // Mg-Mg
						de -= FMgMg_nbs[sittype][i];
						break;
					case 1:  // Mg-Y or Y-Mg
						de -= FMgY_nbs[sittype][i];
						break;
					case 2:  // Y-Y
						de -= FYY_nbs[sittype][i];
						break;
				}
			}
		}
		
		// creating new links between the exchanged atom with it's new neighbours
		n_nbs = mgy->neighbours[site_v].size();
		sittype = mgy->sittype[site_v]-1;
		for (i=0; i<n_nbs; i++)
		{
			nb = mgy->neighbours[site_v][i];
			if (nb != site_e)
			{
				// adding new pair-wise potential:
				element_nb = mgy->elements[nb];
				if (element_nb != 2)
				{
					switch (element_e+element_nb)
					{
						case 0:  // Mg-Mg
							de += FMgMg_nbs[sittype][i];
							break;
						case 1:  // Mg-Y or Y-Mg
							de += FMgY_nbs[sittype][i];
							break;
						case 2:  // Y-Y
							de += FYY_nbs[sittype][i];
							break;
					}
				}
			}
		}
		
		// energy changing caused by change of charge density
		density_change(mgy, cpair, nbs_all, change_density);

		n_nbs = nbs_all.size();
		for (i=0; i<n_nbs; i++)
		{
			nb = nbs_all[i];
			edensity = charge_density[nb] + change_density[i];
			
			if (nb == site_e)
			{
				de -= F_emb[site_e];
			}
			else if (nb == site_v)
			{
				switch (element_e)
				{
					case 0:  // Mg
						de += interp1(eam_fitting_edensity, eam_FMg, edensity, method);
						break;
					case 1:  // Y
						de += interp1(eam_fitting_edensity, eam_FY, edensity, method);
						break;
				}
			}
			else
			{
				element_nb = mgy->elements[nb];
				switch (element_nb)
				{
					case 0:  // Mg
						eng_emb = interp1(eam_fitting_edensity, eam_FMg, edensity, method);
						de += eng_emb - F_emb[nb];
						break;
					case 1:  // Y
						eng_emb = interp1(eam_fitting_edensity, eam_FY, edensity, method);
						de += eng_emb - F_emb[nb];
						break;
					// for case 2: energy doesn't change, both 0 before and after exchange
				}
			}
			
		}
		
		return de;
		
	}  // End of "exchange_de"
	
	
	
	///////////////////////////////////////////////
	void EAM::density_change(MGY *mgy, std::vector<int> &cpair, std::vector<int> &nbs_all, std::vector<double> &change_density)
	{
		int i, j, n_nbsv, n_nbse, nb, site_v, site_e, element_e, sittype;
		bool add_nb;
//		std::vector<int> nbs_all;
//		std::vector<double> change_density, 
		std::vector<double> change_density_v;
		
		site_v = cpair[0];
		site_e = cpair[1];
		element_e = mgy->elements[site_e];
		n_nbsv = mgy->neighbours[site_v].size();
		n_nbse = mgy->neighbours[site_e].size();
		
		// deducting charge density:
		sittype = mgy->sittype[site_e]-1;
		for (i=0; i<n_nbse; i++)
		{
			switch (element_e)
			{
				case 0:  // Mg
					change_density.push_back(-roMg_nbs[sittype][i]);
					break;
				case 1:  // Y
					change_density.push_back(-roY_nbs[sittype][i]);
					break;
			}
		}
		
		// adding new charge density:
		sittype = mgy->sittype[site_v]-1;
		for (i=0; i<n_nbsv; i++)
		{
			switch (element_e)
			{
				case 0:  // Mg
					change_density_v.push_back(roMg_nbs[sittype][i]);
					break;
				case 1:  // Y
					change_density_v.push_back(roY_nbs[sittype][i]);
					break;
			}
		}
		
		nbs_all = mgy->neighbours[site_e];
		
		for (i=0; i<n_nbsv; i++)
		{
			nb = mgy->neighbours[site_v][i];
			
			add_nb = 1;
			for (j=0; j<n_nbse; j++)
			{
				if (nb == nbs_all[j])
				{
					change_density[j] += change_density_v[i];
					add_nb = 0;
					break;
				}
			}
			
			if (add_nb)
			{
				nbs_all.push_back(nb);
				change_density.push_back(change_density_v[i]);
			}
		}
		
	}  // End of "combine_neighbours"
	
}  // End of "eam"


