#include "Vector2.h"

Vector2::Vector2(float x, float y) :x(x), y(y) {
}
Vector2::Vector2(float d) : x(d),y(d){
}
Vector2::Vector2(const Vector2& vec) :x(vec.x), y(vec.y) {
}
Vector2::~Vector2() {
}

const float Vector2::length() const
{
	return sqrt(x * x + y * y);
}

const Vector2& Vector2::normalize()
{
	float len = sqrt(x * x + y * y);
	x /= len;
	y /= len;
	return *this;
}

const Vector2& Vector2::only_multiply_every_element_modify_self(const Vector2& vec)
{
	x *= vec.x;
	y *= vec.y;
	return *this;
}

const Vector2& Vector2::only_multiply_every_element_modify_self(float num)
{
	x *= num;
	y *= num;
	return *this;
}

Vector2 Vector2::only_multiply_every_element(const Vector2& vec) const
{
	return Vector2(x * vec.x,y * vec.y);
}

Vector2 Vector2::absolute()
{
	Vector2 ans(x,y);
	if (x < 0)
		ans.x = -x;
	if (y < 0)
		ans.y = -y;
	return ans;
}

Vector2 Vector2::operator+(const Vector2& vec) const
{
	return Vector2(x + vec.x, y + vec.y);
}

Vector2 Vector2::operator+(float fVal) const
{
	return Vector2(x + fVal, y + fVal);
}

Vector2 Vector2::operator-(const Vector2& vec) const
{
	return Vector2(x - vec.x, y - vec.y);
}

Vector2 Vector2::operator-() const
{
	return Vector2(-x,-y);
}

Vector2 Vector2::operator*(float s) const
{
	return Vector2(x * s, y * s);
}

float Vector2::operator*(const Vector2& vec) const
{
	return x * vec.x + y * vec.y;
}

Vector2 Vector2::operator/(const Vector2& vec) const
{
	return Vector2(x / vec.x, y / vec.y);
}

Vector2& Vector2::operator=(const Vector2& vec)
{
	x = vec.x;
	y = vec.y;
	return *this;
}

Vector2& Vector2::operator+=(const Vector2& vec)
{
	x += vec.x;
	y += vec.y;
	return *this;
}

Vector2& Vector2::operator*=(const Vector2& vec)
{
	x *= vec.x;
	y *= vec.y;
	return *this;
}

Vector2& Vector2::operator/=(const Vector2& vec)
{
	x /= vec.x;
	y /= vec.y;
	return *this;
}

bool Vector2::operator>(const Vector2& vec) const
{
	if (x > vec.x && y > vec.y)
		return true;
	return false;
}

bool Vector2::operator>=(const Vector2& vec) const
{
	if (x >= vec.x && y >= vec.y)
		return true;
	return false;
}

bool Vector2::operator<(const Vector2& vec) const
{
	if (x < vec.x && y < vec.y)
		return true;
	return false;
}

bool Vector2::operator<=(const Vector2& vec) const
{
	if (x <= vec.x && y <= vec.y)
		return true;
	return false;
}
