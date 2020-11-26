#pragma once

#include <opencv2/opencv.hpp>
#include <stdexcept>
#include <vector>

constexpr auto MAX_COLUMNS = 20000;
constexpr auto MAX_ROWS = 10000;

namespace my
{
	class matrix2d
	{
	private:

		uchar** mat_;
		int rows_, columns_;

	public:

		matrix2d(uchar** mat, const int rows, const int columns);

		matrix2d(const int rows, const int columns);

		explicit matrix2d(const cv::Mat& mat);

		// ~matrix2d();

		void set_matrix(uchar** mat, const int rows, const int columns);

		int at(const int row_index, const int column_index) const;

		void set(const int row_index, const int column_index, const uchar value) const;

		void show(const std::string& win_name) const;

		void print() const;

		static std::vector<matrix2d>* convert_from_cv_mat(const cv::Mat& mat);
		
		cv::Mat convert_to_cv_mat() const;

		matrix2d(const matrix2d& other) = default;

		matrix2d(matrix2d&& other) noexcept;

		matrix2d& operator=(const matrix2d& other);

		matrix2d& operator=(matrix2d&& other) noexcept;

		std::vector<matrix2d> operator+(matrix2d& other) const;

		std::vector<matrix2d> operator+(std::vector<matrix2d>& other) const;

		int rows() const;

		int columns() const;
	};
}