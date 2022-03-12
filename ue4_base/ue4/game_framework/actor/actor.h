#pragma once

namespace ue4::core_object {
	class u_object;
}

namespace ue4::components {
	class u_scene_component;
}

namespace ue4::game_framework {
	class a_pawn;

	class a_actor : public ue4::core_object::u_object {
	public:
		char pad_0001[0xF0]; // 0x28(0xF0)
		ue4::game_framework::a_pawn* instigator; // 0x118(0x08)
		char pad_0002[0x10]; // 0x120(0x10)
		ue4::components::u_scene_component* root_component; // 0x130(0x08)

		ue4::math::vector get_location();
		ue4::math::rotator get_rotation();
		void get_bounds(bool only_colliding_components, ue4::math::vector* origin, ue4::math::vector* extent);
		float get_distance_to(ue4::game_framework::a_actor* actor);
	};
}