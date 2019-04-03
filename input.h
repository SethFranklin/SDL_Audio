
#pragma once

#include <cstdint>

namespace Input
{

	bool IsKeyDown(unsigned int k);
	bool IsKeyPressed(unsigned int k);
	bool IsKeyReleased(unsigned int k);

	void PushBackInputs();
	void SetState(unsigned int k, bool b);

}
