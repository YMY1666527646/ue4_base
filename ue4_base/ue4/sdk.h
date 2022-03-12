#pragma once

namespace ue4::core_object {
	class u_object;
}

namespace ue4::sdk {
	// u_canvas
	inline ue4::core_object::u_object* font;
	inline ue4::core_object::u_object* draw_box;
	inline ue4::core_object::u_object* draw_line;
	inline ue4::core_object::u_object* draw_text;
	inline ue4::core_object::u_object* draw_polygon;
	inline ue4::core_object::u_object* text_size;

	// a_player_controller
	inline ue4::core_object::u_object* world_to_screen;

	// a_actor
	inline ue4::core_object::u_object* get_actor_location;
	inline ue4::core_object::u_object* get_actor_rotation;
	inline ue4::core_object::u_object* get_actor_bounds;
	inline ue4::core_object::u_object* get_distance_to;

	// u_skeletal_mesh_component
	inline std::uintptr_t bone_matrix;
	inline ue4::core_object::u_object* get_bone_name;

	bool initialize();

	void process_event(void* object, void* u_function, void* params);
}
