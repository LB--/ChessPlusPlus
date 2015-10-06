# ChessPlusPlus-server
add_executable(ChessPlusPlus-server
	"Main.cpp"
)
set_property(TARGET ChessPlusPlus-server PROPERTY CXX_STANDARD 14)
target_include_directories(ChessPlusPlus-server PUBLIC
	"../"
	${Boost_INCLUDE_DIRS}
)
target_link_libraries(ChessPlusPlus-server
	ChessPlusPlus-common
	${Boost_LIBRARIES}
)
file(COPY data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/data/)

# Options
option(CHESSPP_SERVER_REDIRECT_OUTPUT "Redirects server output to files instead of stdout and stderr" OFF)
if(CHESSPP_SERVER_REDIRECT_OUTPUT)
	target_compile_definitions(ChessPlusPlus-server
		PRIVATE CHESSPP_REDIRECT_OUTPUT
	)
endif()

# Divvy out work to subdirectories
add_subdirectory("board/")
add_subdirectory("config/")
add_subdirectory("net/")
add_subdirectory("piece/")
