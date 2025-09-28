#pragma once
#include "Vector2.h"
class Transform {
public:
	Transform(const Vector2& size = Vector2(), const Vector2& position = Vector2(),
		const Vector2& scale = Vector2(1), const Vector2& rotation = Vector2());
	Transform(const Transform& transform);
	~Transform();
	Transform& operator+= (const Transform& transform);
	Transform& operator= (const Transform& transform);
	Transform operator+ (const Transform& transform) const;
	Transform operator- (const Transform& transform) const;
	//实现各属性缩放
	Transform operator* (float fVal);
	//得到逻辑位置
	const Vector2& get_position()const;
	const Vector2& get_centre_position()const;
	const Vector2& get_anchor()const;
	const Vector2& get_size()const;
	const Vector2& get_scale()const;
	float getRotation()const;
	void set_anchor(const Vector2& oNewAcnhor);
	//设置逻辑坐标位置
	void setLogicPosition(const Vector2& pos);

	//设置原始左上角位置
	void setOriginPosition(const Vector2& pos);
	void setOriginPosition(float x,float y);
	void set_pos_x(float x);
	void set_pos_y(float y);
	void set_centre_position(const Vector2& centre);
	void set_size(const Vector2& size);
	void set_size(float x, float y);
	void set_size_x(float x);
	void set_size_y(float y);
	void set_scale(const Vector2& scale);
	void set_scale(float scale);
	void set_rotation(float rotation);
	//实现变换向另一变换的转换，并根据百分比决定转换程度
	void makeTransformTo(const Transform& transform, float perscentage);
protected:
	void refresh_scaled_size();
	void refresh_centre();
private:
	//顺时针为正方向，目前采用弧度数
	float rotation;
	Vector2 position;
	Vector2 size;//不可直接获取
	Vector2 scale;
	//position(左上角位置) + anchor = 逻辑position(成员)(对外暴露的)
	Vector2 anchor;//logic_position所在位置锚点

	//依赖于其他成员
	Vector2 scaled_size;
	Vector2 centre;
	Vector2 m_LogicPos;
};