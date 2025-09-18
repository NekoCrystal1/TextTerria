#pragma once
#include <string>
#include <unordered_map>
template<typename T>
class TNodeManagerInterface
{
protected:
	TNodeManagerInterface();
	virtual ~TNodeManagerInterface();
public:
	//获取添加新的根节点，如果不存在则添加并返回该根节点，如果已存在则返回且不会添加新节点
	T* getAndAddRoot(std::string sNodeName);
	//查找根节点，如果不存在则返回nullptr且不会添加新节点
	T* getRootNode(std::string sNodeName);
	T* getCruWorkNode();
	//传入nullptr会被重定向为VirtualNode
	void setCurWorkNode(T* pWorkNode);
protected:
	//负责持有所有根节点
	std::unordered_map<std::string, T*> m_mapRenderRoots;
	T* m_pCurWorkNode;
};

template<typename T>
inline TNodeManagerInterface<T>::TNodeManagerInterface() : m_pCurWorkNode(nullptr)
{
	m_pCurWorkNode = getAndAddRoot("VirtualNode");
}

template<typename T>
inline TNodeManagerInterface<T>::~TNodeManagerInterface()
{
	for (auto i : m_mapRenderRoots)
	{
		delete i.second;
	}
	m_mapRenderRoots.clear();
}

template<typename T>
inline T* TNodeManagerInterface<T>::getAndAddRoot(std::string sNodeName)
{
	T* pNode = getRootNode(sNodeName);
	if (!pNode)
	{
		pNode = new T();
		m_mapRenderRoots.insert(std::pair<std::string, T*>(sNodeName, pNode));
	}
	return pNode;
}

template<typename T>
inline T* TNodeManagerInterface<T>::getRootNode(std::string sNodeName)
{
	auto ans = m_mapRenderRoots.find(sNodeName);
	if (ans != m_mapRenderRoots.end())
	{
		return ans->second;
	}
	return nullptr;
}

template<typename T>
inline T* TNodeManagerInterface<T>::getCruWorkNode()
{
	return m_pCurWorkNode;
}

template<typename T>
inline void TNodeManagerInterface<T>::setCurWorkNode(T* pWorkNode)
{
	if (pWorkNode)
	{
		m_pCurWorkNode = pWorkNode;
	}
	else
	{
		m_pCurWorkNode = getRootNode("VirtualNode");
	}
}
