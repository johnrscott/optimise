#include <iostream>
#include "optim.hpp"

// This the the objective function
//
// - The first argument is the set of variables you're optimising
//   over (an arma::vec)
// - The second argument is the gradient. Ignored.
// - The last argument is for other parameters (things you're not
//   optimising over but you need anyway)
//
// As an example the objective function:
//
//   obj = (x[0] - y[0])^2 + (x[1] - y[1])^2
//       + (x[2] - y[2])^2 + (x[3] - y[3])^2
//
// The arma::vec x contains what you're optimising over and
// y contains parameters you want to pass to the objective function
//
double obj(const arma::vec & x, arma::vec * grad_out, void * opt_data) {
  // The optional parameters (opt_data) has type void* so that you can pass
  // anything into it. In this case, arma::vec
  arma::vec y = * static_cast<arma::vec* >(opt_data);
  // Calculate the objective function:
  double value = 0;
  for(int n=0; n<4; n++)
    value += (x[n] - y[n])*(x[n] - y[n]);
  // Return the value of the function
  return value;

}


int main () {

  // x contains the optimisation variables
  // y contains parameters
  arma::vec x{0,0,0,0};
  arma::vec y{1,2,3,4};

  // This is simpler than nlopt
  optim::nm(x, obj, &y);

  // Print the results. There's probably a right
  // way to print vectors 
  std::cout << "Here is y: ["
	    << y[0] << ", "
	    << y[1] << ", "
	    << y[2] << ", "
	    << y[3] << "] "
	    << std::endl;
  std::cout << "Here is the result of the optimisation: ["
	    << x[0] << ", "
	    << x[1] << ", "
	    << x[2] << ", "
	    << x[3] << "] "
	    << std::endl;

  
  return 0;
}
