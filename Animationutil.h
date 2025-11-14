//
// Created by Administrator on 9/11/2025.
//

#ifndef GL_ANIMATIONUTIL_H
#define GL_ANIMATIONUTIL_H
#include "vender/Animation/Timeutil.h"

#include "vender/Animation/Timeutil.h"
#include <algorithm> // 为了 std::max/min

class Animationutil {
private:
    double m_duration;
    double m_endpoint;

public:
    enum class Direction {
        EnableUp,
        Disable
    };

    Direction direction;
    Timeutil timeutil;

    Animationutil(double p_ms, double p_endPoint, Direction p_direction)
            : m_duration(p_ms), m_endpoint(p_endPoint), direction(p_direction) {}

    virtual ~Animationutil() {}

    inline Direction opposite() {
        return (direction == Direction::EnableUp) ? Direction::Disable : Direction::EnableUp;
    }

    virtual double getEquation(double x) const = 0;

    bool isDone() {
        if (m_duration <= 0) return true;
        return timeutil.hasTimeElapsed(m_duration);
    }

    bool finished(Direction p_direction) {
        return isDone() && direction == p_direction;
    }

    void setDuration(double p_duration) {
        m_duration = p_duration;
    }

    void resetTime() {
        timeutil.reset();
    }

    inline double getendPoint() const {
        return m_endpoint;
    }

    inline void setendPoint(double p_endPoint) {
        m_endpoint = p_endPoint;
    }

    inline Direction getDirection() const {
        return direction;
    }

    inline double getOutput() {
        if (m_duration <= 0.0) {
            return (direction == Direction::EnableUp) ? m_endpoint : 0.0;
        }

        double progress = timeutil.getElapseTime() / m_duration;

        // 限制在 [0.0, 1.0] 范围内
        progress = std::max(0.0, std::min(progress, 1.0));

        double eased_value = getEquation(progress);

        if (direction == Direction::EnableUp) {
            return m_endpoint * eased_value;
        } else {
            return m_endpoint * (1.0 - eased_value);
        }
    }
};
#endif //GL_ANIMATIONUTIL_H

