//
// Created by Administrator on 21/11/2025.
//

#ifndef GL_GLBLENDSTATE_H
#define GL_GLBLENDSTATE_H

#include <string>
#include <iostream>

class GLBlendState{
private:
bool m_enabled;
int m_srcFactor;
int m_destFactor;
int m_srcFactorAlpha;
int m_destFactorAlpha;
public:
    GLBlendState(bool p_enabled,int p_srcFactor, int p_destFactor, int p_srcFactorAlpha, int p_destFactorAlpha):
    m_enabled( p_enabled),
    m_srcFactor (p_srcFactor),
    m_destFactor (p_destFactor),
    m_srcFactorAlpha (p_srcFactorAlpha),
    m_destFactorAlpha (p_destFactorAlpha){
    };
~GLBlendState(){};
void setEnabled(bool p_enabled) {
        m_enabled = p_enabled;
    };
void setEnabled() {
        m_enabled = true;
    };

void setDisabled() {
        m_enabled = false;
    };
void setFactors(int p_srcFactor, int p_destFactor, int p_srcFactorAlpha, int p_destFactorAlpha) {
        m_srcFactor = p_srcFactor;
        m_destFactor = p_destFactor;
        m_srcFactorAlpha = p_srcFactorAlpha;
        m_destFactorAlpha = p_destFactorAlpha;
    };

bool isEnabled() {
        return m_enabled;
    };

int getSrcFactor() {
        return m_srcFactor;
    };

int getDstFactor() {
        return m_destFactor;
    };

int getSrcFactorAlpha() {
        return m_srcFactorAlpha;
    };

int getDstFactorAlpha() {
        return m_destFactorAlpha;
    };

bool isSeparate() {
        return m_srcFactor != m_srcFactorAlpha || m_destFactor != m_destFactorAlpha;
    };
std::string toString()const {
    std::string boolStr = m_enabled ? "true" : "false";
    return "enabled: " + boolStr +
           ", src: " + std::to_string(m_srcFactor) +
           ", dest: " + std::to_string(m_destFactor) +
           ", srcAlpha: " + std::to_string(m_srcFactorAlpha) +
           ", destAlpha: " + std::to_string(m_destFactorAlpha);
};
    };
#endif //GL_GLBLENDSTATE_H
