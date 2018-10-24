#include <iostream>
#include <vector>
#include <fstream>

#include "eamlib.h"
#include "mgylib.h"

namespace eam 
{
	 void EAM::PreparingKMC(MGY *mgy)
	{
		listing_exchange(mgy);	
		energy_difference(mgy);
		seaching_saddle();		
	}  // End of "seaching_saddle()"
	
}
