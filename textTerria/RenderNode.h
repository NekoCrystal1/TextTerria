#pragma once
#include "Transform.h"
#include <vector>
class RenderNode
{
public:
	RenderNode();
	virtual ~RenderNode();
public:
	virtual void onRender();
	//自动根据层级添加
	void addNode(RenderNode* pNextNode);
	//直接尾插：将会改变目标层级为最高层
	void pushBack(RenderNode* pNextNode);
	void setOrder(int i32Order);
private:
	//当前渲染层级：渲染顺序，先渲染当前节点，然后渲染子节点，子节点排序根据层级由小到大排序，因此先渲染层级小的，默认0级
	int m_Order;
	Transform m_Transform;
	//根据层级从小到大排序，层级越小越先渲染；同层级会根据加入顺序决定；移除当前节点会将子节点都移除
	std::vector<RenderNode*> m_vecNextNodes;
	//改变层级后会调整父层级中的列表
	RenderNode* m_pParentNode;
};