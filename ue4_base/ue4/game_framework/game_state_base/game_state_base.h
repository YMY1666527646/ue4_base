#pragma once

namespace ue4::game_framework {
	class a_game_state_base {
	public:
		char pad_0001[0x238]; // 0x00(0x238)
		ue4::containers::t_array <ue4::game_framework::a_player_state*> player_array; // 0x238(0x10)
	};
}