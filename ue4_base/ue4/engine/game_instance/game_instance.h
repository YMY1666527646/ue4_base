#pragma once

namespace ue4::engine {
	class u_game_instance {
	public:
		char pad_0001[0x38]; // 0x00(0x38)
		ue4::containers::t_array<class u_player*> local_players; // 0x38(0x10)
	};
}