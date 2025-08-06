#pragma once
#include <vector>

class Kernel
{
private:
	std::size_t _height;
	std::vector<std::vector<double>> _data;
	double _sum;
public:
	Kernel(std::size_t size = 1)
		:_height(size * 2 + 1)
		,_sum(0)
		,_data(std::vector<std::vector<double>>(_height, std::vector<double>(_height, 0)))
	{
		int num = 1;
		int ring = 0;
		int maxRing = (_height - 1) / 2;
		/*_data.resize(_height);
		for(std::size_t i = 0; i < _height; ++i)
		{
				_data[i].resize(_height);
		}*/

		while (ring <= maxRing) {
			// Fill top row
			for (int i = ring; i < _height - ring; ++i) {
				_data[ring][i] = num;
				_sum += num;
			}
			//num += 2;

			// Fill right column
			for (int i = ring + 1; i < _height - ring; ++i) {
				_data[i][_height - ring - 1] = num;
				_sum += num;
			}
			//num += 2;

			// Fill bottom row
			for (int i = _height - ring - 2; i >= ring; --i) {
				_data[_height - ring - 1][i] = num;
				_sum += num;
			}
			//num += 2;

			// Fill left column
			for (int i = _height - ring - 2; i > ring; --i) {
				_data[i][ring] = num;
				_sum += num;
			}
			num += 2;

			++ring;
		}

		for (std::size_t i = 0; i < _height; i++) {
			for (std::size_t j = 0; j < _height; j++) {
				std::cout << _data[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << _sum << std::endl;
	}

	/*Kernel()
		:_height(7)
		,_sum(7)
	{
			_data = {
				{0,    0,    0,      0,      0,      0,      0},
				{0,    2025, 6120,   8145,   6120,   2025,   0},
				{0,    6120, 18496,  24616,  18496,  6120,   0},
				{0,    8145, 24616,  32761,  24616,  8145,   0},
				{0,    6120, 18496,  24616,  18496,  6120,   0},
				{0,    2025, 6120,   8145,   6120,   2025,   0},
				{0,    0,    0,      0,      0,      0,      0 }, };

			for(auto x : _data)
			{
				for (auto y : x)
				{
					_sum += y;
				}
			}
	}*/

	/*Kernel(std::size_t size)
		:_height(5)
		, _sum(0)
	{
		_data = { {1,  4 , 6,  4,  1 },{4, 16, 24, 16,  4,},{6, 24, 36, 24,  6,},{4, 16, 24, 16,  4}, {1,  4,  6,  4,  1} };
	}*/

	int get_data(int x, int y) const
	{
		return _data[y][x];
	}

	std::size_t get_sum() const
	{
		return _sum;
	}

	std::size_t get_height() const
	{
		return _height;
	}

};