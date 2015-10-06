# Common lib
add_library(ChessPlusPlus-common
	"Debug.cpp"
)
set_property(TARGET ChessPlusPlus-common PROPERTY CXX_STANDARD 14)
target_include_directories(ChessPlusPlus-common PUBLIC
	"../"
	${Boost_INCLUDE_DIRS}
)
target_link_libraries(ChessPlusPlus-common
	PUBLIC
		json-parser
		${Boost_LIBRARIES}
)

# Options
option(CHESSPP_COMMON_TRUNC_LOGS "Truncate the log files at the start of the program" ON)
if(CHESSPP_COMMON_TRUNC_LOGS)
	target_compile_definitions(ChessPlusPlus-common
		PUBLIC CHESSPP_TRUNC_LOGS
	)
endif()

# Divvy out work to subdirectories
add_subdirectory("config/")
add_subdirectory("net/")
add_subdirectory("util/")
