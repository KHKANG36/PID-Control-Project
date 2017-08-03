#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	
	//Initialize the coefficient
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;

	//Initialize the error
	p_error = 0;
	i_error = 0;
	d_error = 0;

	//Initialize the previous cte
	prev_cte = 0;

}

void PID::UpdateError(double cte) {

	//Error Update
	p_error = cte;
	i_error += cte;
	d_error = cte - prev_cte;

	prev_cte = cte;
	
}

double PID::TotalError() {


	//Total Error 
	return -Kp*p_error -Ki*i_error - Kd*d_error;

}
