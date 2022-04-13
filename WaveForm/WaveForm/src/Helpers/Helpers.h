#pragma once
#include <iostream>
#include<thread>




class TimeBase 
{

public:

	TimeBase():time(0.0){Timer();}


	inline const float GetTime() noexcept
	{
		return time;
	}

	



private:

	float time;


	void Timer()
	{
		//threaded timer
		std::thread([&]
		{
			while (true)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
				SetTime(time + 0.1);
			}

		}).detach();

	}



	 const void SetTime(float a) noexcept
	{
		time = a;
	}
};