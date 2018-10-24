#include <iostream>
#include <vector>
#include <fstream>

#include "eamlib.h"
#include "mgylib.h"

namespace eam 
{
	 void EAM::seaching_saddle()
	{
		int i, n_saddle;
		double saddle_hight = 0.01;
		
		n_saddle = exchange_pair.size();
		saddles_points.resize(n_saddle);
		
		for (i=0; i<n_saddle; i++)
		{
			if (energy_original[i] > energy_exchanged[i])
				saddles_points[i] = energy_original[i] + saddle_hight;
			else
				saddles_points[i] = energy_exchanged[i] + saddle_hight;
		}
		
	}  // End of "seaching_saddle()"
	
}
