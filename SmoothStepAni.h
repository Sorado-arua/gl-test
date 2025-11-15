//
// Created by Administrator on 14/11/2025.
//

#ifndef GL_SMOOTHSTEPANI_H
#define GL_SMOOTHSTEPANI_H

#include <valarray>
#include "Animationutil.h"

class SmoothStepAni : Animationutil{
private:
public:
    SmoothStepAni(int p_ms,double p_endPoint,Direction p_direction):  Animationutil(p_ms, p_endPoint, p_direction){};
~SmoothStepAni(){};
//overwrite math method;
virtual double getEquation(double x)const override{
        return -2 * std::pow(x, 3) + (3 * pow(x, 2));
}
};


#endif //GL_SMOOTHSTEPANI_H
