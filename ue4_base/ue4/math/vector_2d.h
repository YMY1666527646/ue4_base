#pragma once

namespace ue4::math {
	class vector_2d {
	public:
		float x, y;

		bool is_zero() const {
			if (x == 0.f && y == 0.f) return true;

			return false;
		}
	};
}