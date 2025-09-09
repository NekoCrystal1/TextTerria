#pragma once
#include <functional>

class Timer {
public:
	Timer(float end_frames = 1,bool is_one_shoot = true,std::function<void()> on_time_out = nullptr);
	~Timer();
	void on_update(float delta = 1);
	void restart();
	void set_timer_out_func(std::function<void()> on_timer_out);
	void set_end_time(float new_end_frame);
private:
	float end_frames;
	float cur_frame;
	bool is_one_shoot;
	bool is_shooted;
	std::function<void()> on_timer_out;
	
};