//
// Created by Administrator on 9/11/2025.
//

#ifndef GL_TIMEUTIL_H
#define GL_TIMEUTIL_H


#include "GLFW/glfw3.h"

class Timeutil {
private:
    double m_lasttime;
public:
    Timeutil() : m_lasttime((double ) glfwGetTime()) {
    };

    ~Timeutil() {};
    inline double getElapseTime() const {
        return glfwGetTime() - m_lasttime;
    };

//if the running time =lastime that you need
    void setTime(double time) {
        m_lasttime = time;
    };

    void reset() {
        m_lasttime = (double ) glfwGetTime();
    };
    bool hasTimeElapsed(double p_time) {
        return getElapseTime() >= p_time;
    };
};
#endif //GL_TIMEUTIL_H
