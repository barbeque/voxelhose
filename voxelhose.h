#ifndef _voxelhose_h_
#define _voxelhose_h_

#include <cassert>

class vxVoxelBuffer {
public:
	vxVoxelBuffer(unsigned int width, unsigned int height, unsigned int depth) {
		assert(width > 0);
		assert(height > 0);
		assert(depth > 0);

		this->width = width;
		this->height = height;
		this->depth = depth;
		this->voxels = new unsigned char[depth * height * width];
	}
	~vxVoxelBuffer() {
		delete[] this->voxels;
		this->voxels = NULL;
	}
public:
	void set(unsigned char colour, unsigned int x, unsigned int y, unsigned int z) {
		assert(x < width);
		assert(y < height);
		assert(z < depth);

		this->voxels[z][y][x] = colour;
	}
	unsigned char get(unsigned int x, unsigned int y, unsigned int z) {
		assert(x < width);
		assert(y < height);
		assert(z < depth);

		return this->voxels[z][y][x];
	}
public:
	/// blit this voxel buffer into another one at the given offset
	void blit(vxVoxelBuffer& destination, int destinationOffsetX, int destinationOffsetY, int destinationOffsetY) const {
		for(unsigned int x = 0; x < width; x++) {
			int destinationX = x + destinationOffsetX;
			if(destinationX < 0 || destinationX >= destination.width) {
				continue;
			}

			for(unsigned int y = 0; y < height; y++) {
				int destinationY = y + destinationOffsetY;
				if(destinationY < 0 || destinationY >= destination.height) {
					continue;
				}

				for(unsigned int z = 0; z < depth; z++) {
					int destinationZ = z + destinationOffsetZ;
					if(destinationZ < 0 || destinationZ >= destination.depth) {
						continue;
					}

					destination.set(this->get(x, y, z), (unsigned int)destinationX, (unsigned int)destinationY, (unsigned int)destinationZ);
				}
			}
		}
	}
private:
	unsigned int width;
	unsigned int height;
	unsigned int depth;
	unsigned char* voxels;
};

// TODO subset (so we can cull out the visible portion)
// TODO rasterizer

#endif

