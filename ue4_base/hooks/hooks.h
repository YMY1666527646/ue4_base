#pragma once

namespace hooks {
	bool initialize();
	bool release();
}

namespace hooks::post_render {
	static constexpr auto index = 0x62;
	using fn = void(__thiscall*)(ue4::core_object::u_object*, ue4::engine::u_canvas*);
	inline fn original;
	void __stdcall hook(ue4::core_object::u_object* viewport_client, ue4::engine::u_canvas* canvas);
}