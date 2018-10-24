#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

#include "mgylib.h"

namespace mgy 
{
	void MGY::generate_nearest_neighbour()
	{	
		int i, j, k, ind, n_nbs, xi, yi, zi;
		bool jc, kc;
		double rr1, rr2, rr3, rr4, rmin, eps_rr=1.e-5;
		std::vector<int> nb_dijk(3), lattice_nb_list;
		std::vector<std::vector<int> > nbs;
		std::vector<std::vector<int> > nearest_nb_type1, nearest_nb_type2, nearest_nb_type3, nearest_nb_type4;

		// o1 ~ 04: 4 different types,/ of lattice sites which have different neighbours:
		double xo1, yo1, zo1, xo2, yo2, zo2, xo3, yo3, zo3, xo4, yo4, zo4;
		ind = (Nz/2-1)*Nxy + (Nx/2-1)*Ny + (Ny/2-1);
		xo1 = lattice_x[ind];
		yo1 = lattice_y[ind];
		zo1 = lattice_z[ind];
		xo2 = lattice_x[ind+1];
		yo2 = lattice_y[ind+1];
		zo2 = lattice_z[ind+1];
		xo3 = lattice_x[ind+Nxy];
		yo3 = lattice_y[ind+Nxy];
		zo3 = lattice_z[ind+Nxy];
		xo4 = lattice_x[ind+Nxy+1];
		yo4 = lattice_y[ind+Nxy+1];
		zo4 = lattice_z[ind+Nxy+1];
		
		rmin = 1.1*lattice_a;
		k=Nz/2-1;
		for (i=Nx/2-2; i<=Nx/2; i++) {
			for (j=Ny/2-2; j<=Ny/2+1; j++) {
					ind = k*Nxy + i*Ny +j;
					rr1 = std::sqrt(std::pow(lattice_x[ind]-xo1,2)+std::pow(lattice_y[ind]-yo1,2)+std::pow(lattice_z[ind]-zo1,2));
					rr2 = std::sqrt(std::pow(lattice_x[ind]-xo2,2)+std::pow(lattice_y[ind]-yo2,2)+std::pow(lattice_z[ind]-zo2,2));
					if ((rr1 <= rmin) && (rr1 > eps_rr))  // nearest neighbour of o1
					{
						nb_dijk[0] = j-(Ny/2-1); 
						nb_dijk[1] = i-(Nx/2-1);
						nb_dijk[2] = k-(Nz/2-1);
						nearest_nb_type1.push_back(nb_dijk);
					}
					if ((rr2 <= rmin) && (rr2 > eps_rr))  // nearest neighbour of o2
					{
						nb_dijk[0] = j-(Ny/2); 
						nb_dijk[1] = i-(Nx/2-1);
						nb_dijk[2] = k-(Nz/2-1);
						nearest_nb_type2.push_back(nb_dijk);
					}
			}
		}
		
		rmin = 1.1*std::sqrt(lattice_a*lattice_a/3.+lattice_c*lattice_c*0.25);
		k=Nz/2-2;
		for (i=Nx/2-2; i<=Nx/2; i++) {
			for (j=Ny/2-2; j<=Ny/2+1; j++) {
					ind = k*Nxy + i*Ny +j;
					rr1 = std::sqrt(std::pow(lattice_x[ind]-xo1,2)+std::pow(lattice_y[ind]-yo1,2)+std::pow(lattice_z[ind]-zo1,2));
					rr2 = std::sqrt(std::pow(lattice_x[ind]-xo2,2)+std::pow(lattice_y[ind]-yo2,2)+std::pow(lattice_z[ind]-zo2,2));
					if ((rr1 <= rmin) && (rr1 > eps_rr))  // nearest neighbour of o1
					{
						nb_dijk[0] = j-(Ny/2-1); 
						nb_dijk[1] = i-(Nx/2-1);
						nb_dijk[2] = k-(Nz/2-1);
						nearest_nb_type1.push_back(nb_dijk);
					}
					if ((rr2 <= rmin) && (rr2 > eps_rr))  // nearest neighbour of o2
					{
						nb_dijk[0] = j-(Ny/2); 
						nb_dijk[1] = i-(Nx/2-1);
						nb_dijk[2] = k-(Nz/2-1);
						nearest_nb_type2.push_back(nb_dijk);
					}
			}
		}
		
		k=Nz/2;
		for (i=Nx/2-2; i<=Nx/2; i++) {
			for (j=Ny/2-2; j<=Ny/2+1; j++) {
					ind = k*Nxy + i*Ny +j;
					rr1 = std::sqrt(std::pow(lattice_x[ind]-xo1,2)+std::pow(lattice_y[ind]-yo1,2)+std::pow(lattice_z[ind]-zo1,2));
					rr2 = std::sqrt(std::pow(lattice_x[ind]-xo2,2)+std::pow(lattice_y[ind]-yo2,2)+std::pow(lattice_z[ind]-zo2,2));
					if ((rr1 <= rmin) && (rr1 > eps_rr))  // nearest neighbour of o1
					{
						nb_dijk[0] = j-(Ny/2-1); 
						nb_dijk[1] = i-(Nx/2-1);
						nb_dijk[2] = k-(Nz/2-1);
						nearest_nb_type1.push_back(nb_dijk);
					}
					if ((rr2 <= rmin) && (rr2 > eps_rr))  // nearest neighbour of o2
					{
						nb_dijk[0] = j-(Ny/2); 
						nb_dijk[1] = i-(Nx/2-1);
						nb_dijk[2] = k-(Nz/2-1);
						nearest_nb_type2.push_back(nb_dijk);
					}
			}
		}
		
		///////
		rmin = 1.1*lattice_a;
		k=Nz/2;
		for (i=Nx/2-2; i<=Nx/2; i++) {
			for (j=Ny/2-2; j<=Ny/2+1; j++) {
					ind = k*Nxy + i*Ny +j;
					rr3 = std::sqrt(std::pow(lattice_x[ind]-xo3,2)+std::pow(lattice_y[ind]-yo3,2)+std::pow(lattice_z[ind]-zo3,2));
					rr4 = std::sqrt(std::pow(lattice_x[ind]-xo4,2)+std::pow(lattice_y[ind]-yo4,2)+std::pow(lattice_z[ind]-zo4,2));
					if ((rr3 <= rmin) && (rr3 > eps_rr))  // nearest neighbour of o3
					{
						nb_dijk[0] = j-(Ny/2-1); 
						nb_dijk[1] = i-(Nx/2-1);
						nb_dijk[2] = k-(Nz/2);
						nearest_nb_type3.push_back(nb_dijk);
					}
					if ((rr4 <= rmin) && (rr4 > eps_rr))  // nearest neighbour of o2
					{
						nb_dijk[0] = j-(Ny/2); 
						nb_dijk[1] = i-(Nx/2-1);
						nb_dijk[2] = k-(Nz/2);
						nearest_nb_type4.push_back(nb_dijk);
					}
			}
		}
		
		rmin = 1.1*std::sqrt(lattice_a*lattice_a/3.+lattice_c*lattice_c*0.25);
		k=Nz/2-1;
		for (i=Nx/2-2; i<=Nx/2; i++) {
			for (j=Ny/2-2; j<=Ny/2+1; j++) {
					ind = k*Nxy + i*Ny +j;
					rr3 = std::sqrt(std::pow(lattice_x[ind]-xo3,2)+std::pow(lattice_y[ind]-yo3,2)+std::pow(lattice_z[ind]-zo3,2));
					rr4 = std::sqrt(std::pow(lattice_x[ind]-xo4,2)+std::pow(lattice_y[ind]-yo4,2)+std::pow(lattice_z[ind]-zo4,2));
					if ((rr3 <= rmin) && (rr3 > eps_rr))  // nearest neighbour of o3
					{
						nb_dijk[0] = j-(Ny/2-1); 
						nb_dijk[1] = i-(Nx/2-1);
						nb_dijk[2] = k-(Nz/2);
						nearest_nb_type3.push_back(nb_dijk);
					}
					if ((rr4 <= rmin) && (rr4 > eps_rr))  // nearest neighbour of o2
					{
						nb_dijk[0] = j-(Ny/2); 
						nb_dijk[1] = i-(Nx/2-1);
						nb_dijk[2] = k-(Nz/2);
						nearest_nb_type4.push_back(nb_dijk);
					}
			}
		}
		
		k=Nz/2+1;
		for (i=Nx/2-2; i<=Nx/2; i++) {
			for (j=Ny/2-2; j<=Ny/2+1; j++) {
					ind = k*Nxy + i*Ny +j;
					rr3 = std::sqrt(std::pow(lattice_x[ind]-xo3,2)+std::pow(lattice_y[ind]-yo3,2)+std::pow(lattice_z[ind]-zo3,2));
					rr4 = std::sqrt(std::pow(lattice_x[ind]-xo4,2)+std::pow(lattice_y[ind]-yo4,2)+std::pow(lattice_z[ind]-zo4,2));
					if ((rr3 <= rmin) && (rr3 > eps_rr))  // nearest neighbour of o3
					{
						nb_dijk[0] = j-(Ny/2-1); 
						nb_dijk[1] = i-(Nx/2-1);
						nb_dijk[2] = k-(Nz/2);
						nearest_nb_type3.push_back(nb_dijk);
					}
					if ((rr4 <= rmin) && (rr4 > eps_rr))  // nearest neighbour of o2
					{
						nb_dijk[0] = j-(Ny/2); 
						nb_dijk[1] = i-(Nx/2-1);
						nb_dijk[2] = k-(Nz/2);
						nearest_nb_type4.push_back(nb_dijk);
					}
			}
		}
		
		//////////////////////
				
		for (k=0; k<Nz; k++) {
			for (i=0; i<Nx; i++) {
				for (j=0; j<Ny; j++) 
				{
					ind = k*Nxy+i*Ny+j;
					jc = (((j-(Nx/2-1))%2)==0);
					kc = (((k-(Nz/2-1))%2)==0);
					if ( jc && kc )  // type 1
						nbs = nearest_nb_type1;
					else if ( !jc && kc )  // type 2
						nbs = nearest_nb_type2;
					else if ( jc && !kc )  // type 3
						nbs = nearest_nb_type3;
					else if ( !jc && !kc )  // type 4
						nbs = nearest_nb_type4;
										
					n_nbs = nbs.size();  // number of nearest neighbours of current lattice site
					lattice_nb_list.resize(n_nbs);  // neighbours' id of current lattice site
					for (int s=0; s<n_nbs; s++)
					{
						yi = j + nbs[s][0];
						xi = i + nbs[s][1];
						zi = k + nbs[s][2];
						
						if (yi<0)
							yi += Ny;
						else if (yi>=Ny)
							yi -= Ny;
						
						if (xi<0)
							xi += Nx;
						else if (xi>=Nx)
							xi -= Nx;
						
						if (zi<0)
							zi += Nz;
						else if (zi>=Nz)
							zi -= Nz;
							
						ind = zi*Nxy + xi*Ny + yi;
						lattice_nb_list[s] = ind;
					}
					
					nearest_neighbours.push_back(lattice_nb_list);
					
				}
			}
		}
		
		
	}  // End of "generate_neighbour()"
}
