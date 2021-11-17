#pragma once
#include <SDL.h>

class Time
{
public:
	static Uint32 Now;
	static Uint32 Last;
	static float DeltaTime;
};
