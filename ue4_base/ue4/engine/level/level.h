#pragma once

namespace ue4::game_framework {
	class a_actor;
}

namespace ue4::engine {
	class u_level {
	public:
		char pad_0001[0x98]; // 0x00(0x98)
		ue4::containers::t_array<ue4::game_framework::a_actor*> actors; // 0x98(0x10)
	};
}