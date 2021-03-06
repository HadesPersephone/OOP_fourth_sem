

#include <iostream>
#include <cstring>
#include "Vehicles.h"

//
// B A S E   C L A S S   I M P L E M E N T A T I O N
//

// CVehicle class implementation
#pragma region CVehicle class

// Constructors
CVehicle::CVehicle() : id(0), v_type(0), avr_speed(0), capacity(0), cost_per_mile(0) { }

CVehicle::CVehicle(int _id, int _v_type, double _avr_speed, double _capacity, double _cost_per_mile) :
	avr_speed(_avr_speed), capacity(_capacity), cost_per_mile(_cost_per_mile),
	id(_id), v_type(_v_type) { };

// Methods
int CVehicle::GetId() { return id; }

void CVehicle::SetCostPerMile(double newcost) {
	cost_per_mile = newcost;
}

#pragma endregion

//
// D E R I V E D   C L A S S E S   I M P L E M E N T A T I O N
//

// CCar class implementation
#pragma region CCar class

// Constructors
CCar::CCar(int _id, int _v_type, std::string _make, double _avr_speed, double _cost_per_mile,
	double _capacity, int _max_dist) : CVehicle(_id, _v_type, _avr_speed, _capacity, _cost_per_mile),
	make(_make), max_dist(_max_dist) { }

// Methods
void CCar::Display() {
	std::cout << "[" << id << "] " << v_type << "; " << make << "; " << capacity << "; " <<
		cost_per_mile << "; " << avr_speed << "; " << max_dist << ";\n";
}

double CCar::CalculateCost(int weight, int dist) {
	if (dist > max_dist) return -1.0;
	return weight * cost_per_mile * dist;
}

double CCar::CalculateTime(int dist) {
	if (dist > max_dist) return -1.0;
	return dist / avr_speed;
}

int CCar::GetId() { return id; }

void CCar::SetCostPerMile(double newcost) {
	cost_per_mile = newcost;
}

double CCar::GetAvrSpeed() { return avr_speed; }

int CCar::GetMaxDist() { return max_dist; }

#pragma endregion


// CTrain class implementation
#pragma region CTrain class

// Constructors
CTrain::CTrain(int _id, int _v_type, std::string _t_type, double _avr_speed, double _capacity, 
	double _cost_per_mile) : CVehicle(_id, _v_type, _avr_speed, _capacity, _cost_per_mile),
	type(_t_type) { }

// Methods
void CTrain::Display() {
	std::cout << "[" << id << "] " << v_type << "; " << type << "; " << capacity << "; " <<
		cost_per_mile << "; " << avr_speed << ";\n";
}

double CTrain::CalculateCost(int weight, int dist) {
	return weight *cost_per_mile * dist;
}

double CTrain::CalculateTime(int dist) {
	return dist / avr_speed;
}

int CTrain::GetId() { return id; }

void CTrain::SetCostPerMile(double newcost) {
	cost_per_mile = newcost;
}

double CTrain::GetAvrSpeed() { return avr_speed; }

#pragma endregion