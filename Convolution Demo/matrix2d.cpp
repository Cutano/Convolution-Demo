#include "matrix2d.h"

using namespace my;

matrix2d::matrix2d(uchar** mat, const int rows, const int columns)
{
	if (rows > MAX_ROWS || columns > MAX_COLUMNS)
	{
		throw std::out_of_range("Size out of range");
	}

	mat_ = mat;
	rows_ = rows;
	columns_ = columns;
}

matrix2d::matrix2d(const int rows, const int columns) :rows_(rows), columns_(columns)
{
	if (rows > MAX_ROWS || columns > MAX_COLUMNS)
	{
		throw std::out_of_range("Size out of range");
	}

	mat_ = new uchar * [rows_];

	for (auto i = 0; i != rows_; ++i)
	{
		mat_[i] = new uchar[columns_];
	}
}

matrix2d::matrix2d(const cv::Mat& mat)
{
	columns_ = mat.cols;
	rows_ = mat.rows;

	if (rows_ > MAX_ROWS || columns_ > MAX_COLUMNS)
	{
		throw std::out_of_range("Size out of range");
	}

	mat_ = new uchar * [rows_];

	for (auto i = 0; i != rows_; ++i)
	{
		mat_[i] = new uchar[columns_];
	}

	for (auto i = 0; i < rows_; i++) {
		for (auto j = 0; j < columns_; j++) {
			set(i, j, mat.at<uchar>(i, j));
		}
	}
}

//my::matrix2d::~matrix2d()
//{
//	for (auto i = 0; i != rows_; ++i)
//	{
//		delete[] mat_[i];
//	}
//	delete[] mat_;
//}

void matrix2d::set_matrix(uchar** mat, const int rows, const int columns)
{
	if (rows > MAX_ROWS || columns > MAX_COLUMNS)
	{
		throw std::out_of_range("Size out of range");
	}

	for (auto i = 0; i != rows_; ++i)
	{
		delete[] mat_[i];
	}
	delete[] mat_;

	mat_ = mat;
	rows_ = rows;
	columns_ = columns;
}

int matrix2d::at(const int row_index, const int column_index) const
{
	return mat_[row_index][column_index];
}

void matrix2d::set(const int row_index, const int column_index, const uchar value) const
{
	mat_[row_index][column_index] = value;
}

void matrix2d::show(const std::string& win_name) const
{
	cv::imshow(win_name, convert_to_cv_mat());
	cv::waitKey(0);
}

void matrix2d::print() const
{
	for (auto i = 0; i < rows_; i++) {
		for (auto j = 0; j < columns_; j++) {
			std::cout << static_cast<int>(mat_[i][j]) << " ";
		}
		std::cout << std::endl;
	}
}

std::vector<matrix2d>* matrix2d::convert_from_cv_mat(const cv::Mat& mat)
{
	const auto channels = mat.channels();
	const auto columns = mat.cols;
	const auto rows = mat.rows;

	auto* result = new std::vector<matrix2d>();
	std::vector<cv::Mat> mats;

	cv::split(mat, mats);

	for (auto channel : mats)
	{
		matrix2d temp(rows, columns);
		for (auto i = 0; i < rows; i++) {
			for (auto j = 0; j < columns; j++) {
				temp.set(i, j, mat.at<uchar>(i, j));
			}
		}
		result->push_back(temp);
	}

	return result;
}

cv::Mat matrix2d::convert_to_cv_mat() const
{
	auto mat = cv::Mat(rows_, columns_, CV_8U);

	for (auto i = 0; i < rows_; i++)
	{
		auto* tmp = mat.ptr<uchar>(i);
		for (auto j = 0; j < columns_; j++)
		{
			tmp[j] = mat_[i][j];
		}
	}
	return mat;
}

matrix2d::matrix2d(matrix2d&& other) noexcept : mat_(other.mat_),
rows_(other.rows_),
columns_(other.columns_)
{
}

matrix2d& matrix2d::operator=(const matrix2d& other)
{
	if (this == &other)
		return *this;
	mat_ = other.mat_;
	rows_ = other.rows_;
	columns_ = other.columns_;
	return *this;
}

matrix2d& matrix2d::operator=(matrix2d&& other) noexcept
{
	if (this == &other)
		return *this;
	mat_ = other.mat_;
	rows_ = other.rows_;
	columns_ = other.columns_;
	return *this;
}

std::vector<matrix2d> matrix2d::operator+(matrix2d& other) const
{
	auto result = *new std::vector<matrix2d>();

	result.push_back(*this);
	result.push_back(other);

	return result;
}

std::vector<matrix2d> matrix2d::operator+(std::vector<matrix2d>& other) const
{
	other.insert(other.begin(), *this);
	return other;
}

int matrix2d::rows() const
{
	return rows_;
}

int matrix2d::columns() const
{
	return columns_;
}
