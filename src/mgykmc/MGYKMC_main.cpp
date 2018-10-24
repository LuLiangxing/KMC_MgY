#include <iostream>
#include <vector>

#include "mgylib.h"
#include "eamlib.h"
#include "kmclib.h"
#include "common.h"
#include "mgykmc.h"

using namespace mgy;
using namespace eam;
using namespace kmc;
using namespace mgykmc;

int main(int argc, char **argv)
{
	std::string is_restart;
	MGYKMC_Input *mgykmc_input = new MGYKMC_Input("../../bin/input/kmc_mgy.inp");
	MGYKMC_Output *mgykmc_output = new MGYKMC_Output;

	if (argc > 1)
		is_restart = argv[1];
	
	if (is_restart == "-r")
	{
		mgykmc_input->load_input("../../bin/restart/kmc_mgy.inp.rst");
		mgykmc_input->is_restart = 1;
	}
	
	runMGYKMC(mgykmc_input, mgykmc_output);
	
	std::cout<<"runMGYKMC finished"<<std::endl;

	return(0);
	
}
