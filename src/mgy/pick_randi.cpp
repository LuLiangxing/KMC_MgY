#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <sys/time.h>

#include "mgylib.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////
std::vector<int> pickup_randi(int m, int n)
{
	int i, ind, length_pickup_list;
	int n_section, residue, j, which_section;
	std::vector<int> length_section, start_ind_section;
	std::vector<int> pickup_list(n), picked(m);
	
	std::srand ( time(NULL) ); //initialize the random seed
	
	for (i=0; i<n; i++)
		pickup_list[i] = i;
	
	length_pickup_list = n;
	for (i=0;i<m;i++)
	{
		n_section = length_pickup_list/RAND_MAX+1;
		length_section.resize(n_section);
		for (j=0; j<n_section; j++)
			length_section[j] = length_pickup_list/n_section;
		residue = length_pickup_list % n_section;
		if (residue!=0)
		{
			for (j=0; j<residue; j++)
				length_section[j]++;
		}
		start_ind_section.resize(n_section);
		start_ind_section[0] = 0;
		if (n_section>1)
		{
			for (j=1; j<n_section; j++)
				start_ind_section[j] = start_ind_section[j-1] + length_section[j-1];
		}
				
		which_section = rand() % n_section;
		
		ind = rand() % length_section[which_section] + start_ind_section[which_section];
		picked[i] = (pickup_list[ind]);
		pickup_list[ind] = pickup_list[--length_pickup_list];
	}
	
	return picked;
	
}  // End of "pickup_randi"
