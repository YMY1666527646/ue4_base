#include <includes.h>

ue4::math::vector ue4::game_framework::a_actor::get_location() {
	struct {
		ue4::math::vector return_value;
	} params{};

	ue4::sdk::process_event(this, ue4::sdk::get_actor_location, &params);

	return params.return_value;
}

ue4::math::rotator ue4::game_framework::a_actor::get_rotation() {
	struct {
		ue4::math::rotator return_value;
	} params{};

	const auto flags = ue4::sdk::get_actor_rotation->flags;
	ue4::sdk::get_actor_rotation->flags |= 0x00000400;

	ue4::sdk::process_event(this, ue4::sdk::get_actor_rotation, &params);
	ue4::sdk::get_actor_rotation->flags = flags;

	return params.return_value;
}

void ue4::game_framework::a_actor::get_bounds(const bool only_colliding_components, ue4::math::vector* origin, ue4::math::vector* extent) {
	struct {
		bool only_colliding_components;
		ue4::math::vector origin;
		ue4::math::vector extent;
	} params{};

	params.only_colliding_components = only_colliding_components;

	ue4::sdk::process_event(this, ue4::sdk::get_actor_bounds, &params);

	if (origin != nullptr)
		*origin = params.origin;

	if (extent != nullptr)
		*extent = params.extent;
}

float ue4::game_framework::a_actor::get_distance_to(ue4::game_framework::a_actor* actor) {
	struct {
		ue4::game_framework::a_actor* actor;
		float return_value;
	} params{};

	params.actor = actor;

	ue4::sdk::process_event(this, ue4::sdk::get_distance_to, &params);

	return params.return_value;
}