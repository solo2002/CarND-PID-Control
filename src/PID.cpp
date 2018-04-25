#include "PID.h"
#include <cmath>
#include <iostream>

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

	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;

	previous_cte = 0.0;
	number_of_step = 1;
	best_err = std::numeric_limits<double>::max();

}

void PID::UpdateError(double cte) {
	
	// number_of_step = 1;
	// previous_cte = cte;
	// p_error = cte;
	// d_error = cte - previous_cte;
	// i_error += cte;
	// double tolerance = 0.1;
	// double p[3] = {this->Kp, this->Kd, this->Ki};
	// double dp[3] = {1.0, 1.0, 1.0};//{this->Kp * 0.1, this->Kd * 0.1, this->Ki * 0.1}; 
	// //int step = 0;
	// double err = TotalError();
	// if (std::abs(cte) >= 0.1)
	// { //if the total error is very small, twiddle is unnecessary 
	// 	if (number_of_step % 1 == 0) 
	// 	{		
	// 		while (dp[0] + dp[1] + dp[2] > tolerance)
	// 		{
	// 			for(int i = 0; i < 3; i++) 
	// 			{
	// 				p[i] += dp[i];
	// 				if (err < best_err)
	// 				{
	// 					this->best_err = TotalError();
	// 					dp[i] *= 1.1;
	// 				}
	// 				else
	// 				{
	// 					p[i] -= 2 * dp[i];
	// 					if (TotalError() < this->best_err)
	// 					{
	// 						this->best_err = TotalError();
	// 						dp[i] *= 1.1;
	// 					}
	// 					else
	// 					{
	// 						p[i] += dp[i];
	// 						dp[i] *= 0.9;
	// 					}
	// 				}
	// 				number_of_step++;
	// 			}
	// 		}
	// 	}
	// }
	// this->Kp = p[0];
	// this->Kd = p[1];
	// this->Ki = p[2];

	d_error = cte - p_error;
  p_error = cte;
  i_error = i_error + cte;

	cout << "number of steps: " << number_of_step << endl;
  cout << "P: " << this->Kp << ", I: " << this->Ki << ", D: " << this->Kd << endl;  
  cout << "Total Error: " << TotalError() << endl;
}

double PID::TotalError() {
	return - Kp * p_error - Kd * d_error - Ki * i_error;

}


