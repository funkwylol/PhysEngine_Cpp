#pragma once
#include <math.h>
#include <iostream>
#include <vectors.h>
#include <Dynamics.h>

struct sphere {
	object object;
	c_vector::c_vector pos;
	float radius;
};

struct plane {
	c_vector::c_vector pos;
	c_vector::c_vector width;
	c_vector::c_vector height;
	c_vector::c_vector depth;
};

struct rectangle {
	c_vector::c_vector pos;
	c_vector::c_vector p1;
	c_vector::c_vector p2;
};

struct cube {
	object object;
	c_vector::c_vector pos;
	float size;
};

struct triangle {
	c_vector::c_vector points[3];
};

namespace sphereCollider {
	bool checkCollisionSphere(sphere a, sphere b) {
		if (c_vector::magnitude(c_vector::sub(a.pos, b.pos)) <= a.radius + b.radius) {
			return true;
		}
		else if (c_vector::convert(c_vector::sub(a.pos, b.pos)).magnitude > a.radius + b.radius) {
			return false;
		}
		return false;
	}
	bool checkCollisionPlane(sphere a, sphere b) {
		if (c_vector::convert(c_vector::sub(a.pos, b.pos)).magnitude <= a.radius + b.radius) {
			return true;
		}
		else if (c_vector::convert(c_vector::sub(a.pos, b.pos)).magnitude > a.radius + b.radius) {
			return false;
		}
		return false;
	}

}