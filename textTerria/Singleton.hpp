#pragma once

template<typename T>
class Singleton
{
public:
	static T* instance();
private:
	static T* m_pInstance;
protected:
	Singleton() = default;
	virtual ~Singleton();
	Singleton(Singleton<T>& s) = delete;
};

template<typename T>
T* Singleton<T>::m_pInstance = nullptr;

template<typename T>
inline T* Singleton<T>::instance()
{
	if (!m_pInstance)
	{
		m_pInstance = new T();
	}
	return m_pInstance;
}

template<typename T>
inline Singleton<T>::~Singleton()
{
	delete m_pInstance;
}
