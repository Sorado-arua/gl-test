//
// Created by Administrator on 9/11/2025.
//

#ifndef GL_EASESINE_H
#define GL_EASESINE_H


#include "Animationutil.h"

class Easesine: public Animationutil {
private:
public:
    Easesine(double p_ms, double p_endPoint, Direction p_direction) : Animationutil(p_ms, p_endPoint, p_direction){
    };

    ~Easesine(){};

    bool correctOutput() {
        return true;
    }
//overwrite the math function
    virtual double getEquation(double x)const override {
        return sin(x * 3.14156926f / 2);}
} ;
#endif //GL_EASESINE_H
