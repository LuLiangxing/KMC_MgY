#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

#include "mgylib.h"
#include "common.h"

namespace mgy 
{
	void MGY::generate_structure()
	{
		int i, j, k, ind, NY;
		double half_a, half_c, s3half_a, halfs3_a;
		
		// lattice parameters will be used
		half_a = lattice_a/2.;
		half_c = lattice_c/2.;
		s3half_a = std::sqrt(3.)/2.*lattice_a;
		halfs3_a = lattice_a/2./std::sqrt(3.);
		
		// generating hcp lattice structure and store coordinates of each lattice site
		elements.resize(Nxyz);  // element type of all lattice site, 0: Mg, 1: Y, 2: vacancy
		lattice_x.resize(Nxyz);  // x coordinate of all lattice site
		lattice_y.resize(Nxyz);  // y coordinate of all lattice site
		lattice_z.resize(Nxyz);  // z coordinate of all lattice site
				
		ind = 0;
		for (k=0; k<Nz; k++)
		{
			for (i=0; i<Nx; i++)
			{
				for (j=0;j<Ny;j++)
				{
					lattice_x[ind] = i*lattice_a+(j%2)*half_a+(k%2)*half_a;
					lattice_y[ind] = j*s3half_a+(k%2)*halfs3_a;
					lattice_z[ind] = k*half_c;
					ind++;
				}
			}
		}
		
		NY = Nxyz*yat+n_vacancy;
		if (NY>=Nxyz)
			NY = Nxyz;
		std::vector<int> ind_YV;
		ind_YV = pickup_randi(NY, Nxyz);
		for (i=0; i<NY-n_vacancy; i++)
			elements[ind_YV[i]] = 1;  // Y atoms
		for (i=NY-n_vacancy; i<NY; i++)
			elements[ind_YV[i]] = 2;  // vacancy
		
	}  // End of "generate_structure()"

}  // End of "mgy"


