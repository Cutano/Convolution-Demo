#pragma once

#include "image.h"
#include "matrix2d.h"
#include <algorithm>

namespace my
{
	static class utility
	{
	public:
		static image blur(my::image src, int kernel_size);
	};
}

