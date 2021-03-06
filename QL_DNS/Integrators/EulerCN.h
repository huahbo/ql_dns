//
//  EulerCN.h
//  QL_DNS
//
//  Created by Jonathan Squire on 8/21/14.
//  Copyright (c) 2014 J Squire. All rights reserved.
//

#ifndef __QL_DNS__EulerCN__
#define __QL_DNS__EulerCN__

#include "Integrator.h"
#include "../solution.h"

class EulerCN : public Integrator {
public:
    EulerCN(double t0, double dt, Model * mod);
    ~EulerCN();
    // Step
    void Step(double t, solution * sol);
    
private:
    const double dt_;
    const int nxy_, nz_;
    const int nMF_, nLin_;
    
    // Model
    Model * model_;
    
    // Space for integrator evaluation
    solution * sol_rhs_; // Output of model
    
    // Space for linear operators
    doubVec *linearOp_fluct_,*linearOp_fluct_old_;
    doubVec *linearOp_MF_NLCo_,*linearOp_MF_LinCo_;
    
    // Pointer variables for evaluation - not very clean but couldn't think of a better way!
    dcmplx *dLin_,*dLin_rhs_;
    double *lin_op_, *lin_op_old_;
    doubVec denom;
};





#endif /* defined(__QL_DNS__EulerCN__) */
