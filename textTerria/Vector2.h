#pragma once
#include "algorithm"
#include "math.h"

class Vector2 {
public:
	Vector2(float x, float y);
	Vector2(float d = 0);
	Vector2(const Vector2& vec);
	~Vector2();
	const float length() const;
	const Vector2& normalize();//标准化
	const Vector2& only_multiply_every_element_modify_self(const Vector2& vec);
	const Vector2& only_multiply_every_element_modify_self(float num);
	//如果乘一个实数请用*
	Vector2 only_multiply_every_element(const Vector2& vec)const;

	Vector2 absolute();
	Vector2 operator+(const Vector2& vec) const;
	Vector2 operator+(float fVal) const;
	Vector2 operator-(const Vector2& vec) const;
	Vector2 operator-()const;
	Vector2 operator*(float s) const;
	float operator*(const Vector2& vec) const;
	Vector2 operator/(const Vector2& vec) const;
	Vector2& operator=(const Vector2& vec);
	Vector2& operator+=(const Vector2& vec);
	Vector2& operator*=(const Vector2& vec);
	Vector2& operator/=(const Vector2& vec);
	//严格大于(x，y均大于）
	bool operator>(const Vector2& vec)const;
	bool operator>=(const Vector2& vec)const;
	//严格小于(x，y均小于）
	bool operator<(const Vector2& vec)const;
	bool operator<=(const Vector2& vec)const;
public:
	float x,y;
};