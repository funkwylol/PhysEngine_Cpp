#pragma once
#include <cmath>
#include <iostream>
#include <math.h>
#include "../include/maths.h"
#include <string.h>
#include <vector>
#include <functional>
#include <algorithm>
//#include <matrix.h>
using namespace std;


// Im not the man that they think I am.

// Vector class to create vector objects with magnitude and angle. 
// These probably already exist and probably come with C++ but its faster to just make it myself and I acually understand how tf it works.

namespace vector2 {

	// 2d vector
	class vector2 {
		public:
		// Magnitude
			float magnitude;
		// Angle (Direction)
			float angle;
	};

	// Takes in vector, returns vector (Dynamic array) with x and y components
	vector<float> v_comps(vector2 v) {
		float ra = Convert(v.angle,0,1);
		vector<float> comps = {v.magnitude * std::cos(ra),v.magnitude * sin(ra)};
		return comps;
	}
	// Function type is of vector because it returns a vector
	vector2 vfc(float x, float y) {
		// Uses pythagorean theorem to solve for magnitude (c)
		float c = pythag(x,y,0,2);
		// Uses inverse tan or arctan to solve for angle of vector.
		float a1 = std::atan(y/x);
		float a = Convert(0,a1,2);
		vector2 v1;
		v1.magnitude = c;
		v1.angle = a;
		return v1;
	}
	// Takes the sum of two vectors, va, vb, and outputs a vector c with that value.
	vector2 sum_v(vector2 a, vector2 b) {
		// Creates dynamic array for the components of vector a and b
		vector<float> comps_a = v_comps(a);
		vector<float> comps_b = v_comps(b);
		// Adds the components to make the new vector
		float ax = comps_a[0];
		float ay = comps_a[1];
		float bx = comps_b[0];
		float by = comps_b[1];
		float cx = ax + bx;
		float cy = ay + by;
		// Create the new vector
		vector2 c = vfc(cx,cy);
		return c;
	}

	// Vector subtraction, same as adddition but instead of summning the components, it subtracts them.
	vector2 sub_v(vector2 a, vector2 b) {
		vector<float> comps_a = v_comps(a);
		vector<float> comps_b = v_comps(b);
		float ax = comps_a[0];
		float ay = comps_a[1];
		float bx = comps_b[0];
		float by = comps_b[1];
		float cx = ax - bx;
		float cy = ay - by;
		vector2 c = vfc(cx,cy);
		return c;
	}

	// This is vector by vector multiplication. I dont think I did it right because it needs some stupid cross product or dot product shit that I dont know because thats like complicated linear algebra bullshit.
	float mult_v(vector2 a, vector2 b) {
		vector<float> comps_a = v_comps(a);
		vector<float> comps_b = v_comps(b);
		vector<float> comps_c;
		float result;
		for (int i; i < 2; i++) {
			comps_c[i] = comps_a[i] * comps_b[i];
		}
		for (int i; i < 2; i++) {
			result += comps_c[i];
		}
		// Had i done what i wanted to before, which was to make a recursive function that adds to the previous value by an amount of the vector. It kept 

		return result;
	}
	float div_v(vector2 a, vector2 b) {
		vector<float> comps_a = v_comps(a);
		vector<float> comps_b = v_comps(b);
		vector<float> comps_c;
		float result;
		for (int i; i < 2; i++) {
			comps_c[i] = comps_a[i] / comps_b[i];
		}
		for (int i; i < 2; i++) {
			result += comps_c[i];
		}
		// Had i done what i wanted to before, which was to make a recursive function that adds to the previous value by an amount of the vector. It kept 

		return result;
	}

	// Multiplies vector by scalar
	vector2 mult(vector2 a, float b) {
		vector<float> comps_a = v_comps(a);
		float cx = comps_a[0] * b;
		float cy = comps_a[1] * b;
		vector2 c = vfc(cx, cy);
		return c;

	}

	// Divides vector by scalar
	vector2 div(vector2 a, float b) {
		vector<float> comps_a = v_comps(a);
		float cx = comps_a[0] / b;
		float cy = comps_a[1] / b;
		vector2 c = vfc(cx, cy);

		return c;

	}

	// Turns vector into unit vector. (Normalizes it)
	vector2 normalize(vector2 v1) {
		vector2 v2 = div(v1,v1.magnitude);
		return v2;
	}

}


namespace vector3 {
	// 3d vector
	class vector3 {
		public:
			float magnitude;
			// 2 angles, angle alpha and angle beta, since its in 3d.
			float angle1;
			float angle2;
			// If both angles equal zero, then it is pointing in the +x direction.
			// Angle alpha (1), is measured in degrees from the x axis, angle beta(2) is measured from the y axis.
			
	};

