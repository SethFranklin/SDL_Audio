
#include <cstdint>
#include <algorithm>

#include "input.h"

bool DownLast[128];
bool DownNow[128];

bool Input::IsKeyDown(unsigned int k)
{

	return DownNow[k];

}

bool Input::IsKeyPressed(unsigned int k)
{

	return (DownNow[k] && !DownLast[k]);

}

bool Input::IsKeyReleased(unsigned int k)
{

	return (!DownNow[k] && DownLast[k]);

}

void Input::PushBackInputs()
{

	std::copy(DownNow, DownNow + 128, DownLast);

}

void Input::SetState(unsigned int k, bool b)
{

	DownNow[k] = b;

}
