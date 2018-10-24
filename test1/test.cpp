#include <iostream>
#include <vector>
#include <sys/time.h>
#include <fstream>

void print_vector(std::vector<int> &vec, std::string str);
std::vector<int> pickup_randi(int m, int n);
void read_data(std::string fname, std::vector<double> &store_vector);

class KMC
{
	public:
		double* get_a(void);
		double** get_aa(void);
		std::vector<double> get_c();
		std::vector<std::vector<double>> get_cc(void);
		void set_a(int , double );
		void set_aa(int , int , double );
		void set_c(int , double );
		void set_cc(int , int , double );
		double hh;
	private:
		int na, nax, nay;
		double *a = new double [na];
		double **aa = new double *[nax];
		std::vector<double> c;
		std::vector<std::vector<double>> cc;
		
};

class setting
{
	public:
		void seth3(KMC *kmc);
		double geth3();
	
	private:
		double h3;
	
};

void setting::seth3(KMC *kmc)
{
	std::cout<<"hh into seth3: "<<kmc->hh<<std::endl;
	h3 = kmc->hh;
}

double setting::geth3()
{
	return h3;
}

double* KMC::get_a(void)
{
//	std::cout<<"a in get_a: "<<a[0]<<", "<<a[1]<<std::endl;
	return(&a[0]);
//	return(a);
};

double** KMC::get_aa(void)
{
	return(aa);
};

std::vector<double> KMC::get_c()
{
	return c;
};

std::vector<std::vector<double>> KMC::get_cc(void)
{
	return(cc);
};

void KMC::set_a(int size_a, double ini_a)
{
//	a[0] = a0;
//	a[1] = a1;
//	std::cout<<"a: "<<a[0]<<", "<<a[1]<<std::endl;

//	std::cout<<"size_a: "<<size_a<<", ini_a: "<<ini_a<<std::endl;
//	double *a = new double [size_a];
	
	na = size_a;
	
	for (int i=0;i<size_a;i++)
		a[i] = ini_a;
};

void KMC::set_aa(int ny, int nx, double ini_aa)
{
	nay = ny;
	nax = nx;
	for (int i=0;i<nax;i++)
	{
		aa[i] = new double [nay];
	}
	for (int i=0;i<nax;i++)
	{
		for (int j=0;j<nay;j++)
			aa[i][j] = ini_aa;
	}
		
};

void KMC::set_c(int nx, double ini_aa)
{
	c.resize(nx);
	
	for (int i=0;i<nx;i++)
	{
			c[i] = ini_aa;
	}
};

void KMC::set_cc(int ny, int nx, double ini_aa)
{
	cc.resize(nx);
	for (int i=0;i<nx;i++)
	{
		cc[i].resize(ny);
	}
	for (int i=0;i<nx;i++)
	{
		for (int j=0;j<ny;j++)
			cc[i][j] = ini_aa;
	}
};

