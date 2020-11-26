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

		/**
		 * \brief Construct from 2d uchar array
		 * \param mat 2d uchar array
		 * \param rows row count
		 * \param columns column count
		 */
		matrix2d(uchar** mat, const int rows, const int columns);

		/**
		 * \brief Construct from given size
		 * \param rows row count
		 * \param columns column count
		 */
		matrix2d(const int rows, const int columns);

		/**
		 * \brief Construct from OpenCV Mat
		 * \param mat OpenCV Mat
		 */
		explicit matrix2d(const cv::Mat& mat);

		// ~matrix2d();

		/**
		 * \brief Set matrix data
		 * \param mat 2d uchar array
		 * \param rows row count
		 * \param columns column count
		 */
		void set_matrix(uchar** mat, const int rows, const int columns);

		/**
		 * \brief Get pixel value by coordinate
		 * \param row_index row index
		 * \param column_index column index
		 * \return pixel value
		 */
		int at(const int row_index, const int column_index) const;

		/**
		 * \brief Set pixel value by coordinate
		 * \param row_index row index
		 * \param column_index column index
		 * \param value pixel value
		 */
		void set(const int row_index, const int column_index, const uchar value) const;

		/**
		 * \brief Display image
		 * \param win_name window name
		 */
		void show(const std::string& win_name) const;

		/**
		 * \brief Print data for debugging
		 */
		void print() const;

		/**
		 * \brief Convert OpenCV Mat to matrix2d vector
		 * \param mat OpenCV Mat
		 * \return A vector of each channels' matrix
		 */
		static std::vector<matrix2d>* convert_from_cv_mat(const cv::Mat& mat);
		
		/**
		 * \brief Convert matrix2d to OpenCV Mat
		 * \return OpenCV Mat
		 */
		cv::Mat convert_to_cv_mat() const;

		matrix2d(const matrix2d& other) = default;

		matrix2d(matrix2d&& other) noexcept;

		matrix2d& operator=(const matrix2d& other);

		matrix2d& operator=(matrix2d&& other) noexcept;

		/**
		 * \brief Add self and other matrix2d
		 * \param other Another matrix2d
		 * \return A vector composed by self and other
		 */
		std::vector<matrix2d> operator+(matrix2d& other) const;

		/**
		 * \brief Add between self and vector of matrix2d
		 * \param other Another vector of matrix2d
		 * \return Vector composed by all matrix2d
		 */
		std::vector<matrix2d> operator+(std::vector<matrix2d>& other) const;

		/**
		 * \brief Get row count
		 * \return row count
		 */
		int rows() const;

		/**
		 * \brief Get column count
		 * \return column count
		 */
		int columns() const;
	};
}