#include <iostream>
#include <vector>
#include <fstream>

#include "eamlib.h"
#include "mgylib.h"

namespace eam 
{
	 void EAM::DoExchange(MGY *mgy, int selected_pair)
	{
		int i, site_e, site_v, nb, element_nb, whichvacancy;
		double edensity;
		std::string method;
		std::vector<int> nbs_all;
		std::vector<double> change_density;
		
		method = "linear";
		
		density_change(mgy, exchange_pair[selected_pair], nbs_all, change_density);
		
		// changing the element with the vacancy
		site_v = exchange_pair[selected_pair][0];
		site_e = exchange_pair[selected_pair][1];
		whichvacancy = exchange_pair[selected_pair][2];
		mgy->elements[site_v] = mgy->elements[site_e];
		mgy->elements[site_e] = 2;
		site_vacancy[whichvacancy] = site_e;		

		// updating the charge density and the embedding potential
		for (i=0; i<nbs_all.size(); i++)
		{
			nb = nbs_all[i];
			edensity = charge_density[nb] + change_density[i];
			charge_density[nb] = edensity;
			element_nb = mgy->elements[nb];
			switch (element_nb)
			{
				case 0:  // Mg
					F_emb[nb] = interp1(eam_fitting_edensity, eam_FMg, edensity, method);
					break;
				case 1:  // Y
					F_emb[nb] = interp1(eam_fitting_edensity, eam_FY, edensity, method);
					break;
				case 2:  // vacancy
					F_emb[nb] = 0.;
					break;
			}
			
		}
		
		syseng = energy_exchanged[selected_pair];
		
//		std::vector<double> charge_density0(nbs_all.size()), F_emb0(nbs_all.size());
//		for (i=0; i<nbs_all.size(); i++)
//		{
//			nb = nbs_all[i];
//			charge_density0[i] = charge_density[nb];
//			F_emb0[i] = F_emb[nb];
//		}
//		system_energy(mgy);
//		double err_den=0, err_fem=0;
//		for (i=0; i<nbs_all.size(); i++)
//		{
//			nb = nbs_all[i];
//			err_den += std::abs(charge_density[nb]-charge_density0[i]);
//			err_fem += std::abs(F_emb[nb]-F_emb0[i]);
//		}
//		
//		std::cout<<"err_den: "<<err_den<<", err_fem: "<<err_fem<<std::endl;
		
	}  // End of "DoExchange()"
	
}  // End of "eam"
