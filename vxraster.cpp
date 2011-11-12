#include "vxraster.h"

vxRasterizer::vxRasterizer(SDL_Surface* surface) {
	palette = buildPalette();

	this->surface = surface;
}

void vxRasterizer::renderToScreen() {
	// TODO generate all the rays
	// TODO store all the rays in a list
	// TODO step through the cube surface one at a time, firing all the remaining rays
	// TODO if a ray hits, delete it from the list and write a pixel to the screen. repeat with next z-layer
	// TODO if you run out of z-layers abort all remaining rays to bgcolor
}

// build a sane 8-bit palette
vxRGB* buildPalette() {
	// 3 bits R
	// 3 bits G
	// 2 bits B

	vxRGB* palette = new vxRGB[256];

	for(unsigned char i = 0; i <= 255; i++) {
		unsigned char b = i & 0x3;
		unsigned char g = (i & 0x1c) << 2;
		unsigned char r = (i & 0xe0) << 5;

		vxRGB colour;
		colour.r = (r / 7.0) * 255;
		colour.g = (g / 7.0) * 255;
		colour.b = (b / 3.0) * 255;

		palette[i] = colour;
	}

	return palette;
}
