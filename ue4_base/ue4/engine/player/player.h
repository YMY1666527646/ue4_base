#pragma once

namespace ue4::game_framework {
	class a_player_controller;
}

namespace ue4::engine {
	class u_player {
	public:
		char pad_0001[0x30]; // 0x00(0x30)
		ue4::game_framework::a_player_controller* player_controller; // 0x30(0x08)
		char pad_0002[0x38]; // 0x38(0x38)
		ue4::core_object::u_object* viewport_client; // 0x70(0x08)
	};
}