#pragma once

namespace ue4::components {
	class u_scene_component{
	public:
		char pad_0001[0x11c]; // 0x00(0x11c)
		ue4::math::vector relative_location; // 0x11c(0x0c)
		ue4::math::rotator relative_rotation; // 0x128(0x0c)
	};
}