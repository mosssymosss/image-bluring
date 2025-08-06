#include <iostream>
#include <string>

#include "bmp.hpp" // https://github.com/baderouaich/BitmapPlusPlus
#include "kernel.hpp"
#include "Rectangle.h"

void blur(std::string str, std::size_t lvl, const Rectangle& rec)
{
	bmp::Bitmap img{ str };
	Kernel kernel(lvl);
	std::cout << kernel.get_sum() << std::endl;;
	std::size_t offset = kernel.get_height() / 2;
	std::size_t new_heigth = img.height() + 2 * offset;
	std::size_t new_width = img.width() + 2 * offset;
	std::vector<std::vector<bmp::Pixel>> larger_matrix(new_heigth, std::vector<bmp::Pixel>(new_width, bmp::Black));


	//copying all colors from image to a larger matrix with a black border
	std::cout << larger_matrix.size() << " " << larger_matrix[0].size() << std::endl;
	for (std::size_t y = 0; y < img.height(); ++y)
	{
		for (std::size_t x = 0; x < img.width(); ++x)
		{
			larger_matrix[y + offset][x + offset] = img.get(x, y);
		}
	}

	bmp::Bitmap image(new_heigth, new_width);
	for (int y = 0; y < new_heigth; ++y)
	{
		for (int x = 0; x < new_width; ++x)
		{
			image.set(x, y, larger_matrix[y][x]);
		}
	}
	image.save("g.bmp");
	for (int y = rec.left_y; y < rec.right_y; ++y)
	{
		for (int x = rec.left_x; x < rec.right_x; ++x)
		{
			double red = 0, green = 0, blue = 0;
			for (int dx = 0; dx < kernel.get_height(); ++dx)
			{
				for (int dy = 0; dy < kernel.get_height(); ++dy)
				{
					red += kernel.get_data(dx, dy) * image.get(x + dx, y + dy).r;
					green += kernel.get_data(dx, dy) * image.get(x + dx, y + dy).g;
					blue += kernel.get_data(dx, dy) * image.get(x + dx, y + dy).b;
				}
			}
			bmp::Pixel color(red / kernel.get_sum(), green / kernel.get_sum(), blue / kernel.get_sum());
			img.set(x, y, color);
		}
	}

	img.save("output.bmp");
	
	std::cout << "A" << std::endl;
}



int main()
{
	std::string input = "input.bmp";

	blur(input, 10, Rectangle(308, 492, 365, 524));

}