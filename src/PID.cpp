#include "PID.h"
#include <stddef.h>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;

	int_cte = 0;
	prev_cte = 0;
	has_prev_cte = false;
}

void PID::UpdateError(double cte) {

	if (!has_prev_cte)
	{
		prev_cte = cte;
		has_prev_cte = true;
	}

	auto diff_cte = cte - prev_cte;
	prev_cte = cte;
	int_cte += cte;

	p_error = -cte * Kp;
	d_error = -diff_cte * Kd;
	i_error = -int_cte * Ki;
}

double PID::TotalError() {
	return p_error + d_error + i_error;
}

