#include "utility.h"

using namespace my;

image utility::blur(const image src, int kernel_size)
{
	image result(src);

	const int channels = result.get_channels_count();

	for (int i = 0; i < channels; ++i)
	{
		matrix2d layer = result.get_channel(i);
	}
}
