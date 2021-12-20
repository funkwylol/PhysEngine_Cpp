#include<vectors.h>
#include<Dynamics.h>


namespace gField {

	struct gField {
		object planet;
		
		c_vector::c_vector c_force(object a) {
			std::cout << "planet pos: " << c_vector::magnitude(planet.position);
			std::cout << "orbit boy pos: " << c_vector::magnitude(a.position);
			c_vector::c_vector r_vector = c_vector::sub(planet.position, a.position);
			vector3::vector3 b = c_vector::convert(r_vector);
			double r = c_vector::magnitude(r_vector);
			std::cout << "radius is: " << r;
			double c_f = ( 6.67408e-11 * a.mass * planet.mass ) / std::pow(r,2);
			std::cout << "force is: " << c_f;
			vector3::vector3 c = vector3::createVector3(c_f, b.angle1, b.angle2);
			double mag = c_vector::magnitude(r_vector);
			double mod = mag / c_f;
			c_vector::c_vector c_F = c_vector::convert2(c);
			return c_F; 
		}

		
	};

	object step (float deltaTime, gField a, object objec) {
		std::cout << "force is 2: " << a.c_force(objec).x << a.c_force(objec).y << a.c_force(objec).z;
		objec.force = c_vector::sum(objec.force, a.c_force(objec));
		std::cout << "step force: " << c_vector::magnitude(objec.force);
		objec.velocity = c_vector::mult(c_vector::div(objec.force,objec.mass),deltaTime);
		std::cout << "step velocity: " << c_vector::magnitude(objec.velocity);
		objec.position = c_vector::mult(objec.velocity, deltaTime);
			
		return objec;
	}

	gField create(object planet) {
		gField a;
		a.planet = planet;
		return a;
	}

}