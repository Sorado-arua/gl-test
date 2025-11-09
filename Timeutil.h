//
// Created by Administrator on 9/11/2025.
//

#ifndef GL_TIMEUTIL_H
#define GL_TIMEUTIL_H


#include "GLFW/glfw3.h"

class Timeutil {
private:
    double m_lasttime;
    double m_elapsetime;
public:
Timeutil():m_lasttime((float)glfwGetTime()){
};
~Timeutil(){};
void setTime(double time){
    m_lasttime=time;
};
void reset(){
        m_lasttime=(float)glfwGetTime();
    };
void elapseTime(double time){
m_elapsetime=(float)glfwGetTime()-m_lasttime;
};
//
    inline double getElapseTime() const {
        return m_elapsetime;
    };
    bool hasTimeElapsed(double p_time) {
        if ((double)glfwGetTime() - m_lasttime >= p_time) {
            return hasTimeElapsed((long) p_time);
        };};};
#endif //GL_TIMEUTIL_H
