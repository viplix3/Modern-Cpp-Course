add_library(
	guessing-game
	header/guessing_game.hpp
	src/guessing_game.cpp
)

target_include_directories(guessing-game PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/header")