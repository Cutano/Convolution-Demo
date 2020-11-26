#include "image.h"

using namespace my;

my::image::image(const std::vector<matrix2d>& mats): rows_(mats.at(0).rows()),
                                                     columns_(mats.at(0).columns()),
                                                     channels_(mats.size()),
                                                     mats_(mats) { }

my::image::image(const cv::Mat& mat)
{
	mats_ = *matrix2d::convert_from_cv_mat(mat);
	rows_ = mat.rows;
	columns_ = mat.cols;
	channels_ = mat.channels();
}

image::image(const std::string& img_src)
{
	const auto mat = cv::imread(img_src);
	mats_ = *matrix2d::convert_from_cv_mat(mat);
	rows_ = mat.rows;
	columns_ = mat.cols;
	channels_ = mat.channels();
}

void image::show(const std::string& win_name)
{
	cv::Mat result;
	std::vector<cv::Mat> mats;
	for (auto mat : mats_)
	{
		mats.push_back(mat.convert_to_cv_mat());
	}
	cv::merge(mats, result);
	cv::imshow(win_name, result);
	cv::waitKey(0);
}

my::matrix2d my::image::get_channel(const int channel_index)
{
	return mats_.at(channel_index);
}

void my::image::set_channel(const int channel_index, const matrix2d& mat)
{
	mats_[channel_index] = mat;
}
