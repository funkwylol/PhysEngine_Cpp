#include <iostream>
#include "../include/vectors.h"
//#include "../include/matrix.h"
#include <vector>
#include <algorithm>
#include "../include/Dynamics.h"
#include <fstream>
#include "pbPlots.hpp"
#include "supportLib.hpp"
#include "../include/collision.h"

int main() {

	float modifier;
	float time_limit;
	char key;
	int asciiValue;

	std::vector<std::vector<float>> points;
	std::vector<float> point;

	std::cout << "modifer: ";
	std::cin >> modifier;
	std::cout << "time limit: ";
	std::cin >> time_limit;
	
	std::ofstream data;
	data.open("data.txt", std::ios::in | std::ios::out);
	PhysicsWorld::init();
	PhysicsWorld::gravity = true;

	// Use actual code here

	object cube;
	sphere cube_sphere;
	cube_sphere.object = cube;
	object myass;
	sphere myass_sphere;
	cube_sphere.object = myass;
	cube.mass = 5;
	cube.force = c_vector::create(0,140*std::sqrt(3),140);
	cube.position = c_vector::create(0,0,0);

	PhysicsWorld::addObject(cube);

	std::cout << cube.id << std::endl;
	
	std::cout << PhysicsWorld::m_objects[1].mass << std::endl;
	
	while (PhysicsWorld::dt < time_limit) {
		for (int i = 0; i < PhysicsWorld::m_objects.size(); i++) {
			for (int j = 0; j < PhysicsWorld::m_objects.size(); i++) {
				if (sphereCollider::checkCollisionSphere(PhysicsWorld::m_objects[i],m_objects[j]) == true) {

				}
			}
		}
		std::cout << "repetition: " << PhysicsWorld::dt << std::endl;
		cube = PhysicsWorld::step(PhysicsWorld::dt,cube);
		point = {cube.position.x, cube.position.y, cube.position.z};
		points.push_back(point);
		data << "[" << cube.position.x << " , " << cube.position.y << " , " << cube.position.z << "]" << "\n";
		if (PhysicsWorld::dt + modifier == time_limit) {
			data << "end";
		}
		PhysicsWorld::dt += modifier;
	}

	

	// Oh no no no, Im a rocket man!

	// Rocketman!!!

	bool success;
    StringReference *errorMessage = new StringReference();
	RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();

	vector<double> xs;

	for (int i = 0; i < time_limit/modifier; i++) {
		xs.push_back(points[i][1]);
	}

	vector<double> ys;

	for (int i = 0; i < time_limit/modifier; i++) {
		ys.push_back(points[i][2]);
	}

	ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
	series->xs = &xs;
	series->ys = &ys;
	series->linearInterpolation = true;
	series->lineType = toVector(L"solid");
	series->lineThickness = 4;
	series->color = GetGray(0.3);

	ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
	settings->width = 1920;
	settings->height = 1080;
	settings->autoBoundaries = true;
	settings->autoPadding = true;
	settings->title = toVector(L"cube trajectory");
	settings->xLabel = toVector(L"X axis");
	settings->yLabel = toVector(L"Y axis");
	settings->scatterPlotSeries->push_back(series);

	success = DrawScatterPlotFromSettings(imageReference, settings, errorMessage);

    if (success) {
        vector<double> *pngdata = ConvertToPNG(imageReference->image);
        WriteToFile(pngdata, "example2.png");
        DeleteImage(imageReference->image);
	}
	else {
        cerr << "Error: ";
        for(wchar_t c : *errorMessage->string){
            wcerr << c;
        }
        cerr << endl;
	}

	// while (1) {
	// 	key = getch();
	// 	asciiValue = key;

	// }

	points.clear();
	data.close();
	std::cout.flush();
	return 0;
	
}