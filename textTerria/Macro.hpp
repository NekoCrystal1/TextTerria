#pragma once
#include "Vector2.h"

//#define VECTOR2_MEMBER_READ_AND_WRITE(memberName, disPlayName) \
//public:\
//    void set_##disPlayName(const Vector2& value) { memberName = value; } \
//    void set_##disPlayName(float x, float y) { memberName.x = x; memberName.y = y; } \
//    void set_##disPlayName##_x(float x) { memberName.x = x; } \
//    void set_##disPlayName##_y(float y) { memberName.y = y; } \
//    const Vector2& get##disPlayName() { return memberName; } \
//protected:\
//    Vector2 memberName;


#define VECTOR2_MEMBER_READ_AND_WRITE(memberName, disPlayName) \
public: \
    void set##disPlayName(const Vector2& value) { memberName = value; } \
    void set##disPlayName(float x, float y) { memberName.x = x; memberName.y = y; } \
    void set##disPlayName##_x(float x) { memberName.x = x; } \
    void set##disPlayName##_y(float y) { memberName.y = y; } \
    const Vector2& get##disPlayName() const { return memberName; } \
    Vector2& get##disPlayName() { return memberName; } \
    float get##disPlayName##_x() const { return memberName.x; } \
    float get##disPlayName##_y() const { return memberName.y; } \
protected: \
    Vector2 memberName;