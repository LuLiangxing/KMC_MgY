#include <iostream>
#include <vector>
#include <fstream>

#include "eamlib.h"
#include "common.h"
#include "mgylib.h"
#include "mgykmc.h"

using namespace mgy;
using namespace mgykmc;

namespace eam 
{
	 EAM::EAM(MGY *mgy)
	{
		read_raw_data();
		interp_at_nbs(mgy);
		system_energy(mgy);	
		nthreads = 1;
	}
	

	EAM::EAM(MGY *mgy, MGYKMC_Input *mgykmc_input)
        {
                read_raw_data();
                interp_at_nbs(mgy);
                system_energy(mgy);
                nthreads = mgykmc_input->nthreads;
        }

}
