#pragma once

namespace ue4::game_framework {
	class a_game_state_base;
}

namespace ue4::engine {
	class u_level;
	class u_game_instance;

	class u_world {
	public:
		char pad_0001[0x30]; // 0x00(0x30)
		ue4::engine::u_level* persistent_level; // 0x30(0x08)
		char pad_0002[0xE8]; // 0x38(0xE8)
		ue4::game_framework::a_game_state_base* game_state; // 0x120(0x08)
		char pad_0003[0x10]; // 0x128(0x10)
		ue4::containers::t_array<ue4::engine::u_level*> levels; // 0x138(0x10)
		char pad_0004[0x38]; // 0x148(0x38)
		ue4::engine::u_game_instance* owning_game_instance; // 0x180(0x08)
	};

	inline u_world* world;
}