#include <iostream>
#include <vector>
#include <dlib/optimization.h>

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

int main () {
  return 0;
}
