//
//  Euler.h
//  QL_DNS
//
//  Created by Jonathan Squire on 8/19/14.
//  Copyright (c) 2014 J Squire. All rights reserved.
//

#ifndef __QL_DNS__Euler__
#define __QL_DNS__Euler__

#include "Integrator.h"
#include "../solution.h"


class Euler : public Integrator {
public:
    Euler(double t0, double dt, Model * mod);
    ~Euler();
    // Step
    void Step(double t, solution * sol);
    
private:
    const double dt_;
    const int nxy_, nz_;
    const int nMF_,nLin_;
    
    // Model
    Model * model_;
    
    // Space for integrator evaluation
    solution * sol_rhs_; // Output of model
    
    // Space for linear operator
    doubVec *linearOp_fluct_;
    doubVec *linearOp_MF_;
    
    // Pointer variables for evaluation - not very clean but couldn't think of a better way!
    dcmplx *dLin_,*dLin_rhs_;
    double *lin_op_;
};



#endif /* defined(__QL_DNS__Euler__) */
