#pragma once

namespace ue4::game_framework {
	class a_player_state : public ue4::game_framework::a_actor {
	public:
		char pad_0001[0x148]; // 0x138(0x148)
		ue4::game_framework::a_pawn* pawn_private; // 0x280(0x08)
		char pad_0002[0x78]; // 0x288(0x78)
		ue4::containers::f_string player_name_private; // 0x300(0x10)
	};
}