#include <includes.h>

bool ue4::sdk::initialize() {
	const auto main = reinterpret_cast<std::uintptr_t>(LI_FN(GetModuleHandleA)(nullptr));
	if (!main) return false;

	ue4::core_object::names = reinterpret_cast<decltype(ue4::core_object::names)>(utils::pattern_scan(main, _("48 8D 05 ? ? ? ? EB 13 48 8D 0D ? ? ? ? E8 ? ? ? ? C6 05 ? ? ? ? ? 0F 10"), true));
	if (!ue4::core_object::names) throw std::runtime_error(_("failed to get ue4::core_object::names"));

	ue4::core_object::objects = reinterpret_cast<decltype(ue4::core_object::objects)>(utils::pattern_scan(main, _("48 8B 05 ? ? ? ? 48 8B 0C C8 4C 8D 04 D1 EB 03"), true));
	if (!ue4::core_object::objects) throw std::runtime_error(_("failed to get ue4::core_object::objects"));

	ue4::engine::world = reinterpret_cast<decltype(ue4::engine::world)>(utils::pattern_scan(main, _("48 8B 1D ? ? ? ? 48 85 DB 74 3B 41 B0 01 33 D2 48 8B CB E8"), true));
	if (!ue4::engine::world) throw std::runtime_error(_("failed to get ue4::engine::world"));

	ue4::sdk::bone_matrix = utils::pattern_scan(main, _("48 8B C4 48 89 58 08 48 89 70 10 57 48 81 EC ? ? ? ? F6"));
	if (!sdk::bone_matrix) throw std::runtime_error(_("failed to get ue4::sdk::bone_matrix"));

	// u_canvas
	ue4::sdk::font = ue4::core_object::objects->find("Font Roboto.Roboto");
	ue4::sdk::draw_box = ue4::core_object::objects->find("Function Engine.Canvas.K2_DrawBox");
	ue4::sdk::draw_line = ue4::core_object::objects->find("Function Engine.Canvas.K2_DrawLine");
	ue4::sdk::draw_text = ue4::core_object::objects->find("Function Engine.Canvas.K2_DrawText");
	ue4::sdk::draw_polygon = ue4::core_object::objects->find("Function Engine.Canvas.K2_DrawPolygon");
	ue4::sdk::text_size = ue4::core_object::objects->find("Function Engine.Canvas.K2_TextSize");

	// a_player_controller
	ue4::sdk::world_to_screen = ue4::core_object::objects->find("Function Engine.PlayerController.ProjectWorldLocationToScreen");

	// a_actor
	ue4::sdk::get_actor_location = ue4::core_object::objects->find("Function Engine.Actor.K2_GetActorLocation");
	ue4::sdk::get_actor_rotation = ue4::core_object::objects->find("Function Engine.Actor.K2_GetActorRotation");
	ue4::sdk::get_actor_bounds = ue4::core_object::objects->find("Function Engine.Actor.GetActorBounds");
	ue4::sdk::get_distance_to = ue4::core_object::objects->find("Function Engine.Actor.GetDistanceTo");

	// u_skeletal_mesh_component
	ue4::sdk::get_bone_name = ue4::core_object::objects->find("Function Engine.SkinnedMeshComponent.GetBoneName");

	return true;
}
