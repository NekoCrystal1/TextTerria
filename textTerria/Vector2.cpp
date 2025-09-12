#include "Vector2.h"

Vector2::Vector2(float x, float y) :x(x), y(y) {
}
Vector2::Vector2(float d) : x(d),y(d){
}
Vector2::Vector2(const Vector2& vec) :x(vec.x), y(vec.y) {
}
Vector2::~Vector2() {
}

inline const float Vector2::length() const
{
	return sqrt(x * x + y * y);
}

inline const Vector2& Vector2::normalize()
{
	float len = sqrt(x * x + y * y);
	x /= len;
	y /= len;
	return *this;
}

inline const Vector2& Vector2::only_multiply_every_element_modify_self(const Vector2& vec)
{
	x *= vec.x;
	y *= vec.y;
	return *this;
}

inline const Vector2& Vector2::only_multiply_every_element_modify_self(float num)
{
	x *= num;
	y *= num;
	return *this;
}

inline Vector2 Vector2::only_multiply_every_element(const Vector2& vec) const
{
	return Vector2(x * vec.x,y * vec.y);
}

inline Vector2 Vector2::absolute()
{
	Vector2 ans(x,y);
	if (x < 0)
		ans.x = -x;
	if (y < 0)
		ans.y = -y;
	return ans;
}

inline Vector2 Vector2::operator+(const Vector2& vec) const
{
	return Vector2(x + vec.x, y + vec.y);
}

inline Vector2 Vector2::operator-(const Vector2& vec) const
{
	return Vector2(x - vec.x, y - vec.y);
}

inline Vector2 Vector2::operator*(const float s) const
{
	return Vector2(x * s, y * s);
}

inline float Vector2::operator*(const Vector2& vec) const
{
	return x * vec.x + y * vec.y;
}

inline Vector2& Vector2::operator=(const Vector2& vec)
{
	x = vec.x;
	y = vec.y;
	return *this;
}

inline Vector2& Vector2::operator+=(const Vector2& vec)
{
	x += vec.x;
	y += vec.y;
	return *this;
}

inline bool Vector2::operator>(const Vector2& vec) const
{
	if (x > vec.x && y > vec.y)
		return true;
	return false;
}

inline bool Vector2::operator>=(const Vector2& vec) const
{
	if (x >= vec.x && y >= vec.y)
		return true;
	return false;
}

inline bool Vector2::operator<(const Vector2& vec) const
{
	if (x < vec.x && y < vec.y)
		return true;
	return false;
}

inline bool Vector2::operator<=(const Vector2& vec) const
{
	if (x <= vec.x && y <= vec.y)
		return true;
	return false;
}