	// And i  think its gonna be a long long time till touchdown brings me down

	// IM A ROCKETMANNNNNNNNN

	// Useless constructor
	vector3 createVector3(float magnitude, float angle1, float angle2) {
		vector3 v1;
		v1.magnitude = magnitude;
		v1.angle1 = angle1;
		v1.angle2 = angle2;
		return v1;
	}



	// 3d version of v_comps, same thing, but in 3d.
	vector<float> v_comps(class vector3 v) {
		float ra1 = Convert(v.angle1,0,2);
		float ra2 = Convert(v.angle2,0,2);
		float vx = v.magnitude * cos(ra1);
		float vy = v.magnitude * sin(ra1);
		float vz = v.magnitude * sin(ra2);
		vector<float> comps_3d = {vx, vy, vz};
		return comps_3d;
	}

	// Takes in x and y components of vector, returns a Vector with the same magnitude and direction. 



	// same as vfc(), but in 3d, 
	vector3 vfc_3d(float x, float y, float z) {
		float c = pythag_3d(x,y,z,0,3);
		// Solving for angle 1 and 2, y acts to z just the same as x acts to y, so y can be measured as both the cos(a2) or the sin(a1)
		float a11 = atan(y/x);
		float a21 = atan(z/y);
		float a1 = Convert(0,a11,2);
		float a2 = Convert(0,a21,2);
		vector3 v1;
		v1.magnitude = c;
		v1.angle1 = a1;
		v1.angle2 = a2;
		return v1;
	}

	// Sums two vectors
	vector3 sum(vector3 a, vector3 b) {
		vector<float> comps_a = v_comps(a);
		vector<float> comps_b = v_comps(b);
		vector<float> comps_c;

		for (int n; n<3; n++) {
			comps_c[n] = comps_a[n]+comps_b[n];
		}
		vector3 v1 = vfc_3d(comps_c[0],comps_c[1],comps_c[2]);
		return v1;
	}

	// Subtracts two vectors
	vector3 sub(vector3 a, vector3 b) {
		vector<float> comps_a = v_comps(a);
		vector<float> comps_b = v_comps(b);
		vector<float> comps_c;

		for (int n; n<3; n++) {
			comps_c[n] = comps_a[n]-comps_b[n];
		}
		vector3 v1 = vfc_3d(comps_c[0],comps_c[1],comps_c[2]);
		return v1;
	}

	// Multiplies two vectors. Complicated cross product bullshit
	float mult_v(vector3 a, vector3 b) {
		vector<float> comps_a = v_comps(a);
		vector<float> comps_b = v_comps(b);
		vector<float> comps_c;
		float result;

		for (int n; n<3; n++) {
			comps_c[n] = comps_a[n]*comps_b[n];
		}
		for (int n; n < 3; n++) {
			result += comps_c[n];
		}
		return result;
		vector3 v1 = vfc_3d(comps_c[0],comps_c[1],comps_c[2]);

	}

	// Multiplies vector by scalar
	vector3 mult(vector3 a, float b) {
		vector<float> comps_a = v_comps(a);
		vector<float> comps_c;

		for (int n; n<3; n++) {
			comps_c[n] = comps_a[n]*b;
		}
		vector3 v1 = vfc_3d(comps_c[0],comps_c[1],comps_c[2]);
		return v1;
	}

	float div_v(vector3 a, vector3 b) {
		vector<float> comps_a = v_comps(a);
		vector<float> comps_b = v_comps(b);
		vector<float> comps_c;
		float result;

		for (int n; n<3; n++) {
			comps_c[n] = comps_a[n]/comps_b[n];
		}
		for (int n; n<3; n++) {
			result += comps_c[n];
		}
		return result;

	}

	// Divides vector by scalar
	vector3 div(vector3 a, float b) {
		vector<float> comps_a = v_comps(a);
		vector<float> comps_c;

		for (int n; n<3; n++) {
			comps_c[n] = comps_a[n]/b;
		}
		vector3 v1 = vfc_3d(comps_c[0],comps_c[1],comps_c[2]);
		return v1;
	}

	// Normalizes vector, turns into unit vector
	vector3 normalize(vector3 v1) {
		vector3 v2 = div(v1,v1.magnitude);
		return v2;
	}


}

// a rocket mAAAAAAAAn

// 12/15/2021 mm/dd/yyyy. THIS SHIT CAUSED SUCH AN ANNOYING ILLEGAL INSTRUCTION ISTG THIS WAS SO ANNOYING

// 12/18/2021 mm/dd/yy This actually was a pretty easy fix, you ended up switching to this anyways you fucking dumbass lmfao. Now i have to deal with being able to get nagles and magnitude now tho, still an easy fix. But tryna implement orbits is fuckin annoying.
namespace c_vector {
	// "Coordinate vector 3", instead of having an magnitude and angle you initialize it with pre-set components. e.g [1,0,0]
	struct c_vector {
		float x;
		float y;
		float z;
	};

