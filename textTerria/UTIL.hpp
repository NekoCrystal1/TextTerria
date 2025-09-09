#pragma once
#include <easyx.h>
#include "Transform.h"
inline bool check_point_in_rectangle(const Vector2& point, const Vector2& range1, const Vector2& range2) {
	if (point.x > (range1.x < range2.x ? range1.x : range2.x) && point.x < (range1.x > range2.x ? range1.x : range2.x) &&
		point.y >(range1.y < range2.y ? range1.y : range2.y) && point.y < (range1.y > range2.y ? range1.y : range2.y))
		return true;
	return false;
}
inline bool check_point_in_rectangle(const Vector2& point, const Transform& range) {
	return check_point_in_rectangle(point, range.get_position(), range.get_size() + range.get_position());
}