#include <iostream>
#include <vector>
#include <fstream>

#include "eamlib.h"
#include "mgylib.h"

namespace eam 
{
	 void EAM::listing_exchange(MGY *mgy)
	{
		int vi, n_nbs, vsite, csite, nbj;
		std::vector<int> cpair;
		
		exchange_pair.clear();
		cpair.resize(3);
		
		for (vi=0; vi<n_vacancy; vi++)
		{
			vsite = site_vacancy[vi];
			cpair[0] = vsite;
			n_nbs = mgy->nearest_neighbours[vsite].size();
			for (nbj=0; nbj<n_nbs; nbj++)
			{
				csite = mgy->nearest_neighbours[vsite][nbj];
				if (mgy->elements[csite] != 2)  // Mg or Y
				{
					cpair[1] = csite;
					cpair[2] = vi;
					exchange_pair.push_back(cpair);
				}
			}
		}
		
	}  // End of "listing_exchange()"
	
}  // End of "eam"
