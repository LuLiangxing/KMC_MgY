#ifndef MGYLIB_H_
#define MGYLIB_H_

#include <iostream>
#include <vector>

#include "mgykmc.h"

using namespace mgykmc;

namespace mgy 
{	
	class MGY
	{
		public:
			MGY(std::string fname);
			MGY(MGYKMC_Input *mgykmc_input);
			virtual ~MGY()
			{}
			
			void set_parameter(std::string fname);
			
			void set_parameter(MGYKMC_Input *mgykmc_input);
			
			void generate_structure();
			
			void generate_neighbour();
			
			void generate_nearest_neighbour();
			
//			void DoExchange(int );
			
			int n_vacancy;
			std::vector<int> elements, sittype;
			std::vector<double> lattice_x, lattice_y, lattice_z;
			std::vector<std::vector<int> > neighbours, nearest_neighbours;
//			std::vector<std::vector<int> > nb_type1, nb_type2, nb_type3, nb_type4;
			std::vector<double> rr_type1, rr_type2, rr_type3, rr_type4;
			
		private:
			int Nx, Ny, Nz, Nxyz, Nxy;  // for periodical, Nx, Ny & Nz must be times of 2;
			double lattice_a, lattice_c, rc_cut, yat;
						
	};
	
} /* namespace kmc */

//std::vector<int> pickup_randi(int m, int n);	
//// void read_data(std::string fname, std::vector<double> &store_vector);
//void print_vector(std::vector<double> &vec, std::string fname);
//void print_vector(std::vector<int> &vec, std::string fname);
//void print_vector(std::vector<std::vector<int> > &mat, std::string fname);
//void print_vector(std::vector<std::vector<double> > &mat, std::string fname)

#endif /* MGYLIB_H_ */




