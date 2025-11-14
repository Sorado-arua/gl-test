//
// Created by Administrator on 14/11/2025.
//

#ifndef GL_ELASTICANI_H
#define GL_ELASTICANI_H

#include <valarray>
#include "Animationutil.h"
//弹性Elastic
class ElasticAni: public  Animationutil{
private:
    float m_smooth;
    float m_easeAmount;
    bool m_isMore_Elasticity;
public:
    ElasticAni(int p_ms,double p_endPoint, float p_elasticity, float p_smooth, bool p_strength_elasticity,Direction p_direction): Animationutil(p_ms, p_endPoint,p_direction ){
        m_easeAmount = p_elasticity;
        m_smooth = p_smooth;
        m_isMore_Elasticity = p_strength_elasticity;
    };
~ElasticAni(){};
//overwrite the math function
    virtual double getEquation(double x)const override {
        x = std::pow(x, m_smooth);
        double m_elasticity = m_easeAmount * .1f;
        if (m_elasticity != 0) {
            return std::pow(2, -10 * (m_isMore_Elasticity ? sqrt(x) : x)) *
                   sin((x - (m_elasticity / 4)) * ((2 * 3.1415926f) / m_elasticity)) + 1;
        }
    }
};


#endif //GL_ELASTICANI_H
