#pragma once
#include "matrix2d.h"

namespace my
{
	class kernel: public matrix2d
	{
	private:
		int size_, border_width_;
	};
}