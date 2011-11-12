#ifndef _voxelhose_h_
#define _voxelhose_h_

class vxVoxelBuffer {
public:
	vxVoxelBuffer(unsigned int width, unsigned int height, unsigned int depth);
	~vxVoxelBuffer();
public:
	void set(unsigned char colour, unsigned int x, unsigned int y, unsigned int z);
	unsigned char get(unsigned int x, unsigned int y, unsigned int z);
public:
	/// blit this voxel buffer into another one at the given offset
	void blit(vxVoxelBuffer& destination, unsigned int destinationOffsetX, unsigned int destinationOffsetY, unsigned int destinationOffsetY) const;
private:
	unsigned int width;
	unsigned int height;
	unsigned int depth;
	unsigned char* voxels;
};

// TODO subset (so we can cull out the visible portion)
// TODO rasterizer

#endif

