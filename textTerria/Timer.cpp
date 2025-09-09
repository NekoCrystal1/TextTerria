#include "Timer.h"

Timer::Timer(float end_frames, bool is_one_shoot, std::function<void()> on_time_out):end_frames(end_frames),cur_frame(0.0f), is_one_shoot(is_one_shoot), is_shooted(false), on_timer_out(on_timer_out)
{
}

Timer::~Timer()
{
}

void Timer::on_update(float delta)
{
	if (cur_frame < end_frames)
		cur_frame++;
	if (cur_frame >= end_frames && ((is_one_shoot && !is_shooted) || !is_one_shoot)) {
		cur_frame -= end_frames;
		if (on_timer_out)
			on_timer_out();
	}
}

void Timer::restart()
{
	is_shooted= false;
	cur_frame = 0;
}

void Timer::set_timer_out_func(std::function<void()> on_timer_out)
{
	this->on_timer_out = on_timer_out;
}

void Timer::set_end_time(float new_end_frame)
{
	this->end_frames = new_end_frame;
}
