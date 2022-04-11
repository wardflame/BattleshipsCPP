#pragma once

// Difficulty levels for gameplay.
enum class Difficulty
{
	Cadet,
	Commodore,
	Admiral
};

// String version of difficulty level.
static const char* difficulty_str[] = { "Cadet", "Commodore", "Admiral" }