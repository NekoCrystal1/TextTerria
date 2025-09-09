#pragma once
#include <functional>
class MilisecondTimer
{
public:
	MilisecondTimer(float end_frames = 1, bool is_one_shoot = true, std::function<void()> on_time_out = nullptr);
	~MilisecondTimer();
	void on_update(float delta = 1);
	void restart();
	void set_timer_out_func(std::function<void()> on_timer_out);
	void set_end_time(float new_end_frame);
private:
	float m_fEndTime;
	float m_fCurTime;
	bool m_bIsOneShoot;
	bool m_bIsShooted;
	std::function<void()> m_funcOnTimerOutFunc;
};