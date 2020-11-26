#pragma once
#include "matrix2d.h"
#include <vector>
#include <opencv2/opencv.hpp>

namespace my
{
	class image
	{
	private:
		
		int rows_, columns_, channels_;
		std::vector<matrix2d> mats_;
		
	public:

		explicit image(const std::vector<matrix2d>& mats);

		explicit image(const cv::Mat& mat);

		explicit image(const std::string& img_src);

		void show(const std::string& win_name);

		matrix2d get_channel(int channel_index);

		void set_channel(int channel_index, const matrix2d& mat);


		int get_rows() const;

		int get_columns() const;

		int get_channels_count() const;

		image(const image& other);

		image(image&& other) noexcept;

		image& operator=(const image& other);

		image& operator=(image&& other) noexcept;
	};
}

