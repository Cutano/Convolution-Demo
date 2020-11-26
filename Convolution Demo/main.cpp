#include "matrix2d.h"
#include "image.h"
#include "utility.h"

int main()
{
	my::image img("D:/OneDrive - Rinne's Space/Pictures/wallhaven-512644.png");
	my::image dst = my::utility::blur(img, 21);
	dst.show("window");
}