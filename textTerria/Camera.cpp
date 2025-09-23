#include "Camera.h"

const static Vector2 CAMERA_SCALE_VELOCITY = { 1.02, 1.02 };

Camera::Camera(): RenderNode(Vector2(getwidth(), getheight()), Vector2()), vision_scale(1.0f)
{
	*m_pWorldTransform = *m_pLocalTransform;
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

void Camera::on_update()
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
	if (add_pos.x != 0 || add_pos.y != 0)
	{
		m_pLocalTransform->set_position(m_pLocalTransform->get_position() + add_pos);
		makeDirty();
	}
	float modify_scale = add_scale - sub_scale;
	if (modify_scale != 0)
	{
		Vector2 oLastSize = m_pLocalTransform->get_size();
		if (modify_scale > 0)
		{
			vision_scale *= CAMERA_SCALE_VELOCITY;
			m_pLocalTransform->set_scale(m_pLocalTransform->get_scale() / CAMERA_SCALE_VELOCITY);
		}
		else if(modify_scale < 0)
		{
			vision_scale /= CAMERA_SCALE_VELOCITY;
			m_pLocalTransform->set_scale(m_pLocalTransform->get_scale().only_multiply_every_element(CAMERA_SCALE_VELOCITY));
		}
		m_pLocalTransform->set_position(m_pLocalTransform->get_position() -
			(m_pLocalTransform->get_size() - oLastSize) / 2);
		makeDirty();
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
	const Transform& cameraTransform = getWorldTransform();
	return (centre_position - cameraTransform.get_centre_position()).only_multiply_every_element(vision_scale);
}

Vector2 Camera::transformRenderSize(const Vector2& size) 
{
	return size.only_multiply_every_element(vision_scale);
}

Transform Camera::transformRenderTransform(const Transform& target_transform)
{
	Transform ans = target_transform;
	const Transform& cameraTransform = getWorldTransform();
	ans.set_size(target_transform.get_size().only_multiply_every_element(vision_scale));
	ans.set_centre_position(
		(target_transform.get_centre_position() - cameraTransform.get_centre_position() + m_pLocalTransform->get_size() / 2).
		only_multiply_every_element(vision_scale));
	return ans;
}

void Camera::updateTransform()
{
	if (!m_pParentNode)
	{
		m_pWorldTransform->set_centre_position(m_pLocalTransform->get_centre_position());
		m_pWorldTransform->set_rotation(m_pLocalTransform->getRotation());
		return;
	}
	const Transform& pParentTransform = m_pParentNode->getWorldTransform();
	m_pWorldTransform->set_centre_position(m_pLocalTransform->get_position() + pParentTransform.get_centre_position());
	m_pWorldTransform->set_rotation(m_pLocalTransform->getRotation() + pParentTransform.getRotation());
}
