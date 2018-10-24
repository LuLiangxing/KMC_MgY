#include <iostream>
#include <vector>
#include <fstream>

#include "eamlib.h"

namespace eam 
{
	void EAM::read_raw_data()
	{		
		// eam_fitting_distance:
		read_data("../../bin/EAM_data/r.txt", eam_fitting_distance);
		
		// eam_fitting_edensity:
		read_data("../../bin/EAM_data/ro.txt", eam_fitting_edensity);
		
		// eam_roMg:
		read_data("../../bin/EAM_data/Ro_Mg.txt", eam_roMg);
		
		// eam_roY:
		read_data("../../bin/EAM_data/Ro_Y.txt", eam_roY);
		
		// eam_FMg:
		read_data("../../bin/EAM_data/FMg.txt", eam_FMg);
		
		// eam_FY:
		read_data("../../bin/EAM_data/FY.txt", eam_FY);
		
		// eam_FMgMg:
		read_data("../../bin/EAM_data/FMgMg.txt", eam_FMgMg);
		
		// eam_FYY:
		read_data("../../bin/EAM_data/FYY.txt", eam_FYY);
		
		// eam_FMgY:
		read_data("../../bin/EAM_data/FMgY.txt", eam_FMgY);
		
	}  // End of "initiallization()"
	
	
	void read_data(std::string fname, std::vector<double> &store_vector)
	{
		double xin;
		std::ifstream inFile;
		
		store_vector.clear();
		
		inFile.open(fname);
		if (!inFile) 
		{
			std::cout << "Unable to read data file: "<<fname;
			exit(1);   // call system to stop
		}
		while (inFile >> xin)
			store_vector.push_back(xin);
			
		inFile.close();
	}
	
}  // End of "eam"
