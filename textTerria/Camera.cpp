#include "Camera.h"

const static Vector2 CAMERA_SCALE_VELOCITY = { 1.02, 1.02 };

Camera::Camera(): TEntityObject(Vector2(getwidth(), getheight()), Vector2()), vision_scale(1.0f)
{
}

void Camera::on_input(ExMessage& msg)
{
	switch (msg.message)
	{
	case WM_KEYDOWN:
		switch (msg.vkcode)
		{
		case VK_UP:
			up = true;
			break;
		case VK_DOWN:
			down = true;
			break;
		case VK_LEFT:
			left = true;
			break;
		case VK_RIGHT:
			right = true;
			break;
		case VK_ADD:
			add_scale = true;
			break;
		case VK_SUBTRACT:
			sub_scale = true;
			break;
		}
		break;
	case WM_KEYUP:
		switch (msg.vkcode)
		{
		case VK_UP:
			up = false;
			break;
		case VK_DOWN:
			down = false;
			break;
		case VK_LEFT:
			left = false;
			break;
		case VK_RIGHT:
			right = false;
			break;
		case VK_ADD:
			add_scale = false;
			break;
		case VK_SUBTRACT:
			sub_scale = false;
			break;
		}
		break;
	}
}

void Camera::on_uodate()
{
	Vector2 add_pos;
	if (up)
		add_pos.y -= 10;
	if (down)
		add_pos.y += 10;
	if (left)
		add_pos.x -= 10;
	if (right)
		add_pos.x += 10;
	m_pLocalTransform->set_position(m_pLocalTransform->get_position() + add_pos);
	float modify_sclae = add_scale - sub_scale;
	if (modify_sclae > 0)
	{
		vision_scale *= CAMERA_SCALE_VELOCITY;
		m_pLocalTransform->set_scale(m_pLocalTransform->get_scale() / CAMERA_SCALE_VELOCITY);
	}
	else if(modify_sclae < 0)
	{
		vision_scale /= CAMERA_SCALE_VELOCITY;
		m_pLocalTransform->set_scale(m_pLocalTransform->get_scale() * CAMERA_SCALE_VELOCITY);
	}
}

bool Camera::isShouldRender(const Transform& transform)
{
	const Transform& selfTransform = getWorldTransform();
	//判断两矩形是否重叠
	if ((selfTransform.get_centre_position() - selfTransform.get_centre_position()).absolute() * 2 <
		(selfTransform.get_size() + transform.get_size()))
	{
		return true;
	}
	return false;
}

const Vector2& Camera::get_centre()
{
	return getWorldTransform().get_centre_position();
}

const Vector2& Camera::get_position()
{
	return getWorldTransform().get_position();
}

const Vector2& Camera::get_vision_scale()
{
	return vision_scale;
}

Vector2 Camera::transformRenderCentre(const Vector2& centre_position) 
{
	//渲染中心 = ( 对象中心 - 相机中心 )  * 缩放-> 先求向量，再缩放向量：得到的是屏幕坐标
	return (centre_position - getWorldTransform().get_centre_position()).only_multiply_every_element(vision_scale) +
		getWorldTransform().get_centre_position();
}

Vector2 Camera::transformRenderSize(const Vector2& size) 
{
	return size.only_multiply_every_element(vision_scale);
}

Transform Camera::transformRenderTransform(const Transform& target_transform)
{
	Transform ans = target_transform;
	ans.set_size(target_transform.get_size().only_multiply_every_element(vision_scale));
	ans.set_centre_position(
		(target_transform.get_centre_position() - getWorldTransform().get_centre_position()).only_multiply_every_element(vision_scale) +
		getWorldTransform().get_centre_position()
	);
	return ans;
}

void Camera::updateTransform()
{
	if (!m_pParentNode)
	{
		return;
	}
	m_pWorldTransform->set_centre_position(m_pLocalTransform->get_centre_position() + m_pParentNode->getWorldTransform().get_centre_position());
	m_pWorldTransform->set_rotation(m_pLocalTransform->getRotation() + m_pParentNode->getWorldTransform().getRotation());
}
