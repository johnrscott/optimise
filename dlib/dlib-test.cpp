#include <iostream>
#include <vector>
#include <dlib/optimization.h>

// From the optimisation example program
typedef dlib::matrix<double,0,1> column_vector;

// This the the objective function
//
// - The first argument is the set of variables you're optimising
//   over (a std vector)
// - The second argument is the gradient (nope, none of that!).
//   I just ignore that variable.
// - The last argument is for other parameters (things you're not
//   optimising over but you need anyway)
//
// As an example the objective function is
//
//   obj = (x[0] - x[4])^2 + (x[1] - x[5])^2
//       + (x[2] - x[6])^2 + (x[3] - x[7])^2
//
// The first four elements of x are what you're optimising over
// -- the second four are a vector of parameters. NOPE
//
double obj(const column_vector & x) {
  // Calculate the objective function:
  double value = 0;
  column_vector y{1,1,1,1};
  for(int n=0; n<4; n++)
    value += (x(n) - y(n))*(x(n) - y(n));
  // Return the value of the function
  return value;
}

int main () {

  // The variables of optimisation
  column_vector x{0,0,0,0};
  
  // Do the optimisation -- see example optimisation program
  find_min_using_approximate_derivatives(dlib::bfgs_search_strategy(),
					 dlib::objective_delta_stop_strategy(1e-7),
					 obj, x, -1, 1e-7);

  // Print the result
  std::cout << "The result of the optimisation is: ["
	    << x(0) << ", "
	    << x(1) << ", "
	    << x(2) << ", "
	    << x(3) << "] "
	    << std::endl;
  
  return 0;
}
