#include <includes.h>
#include "../hooks.h"

void __stdcall hooks::post_render::hook(ue4::core_object::u_object* viewport_client, ue4::engine::u_canvas* canvas) {
	render::canvas = canvas;

	render::text({ 50.f, 50.f }, L"ue4_base", { 1.f, 1.f, 1.f, 1.f });

	const auto world = *reinterpret_cast<decltype(ue4::engine::world)*>(ue4::engine::world);
	if (!world) return;

	const auto local_player = world->owning_game_instance->local_players[0];
	if (!local_player) return;

	const auto player_controller = local_player->player_controller;
	if (!player_controller) return;

	const auto my_player = player_controller->acknowledged_pawn;
	if (!my_player) return;

	auto actors = world->persistent_level->actors;
	for (auto i = 0; i < actors.size(); i++) {
		const auto actor = actors[i];
		if (!actor || !actor->root_component) continue;
		if (actor == my_player) continue;

		const auto get_name = actor->get_name();
		const auto name = std::wstring(get_name.begin(), get_name.end());

		const auto location = actor->get_location();

		ue4::math::vector_2d position{};
		if (player_controller->world_to_screen(location, position)) {
			render::text(position, name.c_str(), { 1.f, 1.f, 1.f, 1.f });
		}
	}

	hooks::post_render::original(viewport_client, canvas);
}