#pragma once
#include "../include/vectors.h"
//#include <matrix.h>
#include <vector>
#include <algorithm>

struct object {
	c_vector::c_vector position;
	c_vector::c_vector velocity;
	c_vector::c_vector force;
	float mass;
	int id;
	
};

c_vector::c_vector up = c_vector::create(0,0,1);
c_vector::c_vector down = c_vector::create(0,0,-1);
c_vector::c_vector east = c_vector::create(1,0,0);
c_vector::c_vector west = c_vector::create(-1,0,1);
c_vector::c_vector north = c_vector::create(0,1,0);
c_vector::c_vector south = c_vector::create(0,-1,0);

namespace PhysicsWorld  {

	float dt;
	bool gravity = false;
	bool friction = false;

	const c_vector::c_vector m_gravity = c_vector::create(0,0,-9.8);
	std::vector<object> m_objects;
	//object m_objects[21474];
 
	void addObject (object obj) {
		m_objects.push_back(obj);
	}

	void removeObject(object obj) {
		m_objects.erase(m_objects.begin()+obj.id);
	}

	object step(float deltaTime, object objec) {
		if (gravity == true) {
			objec.force = c_vector::sum(objec.force, m_gravity);
		}

		objec.velocity = c_vector::mult(c_vector::div(objec.force,objec.mass),deltaTime);
		objec.position = c_vector::mult(objec.velocity, deltaTime);
		
		return objec;
	}

	void init() {
		dt = 0;
		object m_object;
		m_object.mass = -1;
		addObject(m_object);
		m_object.id = 0;
		for (int i = 1; i < m_objects.size(); i++) {
			m_objects[i].id = m_objects[i-1].id + 1;
		}
	}

}











// Wasnt the kind of place, to raise your kids

// In fact its cold as hell
