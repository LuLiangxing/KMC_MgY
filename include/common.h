#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <vector>


std::vector<int> pickup_randi(int m, int n);	
// void read_data(std::string fname, std::vector<double> &store_vector);
void print_vector(std::vector<double> &vec, std::string fname);
void print_vector(std::vector<int> &vec, std::string fname);
void print_vector(std::vector<std::vector<int> > &mat, std::string fname);
void print_vector(std::vector<std::vector<double> > &mat, std::string fname);

double interpolation1(std::vector<double> &x0, std::vector<double> &y0, double x, std::string method);

#endif /* COMMON_H_ */
