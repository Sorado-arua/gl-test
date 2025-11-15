//
// Created by Administrator on 15/11/2025.
//

#ifndef GL_DECELEBRATEANI_H
#define GL_DECELEBRATEANI_H


#include "Animationutil.h"

class DecelebrateAni : Animationutil{
private:
public:
    DecelebrateAni(int p_ms,double p_endPoint,Direction p_direction): Animationutil(p_ms,p_endPoint,p_direction){};
~DecelebrateAni(){};
//overwrite math method
    virtual double getEquation(double x)const override {
        return 1 - ((x - 1) * (x - 1));
    };};
#endif //GL_DECELEBRATEANI_H
