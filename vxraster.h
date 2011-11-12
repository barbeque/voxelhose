#ifndef _vxraster_h_
#define _vxraster_h_

// responsible for raytracing a voxel buffer to screen centered in the viewing volume
class vxRasterizer {
public:
	void renderToScreen(const vxVoxelBuffer& buffer) const;
};

#endif

