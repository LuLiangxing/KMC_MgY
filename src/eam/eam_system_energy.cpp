#include <iostream>
#include <vector>
#include <fstream>

#include "eamlib.h"
#include "mgylib.h"

namespace eam 
{
	 void EAM::system_energy(MGY *mgy)
	{
		int i, j, elem_sit, elem_nb, sittype, nsite, n_nbs;
		double edensity, eng_emb, half=0.5;
		std::string method;
		
		method = "linear";
		nsite = mgy->elements.size();
		
		site_vacancy.clear();
		F_emb.clear();
		charge_density.clear();
		
		n_vacancy = 0;
		
		syseng = 0.;
		
		for (i=0; i<nsite; i++)
		{
			elem_sit = mgy->elements[i];
			edensity = 0.;
			n_nbs = mgy->neighbours[i].size();
			sittype = mgy->sittype[i]-1;
			for (j=0; j<n_nbs; j++)
			{
				elem_nb = mgy->elements[ mgy->neighbours[i][j] ];
				
				// charge density:
				switch (elem_nb)
				{
					case 0:  // Mg
						edensity += roMg_nbs[sittype][j];
						break;
					case 1:  // Y
						edensity += roY_nbs[sittype][j];
						break;
				}
			}
			
			// pair-wise potential:
			if (elem_sit != 2)  // Mg or Y
			{
				for (j=0; j<n_nbs; j++)
				{
					elem_nb = mgy->elements[ mgy->neighbours[i][j] ];
					
					if (elem_nb != 2)  // Mg or Y
					{
						switch (elem_sit + elem_nb)
						{
							case 0:  // Mg-Mg
								syseng += FMgMg_nbs[sittype][j]*half;
								break;
							case 1:  // Mg-Y or Y-Mg
								syseng += FMgY_nbs[sittype][j]*half;
								break;
							case 2:  // Y-Y
								syseng += FYY_nbs[sittype][j]*half;
								break;
						}
					}
				}
				
				// embedding potential:
				switch (elem_sit)
				{
					case 0:  // Mg
						eng_emb = interp1(eam_fitting_edensity, eam_FMg, edensity, method);
						syseng += eng_emb;
						break;
					case 1:  // Y
						eng_emb = interp1(eam_fitting_edensity, eam_FY, edensity, method);
						syseng += eng_emb;
						break;
				}
				
				
				
			}  // End of "if (elem_sit != 2)"
			else  // vacancy
			{
				n_vacancy++;
				site_vacancy.push_back(i);
				
				eng_emb = 0.;
				
			}
			
			// save charge density & embedding potential of current site
			charge_density.push_back(edensity);
			F_emb.push_back(eng_emb);
			
		}  // End of current lattice site
		
		
	}  // End of "system_energy()"
	
}  // End of "eam"
