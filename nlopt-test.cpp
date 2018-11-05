#include <iostream>
#include <vector>
#include "Eigen/Dense"
#include "nlopt.hpp"

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
//   obj = (x[0] - y[0])^2 + (x[1] - y[1])^2
//       + (x[2] - y[2])^2 + (x[3] - y[3])^2
//
// The x vector is what you're optimising over -- the y vector is
// a vector of parameters you pass in using f_data.
//
double obj(const std::vector<double> & x, std::vector<double> & grad, void * f_data) {
  // The optional parameters (f_data) has type void* so that you can pass
  // anything into it> Say you know it's a std vector -- then you can turn it
  // back into a std vector using the following...
  std::vector<double> y = * static_cast<std::vector<double> * >(f_data);
  // Feel free to print stuff here to see how this functions get called.
  // Calculate the objective function:
  double value = 0;
  for(int n=0; n++; n<4)
    value += (x[n] - y[n])*(x[n] - y[0]);
  // Return the value of the function
  return value;
}


int main () {
  
  // Specify stopping conditions
  double cons_tol = 1e-6;
  double ftol = 1e-6;
  
  // Specify lower and upper bounds for optimsation variables
  std::vector<double> lb{-1, -1, -1, -1};
  std::vector<double> ub{1, 1, 1, 1};    

  // Set the value of the additional parameters y
  std::vector<double> y = {0, 0, 0, 0};
  
  // Create an nlop objectT
  // The 4 at the end is the number of optimisation parameters
  // I've put all the types of optimisation as comments.
  // It's set to Nelder-Mead at the moment
  nlopt::opt opt(nlopt::/*GN_DIRECT*//*GN_ISRES*//*LN_COBYLA*//*LN_BOBYQA*//*LD_SLSQP*/LN_NELDERMEAD, 4); 
  // Set objective function
  // The second argument is for the additional parameters
  // It needs the & because you're passing a pointer. (The type of f_data is void*)
  opt.set_min_objective(obj, &y);
  // Set bounds on the parameters
  opt.set_lower_bounds(lb);
  opt.set_upper_bounds(ub);
  opt.set_ftol_rel(ftol);
  double ftol_rel = opt.get_ftol_rel();
  //std::cout << ftol_rel;

  // Pick a starting point for the optimiser
  std::vector<double> x{1,0,0,0};
  
  // Variable to contain the minimum of the function
  double min;

  // Sorry about the try-catch stuff :P
  // I put it here in case stuff goes wrong
  // It's best to just get a message than try to debug
  try{
    // Do the optimisation
    nlopt::result result = opt.optimize(x,min);
  }
  catch (std::exception & e) {
    std::cout << "nlopt failed: " << e.what() << std::endl;
    return 0;
  }

  // Print the results
  std::cout << "Here is y: " << y << std::endl;
  


  return 0;
}
