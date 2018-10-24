#include <iostream>
#include <vector>
#include <fstream>

#include "eamlib.h"
#include "common.h"
#include "mgylib.h"

using namespace mgy;

namespace eam 
{
	 void EAM::interp_at_nbs(MGY *mgy)
	{
		std::string method;
		method = "linear";
		
		roMg_nbs.push_back(interp1(eam_fitting_distance, eam_roMg, mgy->rr_type1,method));
		roMg_nbs.push_back(interp1(eam_fitting_distance, eam_roMg, mgy->rr_type2,method));
		roMg_nbs.push_back(interp1(eam_fitting_distance, eam_roMg, mgy->rr_type3,method));
		roMg_nbs.push_back(interp1(eam_fitting_distance, eam_roMg, mgy->rr_type4,method));
		roY_nbs.push_back(interp1(eam_fitting_distance, eam_roY, mgy->rr_type1,method));
		roY_nbs.push_back(interp1(eam_fitting_distance, eam_roY, mgy->rr_type2,method));
		roY_nbs.push_back(interp1(eam_fitting_distance, eam_roY, mgy->rr_type3,method));
		roY_nbs.push_back(interp1(eam_fitting_distance, eam_roY, mgy->rr_type4,method));
		FMgMg_nbs.push_back(interp1(eam_fitting_distance, eam_FMgMg, mgy->rr_type1,method));
		FMgMg_nbs.push_back(interp1(eam_fitting_distance, eam_FMgMg, mgy->rr_type2,method));
		FMgMg_nbs.push_back(interp1(eam_fitting_distance, eam_FMgMg, mgy->rr_type3,method));
		FMgMg_nbs.push_back(interp1(eam_fitting_distance, eam_FMgMg, mgy->rr_type4,method));
		FYY_nbs.push_back(interp1(eam_fitting_distance, eam_FYY, mgy->rr_type1,method));
		FYY_nbs.push_back(interp1(eam_fitting_distance, eam_FYY, mgy->rr_type2,method));
		FYY_nbs.push_back(interp1(eam_fitting_distance, eam_FYY, mgy->rr_type3,method));
		FYY_nbs.push_back(interp1(eam_fitting_distance, eam_FYY, mgy->rr_type4,method));
		FMgY_nbs.push_back(interp1(eam_fitting_distance, eam_FMgY, mgy->rr_type1,method));
		FMgY_nbs.push_back(interp1(eam_fitting_distance, eam_FMgY, mgy->rr_type2,method));
		FMgY_nbs.push_back(interp1(eam_fitting_distance, eam_FMgY, mgy->rr_type3,method));
		FMgY_nbs.push_back(interp1(eam_fitting_distance, eam_FMgY, mgy->rr_type4,method));
		
	}
	
}
