#pragma once

namespace ue4::game_framework {
	class a_player_controller : public ue4::game_framework::a_controller {
	public:
		char pad_0001[0x68]; // 0x230(0x68)
		ue4::engine::u_player* player; // 0x298(0x08)
		ue4::game_framework::a_pawn* acknowledged_pawn; // 0x2a0(0x08)

		bool world_to_screen(const ue4::math::vector& world, ue4::math::vector_2d& screen);
	};
}