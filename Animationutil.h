//
// Created by Administrator on 9/11/2025.
//

#ifndef GL_ANIMATIONUTIL_H
#define GL_ANIMATIONUTIL_H
#include "vender/Animation/Timeutil.h"

class Animationutil  {
private:
    double m_duration;
    double m_endpoint;

public:
    enum class Direction {
        EnableUp,
        Disble
    };
    Direction direction;
    Animationutil(double p_ms, double p_endPoint, Direction p_direction):m_duration(p_ms),m_endpoint(p_endPoint),direction(p_direction){}
    ~Animationutil(){};
    Timeutil timeutil;

    inline Direction opposite() {
        if (direction == Direction::EnableUp) {
            return (direction == Direction::EnableUp) ? Direction::Disble : Direction::EnableUp;
        }
    };

//virtual
    virtual double getEquation(double x) const = 0;
//      eg:  std::cout << "Animal makes a generic sound..." << std::endl;
//bool
    bool isDone() {
        return timeutil.hasTimeElapsed(m_duration);
    }
    bool finished(Direction p_direction) {
        return isDone() && direction==p_direction;
    }
    bool correctOutput() {
        return false;
    }
//    void
    void setDuration(double p_duration) {
        m_duration = p_duration;
    }
    void resetTime() {
        timeutil.reset();
    }
//    get and set
//getter and setter
    inline double getLinearout() {
        return 1 - ((timeutil.getElapseTime() / (double) m_duration) * m_endpoint);
//`Elapsed Time` (已过总时间)”的公式
    }

    inline double getendPoint() {
        return m_endpoint;
    }

    inline double setendPoint(double p_endPoint) {
        m_endpoint = p_endPoint;
    }
    inline Direction getDirection() {
        return direction;
    }

    inline double getOutput() {
        if (direction == Direction::EnableUp) {
            if (isDone()) {
                return m_endpoint;//反向播放完毕，回到起点 0
            }
            // 反向播放的核心公式
            double calucate_progress = timeutil.getElapseTime() / (double) m_duration;
            return m_endpoint * getEquation(calucate_progress);
        } else {
            if (isDone()) {
                return 0.0;
            }
            if (correctOutput()) {
                double revTime = std::fmin(m_duration, std::fmax(0, m_duration - timeutil.getElapseTime()));
                return getEquation(revTime / (double) m_duration) * m_endpoint;}
            return (1 - getEquation(timeutil.getElapseTime() / (double) m_duration)) * m_endpoint;
        }
    }
};
#include <string>
#endif //GL_ANIMATIONUTIL_H
