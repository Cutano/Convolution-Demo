#include "utility.h"

using namespace my;

image utility::blur(const image src, int kernel_size)
{
	if (kernel_size <= 0 || kernel_size % 2 == 0)
	{
		throw std::domain_error("Kernel size must be positive and odd");
	}

	const int border_width = kernel_size / 2;

	if (border_width * 2 + kernel_size > std::min(src.get_rows(), src.get_columns()))
	{
		throw std::out_of_range("Kernel_size too large");
	}
	
	image result(src);

	const int channels = result.get_channels_count();

	for (int c = 0; c < channels; ++c)
	{
		const matrix2d src_layer = result.get_channel(c);
		matrix2d result_layer(src_layer);

		for (int i = border_width; i < src.get_rows() - border_width; ++i)
		{
			for (int j = border_width; j < src.get_columns() - border_width; ++j)
			{
				// For each pixel of kernel center

				int avg = 0;

				for (int x = i - border_width; x <= i + border_width; ++x)
				{
					for (int y = j - border_width; y <= j + border_width; ++y)
					{
						avg += src_layer.at(x, y);
					}
				}

				avg /= kernel_size * kernel_size;

				result_layer.set(i, j, avg);
				result.set_channel(c, result_layer);
			}
		}
	}

	return result;
}
