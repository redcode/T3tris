solution "Tetris"
	configurations {"Release-Dynamic", "Release-Static", "Debug-Dynamic", "Debug-Static"}

	project "Tetris"
		language "C"
		flags {"ExtraWarnings"}
		files {"../sources/**.c"}
		includedirs {"../API/C"}
		defines {"TETRIS_USE_C_STANDARD_LIBRARY"}
		--buildoptions {"-std=c89 -pedantic -Wall"}

		configuration "Release*"
			targetdir "lib/release"

		configuration "Debug*"
			flags {"Symbols"}
			targetdir "lib/debug"

		configuration "*Dynamic"
			kind "SharedLib"

		configuration "*Static"
			kind "StaticLib"
			defines {"TETRIS_STATIC"}