int main()
{
	// loading parameters from input file:
	
	// initiallization:
	KMC *kmc = new KMC;  // new kmc class
	
	int size_a = 5, nay= 2, nax= 3;
	double ini_a = 10.3, ini_aa = 0.12;
	
	kmc->set_a(size_a, ini_a);
	double *b = kmc->get_a();
//	std::cout<<b[0]<<", "<<b[1]<<", "<<b[2]<<std::endl;
	
	for (int i=0;i<size_a;i++)
		std::cout<<b[i]<<", ";
	std::cout<<std::endl;
	
	size_a = 2; 
	ini_a = 3.1;
	kmc->set_a(size_a, ini_a);
	b = kmc->get_a();
	
	for (int i=0;i<size_a;i++)
		std::cout<<b[i]<<", ";
	std::cout<<std::endl;
	
	struct timeval start, end;
	gettimeofday(&start, NULL);
	
	for (int i=1; i<10000; i++)
	{
		size_a = 20;
		ini_a = i/10.;
		kmc->set_a(size_a, ini_a);
		b = kmc->get_a();
//		for (int i=0;i<size_a;i++)
//			std::cout<<b[i]<<", ";
//		std::cout<<std::endl;
	}
	
	gettimeofday(&end, NULL);
	std::cout<< ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6<<std::endl;
	
//	for (int i=0;i<size_a;i++)
//		std::cout<<b[i]<<", ";
//	std::cout<<std::endl;

	kmc->set_aa(nay,nax,ini_aa);
	double **bb = kmc->get_aa();
	
	for (int i=0; i<nax; i++)
	{
		for (int j=0; j<nay; j++)
			std::cout<<bb[i][j]<<", ";
		std::cout<<std::endl;
	}
	
	kmc->set_cc(nay,nax,ini_aa);
	std::vector<std::vector<double>> dd = kmc->get_cc();
	std::cout<<"cc: "<<std::endl;
	for (int i=0; i<nax; i++)
	{
		for (int j=0; j<nay; j++)
			std::cout<<bb[i][j]<<", ";
		std::cout<<std::endl;
	}


	gettimeofday(&start, NULL);
	
	for (int i=0; i<10000; i++)
	{
		kmc->set_cc(nay,nax,ini_aa);
		std::vector<std::vector<double>> dd = kmc->get_cc();
	}
	
	gettimeofday(&end, NULL);
	std::cout<< ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6<<std::endl;
	
	
	std::cout<<"test c, d:"<<std::endl;
	
	gettimeofday(&start, NULL);
	
	for (int i=0; i<10000; i++)
	{
		kmc->set_c(20,i/10.);
		std::vector<double> d = kmc->get_c();
	}
	
//	std::cout<<"d.size(): "<<d.size()<<std::endl;
	
	gettimeofday(&end, NULL);
	std::cout<< ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6<<std::endl;
	
//	std::cout<<"d.size(): "<<d.size()<<std::endl;

	double lax = 3.3, lab;
	int ij =4;
	lab = lax+(ij%2)*lax;
	std::cout<<"lab: "<<lab<<std::endl;
	
	std::cout<<"-10%10 = "<<(-10)%10<<std::endl;
	
	std::vector<int*> ts, tss;
	int tsi[3];
	tsi[0] = tsi[1] = tsi[2] = 4;
	ts.push_back(tsi);
	
	tsi[0] = tsi[1] = tsi[2] = 5;
	ts.push_back(tsi);
	std::cout<<"ts.size(): "<<ts.size()<<std::endl;
	std::cout<<"ts[0][0]: "<<ts[0][0]<<", ts[0][1]: "<<ts[0][1]<<", ts[0][2]: "<<ts[0][2]<<std::endl;
	std::cout<<"ts[1][0]: "<<ts[1][0]<<", ts[1][1]: "<<ts[1][1]<<", ts[1][2]: "<<ts[1][2]<<std::endl;
	
	tss = ts;
	std::cout<<"tss.size(): "<<tss.size()<<std::endl;
	std::cout<<"tss[0][0]: "<<tss[0][0]<<", tss[0][1]: "<<tss[0][1]<<", tss[0][2]: "<<tss[0][2]<<std::endl;
	std::cout<<"tss[1][0]: "<<tss[1][0]<<", tss[1][1]: "<<tss[1][1]<<", tss[1][2]: "<<tss[1][2]<<std::endl;
	
	std::vector<std::vector<int>> tg, tgg;
	std::vector<int> tgi;
	tgi.resize(3);
	tgi[0] = tgi[1] = tgi[2] = 4;
	tg.push_back(tgi);
	
	tgi[0] = tgi[1] = tgi[2] = 5;
	tg.push_back(tgi);
	std::cout<<"tg.size(): "<<tg.size()<<std::endl;
	std::cout<<"tg[0][0]: "<<tg[0][0]<<", tg[0][1]: "<<tg[0][1]<<", tg[0][2]: "<<tg[0][2]<<std::endl;
	std::cout<<"tg[1][0]: "<<tg[1][0]<<", tg[1][1]: "<<tg[1][1]<<", tg[1][2]: "<<tg[1][2]<<std::endl;
	
	tgg = tg;
	std::cout<<"tgg.size(): "<<tgg.size()<<std::endl;
	std::cout<<"tgg[0][0]: "<<tgg[0][0]<<", tgg[0][1]: "<<tgg[0][1]<<", tgg[0][2]: "<<tgg[0][2]<<std::endl;
	std::cout<<"tgg[1][0]: "<<tgg[1][0]<<", tgg[1][1]: "<<tgg[1][1]<<", tgg[1][2]: "<<tgg[1][2]<<std::endl;
	
	std::vector<int> tki(3);
	std::cout<<"tki.size(): "<<tki.size()<<std::endl;
	
	double lattice_a = 3.2, rc_cut=6.5;
	int xy_range = 2*int(rc_cut/lattice_a);
	std::cout<<"xy_range: "<<xy_range<<std::endl;
	
	std::vector<int> indx(5);
	for (int i=0;i<5;i++)
		indx[i] = i;
	print_vector(indx, "indx");
	
	indx.pop_back();
	print_vector(indx, "indx");
	
	indx.resize(6);
	print_vector(indx, "indx");
	
	std::vector<int> indy;
	indy.resize(4);
	print_vector(indy, "indy");
	
	std::vector<int> pic;
	pic = pickup_randi(5,1000000);
	print_vector(pic,"pic");
	
	std::vector<double> fy_eam;
	read_data("../EAM_data/FY.txt", fy_eam);
	
	std::cout<<"fy_eam.size(): "<<fy_eam.size()<<std::endl;
	for (int i=0;i<10;i++)
		printf("%3.16f \n",fy_eam[i]);
//		std::cout<<fy_eam[i]<<" \n";
	
	kmc->hh = 0.3;
	std::cout<<"hh: "<<kmc->hh<<std::endl;
	
	setting *settings = new setting;
	settings->seth3(kmc);
	std::cout<<"h3: "<<settings->geth3()<<std::endl;
	
	return(0);
}

void print_vector(std::vector<int> &vec, std::string str)
{
	int nn = vec.size();
	std::cout<<str<<" size: "<<vec.size()<<", values: ";
	for (int i=0; i<nn; i++)
		std::cout<<", "<<vec[i];
	std::cout<<std::endl;
}


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
		
		std::cout<<"pick up from the "<<which_section<<"th section in total "<<n_section<<" sections"<<std::endl;
		
		ind = rand() % length_section[which_section] + start_ind_section[which_section];
		picked[i] = (pickup_list[ind]);
		pickup_list[ind] = pickup_list[--length_pickup_list];
	}
	
	
	return picked;
	
}  // End of "pickup_randi"


void read_data(std::string fname, std::vector<double> &store_vector)
{
	double xin;//, x2;
//	int x3;
	std::ifstream inFile;
	
	store_vector.clear();
	
	inFile.open(fname);
	if (!inFile) 
	{
		std::cout << "Unable to data file: "<<fname;
		exit(1);   // call system to stop
	}
	
//	inFile>>x2>>x3;
//	std::cout<<x2<<" "<<x3<<std::endl;
	
	while (inFile >> xin)
		store_vector.push_back(xin);
		
	inFile.close();
}