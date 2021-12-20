#pragma once
#include <math.h>
#include <cmath>
#include <vector>
#include <iostream>


/*


DO NOT USE THIS SHITS BROKEN LMFAO




*/


class Matrix {
	public:
		std::vector<std::vector<float>> values;
};

// Its just my job, five days a week

Matrix create(std::vector<std::vector<int>> values) {
	Matrix m1;

	for (int i; i < values.size(); i++) {
		for (int j; j < values[i].size(); i++) {
			m1.values[i][j] = values[i][j];
		}
	}
	return m1;
}

Matrix sum(Matrix a, Matrix b) {
	Matrix c;
	std::vector<unsigned long> sizes_a = {a.values.size(), a.values[0].size()};
	std::vector<unsigned long> sizes_b = {b.values.size(), b.values[0].size()};
	if (sizes_a[0] == sizes_b[0] && sizes_a[1] == sizes_b[1]) 
	{
		for (int i; i < a.values.size(); i++) 
		{
			for(int k; k < a.values[0].size(); k++) 
			{
				c.values[i][k] = a.values[i][k] + b.values[i][k];
			}
		}

		return c; 
	}
	else 
	{
		std::cout << "cannot add matrices" << std::endl;
	}
}

// And I think its gonna be a long long time till touch down brings me down