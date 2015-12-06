# ChessPlusPlus-client
if(APPLE) # Application bundle if on an apple machine
	# Optionally build application bundle
	set(BUILD_APPBUNDLE FALSE CACHE BOOL "Build into OS x Application Bundle.")
	if(BUILD_APPBUNDLE)
		# Set bundle properties
		set(MACOSX_BUNDLE_BUNDLE_NAME ChessPlusPlus)
		set(MACOSX_BUNDLE_INFO_STRING ChessPlusPlus)
		set(MACOSX_BUNDLE_SHORT_VERSION_STRING 0.0.1)
		set(MACOSX_BUNDLE_BUNDLE_VERSION 0.0.1)
		set(MACOSX_BUNDLE_GUI_IDENTIFIER com.cplusplus.chesspp)

		# Throw all the resource paths into a variable
		file(GLOB_RECURSE CHESSPP_RESOURCES
			${PROJECT_SOURCE_DIR}/client/data/*
		)

		# Make sure each resource file gets put in the right directory
		# in the application bundle
		FOREACH(file ${CHESSPP_RESOURCES})
			file(RELATIVE_PATH relPath ${PROJECT_SOURCE_DIR} ${file})
			string(FIND ${relPath} "/" inSubDirectory REVERSE)
			if(${inSubDirectory} GREATER 0)
				string(SUBSTRING ${relPath} 0 ${inSubDirectory} relDir)
				set(PACKAGE_LOCATION Resources/${relDir})
			else()
				set(PACKAGE_LOCATION Resources)
			endif()
			set_source_files_properties(${file}
				PROPERTIES
					MACOSX_PACKAGE_LOCATION ${PACKAGE_LOCATION}
			)
		ENDFOREACH()
		add_executable(ChessPlusPlus-client MACOSX_BUNDLE
			"Main.cpp"
		)
	endif()
endif()
if(NOT APPLE OR NOT BUILD_APPBUNDLE)
	# Copy resources to build directory if build directory is different from source directory.
	if(NOT ${CMAKE_CURRENT_BINARY_DIR} STREQUAL ${PROJECT_SOURCE_DIR})
		file(COPY data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/data/)
	endif()
	if(WIN32)
		add_executable(ChessPlusPlus-client WIN32
			"Main.cpp"
		)
	else()
		add_executable(ChessPlusPlus-client
			"Main.cpp"
		)
	endif()
endif()
set_property(TARGET ChessPlusPlus-client PROPERTY CXX_STANDARD 14)
target_include_directories(ChessPlusPlus-client PUBLIC
	"../"
	${SFML_INCLUDE_DIR}
	${Boost_INCLUDE_DIRS}
)
target_link_libraries(ChessPlusPlus-client
	ChessPlusPlus-common
	${SFML_LIBRARIES}
	${SFML_DEPENDENCIES}
	${Boost_LIBRARIES}
)

# Options
if(WIN32)
	set(CHESSPP_CLIENT_REDIRECT_OUTPUT_DEFAULT ON)
else()
	set(CHESSPP_CLIENT_REDIRECT_OUTPUT_DEFAULT OFF)
endif()
option(CHESSPP_CLIENT_REDIRECT_OUTPUT "Redirects client output to files instead of stdout and stderr" ${CHESSPP_CLIENT_REDIRECT_OUTPUT_DEFAULT})
if(CHESSPP_CLIENT_REDIRECT_OUTPUT)
	target_compile_definitions(ChessPlusPlus-client
		PRIVATE CHESSPP_REDIRECT_OUTPUT
	)
endif()

# Add sources
target_sources(ChessPlusPlus-client PRIVATE
	"${CMAKE_CURRENT_LIST_DIR}/Board.cpp"
)

# Divvy out work to subdirectories
add_subdirectory("app/")
add_subdirectory("config/")
add_subdirectory("net/")
add_subdirectory("res/")
