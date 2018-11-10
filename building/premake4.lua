solution "Tetris"
	configurations {"release-dynamic", "release-static", "debug-dynamic", "debug-static"}

	project "Tetris"
		language "C"
		flags {"ExtraWarnings"}
		files {"../sources/**.c"}
		includedirs {"../API"}
		defines {"TETRIS_USE_C_STANDARD_LIBRARY"}
		--buildoptions {"-std=c89 -pedantic -Wall -Weverything"}

		configuration "release*"
			targetdir "lib/release"

		configuration "debug*"
			flags {"Symbols"}
			targetdir "lib/debug"

		configuration "*dynamic"
			kind "SharedLib"

		configuration "*static"
			kind "StaticLib"
			defines {"TETRIS_STATIC"}