	c_vector create(float x, float y, float z) {
		c_vector v1;
		v1.x = x;
		v1.y = y;
		v1.z = z;
		return v1;
	}

	double magnitude(c_vector a) {
		double magnitude = pythag_3d(a.x,a.y,a.z,0,3);
		return magnitude;
	}

	// std::vector<vector> matrices_definition(Matrix a) {
	// 	std::vector<vector> vectors;
	// 	for (int i; i < a.values.size(); i++) {
	// 		vectors[i] = create(a.values[i]);
	// 	}
	// 	return vectors;
	// }

	// vector matrix_definition(Matrix a) {
	// 	vector b = create(a.values[0]);

	// 	return b;
	// }

	c_vector product(c_vector v1, float v2) {
		c_vector v3;
		v3.x = v1.x * v2;
		v3.y = v1.y * v2;
		v3.z = v1.z * v2;
		return v3;
	}

	c_vector sum(c_vector a, c_vector b) {
		c_vector c;
		c.x = a.x + b.x;
		c.y = a.y + b.y;
		c.z = a.z + b.z;
		return c;
	}

	c_vector sub(c_vector a, c_vector b) {
		c_vector c;
		c.x = a.x - b.x;
		c.y = a.y - b.y;
		c.z = a.z - b.z; 
		return c;
	}

	c_vector mult(c_vector a, float b) {
		c_vector c;
		c.x = a.x * b;
		c.y = a.y * b;
		c.z = a.z * b;
		return c;
	}

	c_vector div(c_vector a, float b) {
		c_vector c;
		c.x = a.x / b;
		c.y = a.y / b;
		c.z = a.z / b;
		return c;
	}

	vector3::vector3 convert(c_vector a) {
		vector3::vector3 v1 = vector3::vfc_3d(a.x, a.y, a.z);
		return v1;
	}

	c_vector convert2(vector3::vector3 a) {
		c_vector b;
		vector<float> pos2 = vector3::v_comps(a);
		b.x = pos2[0];
		b.y = pos2[1];
		b.z = pos2[2];
		return b;
	}

	c_vector normalize(c_vector a) {
		vector3::vector3 v1 = convert(a);		
		vector3::vector3 v2 = vector3::normalize(v1);
		c_vector v3 = convert2(v2);
		return v3;
	}


	// float mult_v(c_vector a, c_vector b) {
	// 	vector3::vector3 v1 = convert(a);
	// 	vector3::vector3 v2 = convert(b);
	// 	float result = vector3::mult_v(v1,v2);
	// 	return result;
	// }


	// float div_v(c_vector a, c_vector b) {
	// 	vector3::vector3 v1 = convert(a);
	// 	vector3::vector3 v2 = convert(b);
	// 	float result = vector3::div_v(v1,v2);
	// 	return result;
	// }



	/* Function to create vectors so you dont have to do

		vector2 a = vfc(3,4) 
		or
		vector2 a;
		a.magnitude = so and so;
		a.angle = so and so;

		Instead you just do

		vector2 a = createVector2(2,30);
		and with the previous one you can just do

		c_vector3 a = vector3(1,0,1);

	*/

}

struct field_vector {
	vector2::vector2 vector;
	std::vector<float> pos;
};

namespace field2 {

	class field2 {
		public:
			std::vector<float> (*function)(float,float);
			
			vector2::vector2 fieldf (float x, float y, std::vector<float> (*func)(float, float)) {
				std::vector<float> comps = func(x,y);
				vector2::vector2 v1 = vector2::vfc(comps[0], comps[1]);
				function = func;	
				
				return v1;
			}
	};


	field2 create(std::vector<float> (*func)(float,float)) {
		field2 f1;
		f1.function = func;
		return f1;
	}
	
}

namespace field3 {

	// vector field, useful for gravitation and fluid dynamics
	class field3 {
		public:
			std::vector<float> (*function)(float,float,float);
			
			// Iniates a field with a pointer to a function. The function is then saved. Or i think it is. Idk complicated function pointer bullshit.
			void fieldf_init (std::vector<float> (*func)(float, float,float)) {
				function = func;	
			}

			c_vector::c_vector field (float x, float y, float z) {
				std::vector<float> comps = function(x,y,z);
				c_vector::c_vector v1 = c_vector::create(comps[0], comps[1], comps[2]);
				return v1;
			}
	};

	field3 create(std::vector<float> (*func)(float,float,float)) {
		field3 f1;
		f1.function = func;
		return f1;
	}
	
}

// struct mesh {
// 	vector<triangle> tris;
// };
