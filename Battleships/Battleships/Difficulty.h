#pragma once

// Difficulty levels for gameplay.
enum class Difficulty {
	Cadet,
	Commodore,
	Admiral
};

// String version of difficulty level.
static const char* difficulty_string[] = { "Cadet", "Commodore", "Admiral" };

// Roll threshold for guaranteed AI hit.
static const float difficulty_threshold[] = { 0.05f, 0.25f, 0.4f };