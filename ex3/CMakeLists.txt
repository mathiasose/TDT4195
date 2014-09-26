cmake_minimum_required(VERSION 2.8)


PROJECT(Opengl) # #his is the name of your project
SET( Executable_file       Hello_world_GL     ) # This is how you .exe will be named



#########################################################
# Include Files , you can add source .cpp and .h to the program
#########################################################
add_executable(${Executable_file} main.cpp visuals.cpp visuals.h shader.hpp shader.cpp)


# Here only main.cpp was added, but more files
#could be added, for instance:
# add_executable(${Executable_file} main.cpp header.h function.cpp function.h ) 


# Do not change settings below this area, unless you know what you are doing

#########################################################
# Setting up OUTPUT FOLDER as /bin
#########################################################
set(dir ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(LIBRARY_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
	message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)
#########################################################
# Find FreeGLUT
#########################################################

IF(${WIN32})
	IF(${MINGW})
		FIND_PATH(GLUT_INCLUDE_DIR NAMES GL/freeglut.h
		 HINTS ${CMAKE_CURRENT_SOURCE_DIR}/freeglut-mingw/include/)
		# Look for the library.
		FIND_LIBRARY(GLUT_LIBRARY NAMES freeglut
		 HINTS ${CMAKE_CURRENT_SOURCE_DIR}/freeglut-mingw/lib/ )  
	ELSEIF(${MSVC})
		FIND_PATH(GLUT_INCLUDE_DIR NAMES GL/freeglut.h
		 HINTS ${CMAKE_CURRENT_SOURCE_DIR}/freeglut-msvc/include/)
		# Look for the library.
		FIND_LIBRARY(GLUT_LIBRARY NAMES freeglut
		 HINTS ${CMAKE_CURRENT_SOURCE_DIR}/freeglut-msvc/lib/ )  
	ENDIF(${MINGW})

	# Handle the QUIETLY and REQUIRED arguments and set FREEGLUT_FOUND to TRUE if all listed variables are TRUE.
	INCLUDE(FindPackageHandleStandardArgs)
	FIND_PACKAGE_HANDLE_STANDARD_ARGS(GLUT DEFAULT_MSG GLUT_LIBRARY GLUT_INCLUDE_DIR)
	# Copy the results to the output variables.
	IF(GLUT_FOUND)
		SET(GLUT_LIBRARIES ${GLUT_LIBRARY})
		SET(GLUT_INCLUDE_DIRS ${GLUT_INCLUDE_DIR})
		IF(${MINGW})
			add_custom_command(TARGET ${Executable_file} PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/freeglut-mingw/bin/freeglut.dll"  "${CMAKE_CURRENT_SOURCE_DIR}/bin/" )
		ELSEIF(${MSVC})
			add_custom_command(TARGET ${Executable_file} PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/freeglut-msvc/bin/freeglut.dll"  "${CMAKE_CURRENT_SOURCE_DIR}/bin/" )
		ENDIF(${MINGW})
	ELSE(GLUT_FOUND)
		SET(GLUT_LIBRARIES)
		SET(GLUT_INCLUDE_DIRS)
	ENDIF(GLUT_FOUND)
	
	MARK_AS_ADVANCED(GLUT_INCLUDE_DIRS GLUT_LIBRARIES)
	include_directories(${GLUT_INCLUDE_DIRS})
	link_directories(${GLUT_LIBRARY_DIRS})
	add_definitions(${GLUT_DEFINITIONS})
ENDIF(${WIN32})

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
# In linux Freeglut is found as glut ;)
	find_package(GLUT REQUIRED)
	include_directories(${GLUT_INCLUDE_DIRS})
	link_directories(${GLUT_LIBRARY_DIRS})
	add_definitions(${GLUT_DEFINITIONS})
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)

#########################################################
# Find GLEW
#########################################################

IF(${WIN32})
	IF(${MINGW})
		FIND_PATH(GLEW_INCLUDE_DIR NAMES GL/glew.h
		 HINTS ${CMAKE_CURRENT_SOURCE_DIR}/glew-mingw/include/)
		# Look for the library.
		FIND_LIBRARY(GLEW_LIBRARY
		 NAMES glew GLEW glew32 glew32s 
		 HINTS ${CMAKE_CURRENT_SOURCE_DIR}/glew-mingw/lib/)  
	ELSEIF(${MSVC})
		FIND_PATH(GLEW_INCLUDE_DIR NAMES GL/glew.h
		 HINTS ${CMAKE_CURRENT_SOURCE_DIR}/glew-msvc/include/)
		# Look for the library.
		FIND_LIBRARY(GLEW_LIBRARY
		 NAMES glew GLEW glew32 glew32s 
		 HINTS ${CMAKE_CURRENT_SOURCE_DIR}/glew-msvc/lib/)  
	ENDIF(${MINGW})
	
	# Handle the QUIETLY and REQUIRED arguments and set GLEW_FOUND to TRUE if all listed variables are TRUE.
	INCLUDE(FindPackageHandleStandardArgs)
	FIND_PACKAGE_HANDLE_STANDARD_ARGS(GLEW DEFAULT_MSG GLEW_LIBRARY GLEW_INCLUDE_DIR)
	# Copy the results to the output variables.
	IF(GLEW_FOUND)
        SET(GLEW_LIBRARIES ${GLEW_LIBRARY})
		SET(GLEW_INCLUDE_DIRS ${GLEW_INCLUDE_DIR})
		IF(${MINGW})
			add_custom_command(TARGET ${Executable_file} PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/glew-mingw/bin/glew32.dll"  "${CMAKE_CURRENT_SOURCE_DIR}/bin/" )
		ELSEIF(${MSVC})
			add_custom_command(TARGET ${Executable_file} PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/glew-msvc/bin/glew32.dll"  "${CMAKE_CURRENT_SOURCE_DIR}/bin/" )
		ENDIF(${MINGW})
	ELSE(GLEW_FOUND)
		SET(GLEW_LIBRARIES)
		SET(GLEW_INCLUDE_DIRS)
	ENDIF(GLEW_FOUND)

	MARK_AS_ADVANCED(GLEW_INCLUDE_DIRS GLEW_LIBRARIES)
	include_directories(${GLEW_INCLUDE_DIRS})
	link_directories(${GLEW_LIBRARY_DIRS})
	add_definitions(${GLEW_DEFINITIONS})
ENDIF(${WIN32})

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

	FIND_PATH(GLEW_INCLUDE_DIR NAMES GL/glew.h
		/usr/include
		/usr/local/include
		/sw/include
		/opt/local/include
		DOC "The directory where GL/glew.h resides")
	# Look for the library
	FIND_LIBRARY(GLEW_LIBRARY
	NAMES glew GLEW glew32 glew32s 
		PATHS
		/usr/lib64
		/usr/lib
		/usr/local/lib64
		/usr/local/lib
		/sw/lib
		/opt/local/lib)

	# Handle the QUIETLY and REQUIRED arguments and set GLEW_FOUND to TRUE if all listed variables are TRUE.
	INCLUDE(FindPackageHandleStandardArgs)
	FIND_PACKAGE_HANDLE_STANDARD_ARGS(GLEW DEFAULT_MSG GLEW_LIBRARY GLEW_INCLUDE_DIR)
	# Copy the results to the output variables.
	IF(GLEW_FOUND)
        SET(GLEW_LIBRARIES ${GLEW_LIBRARY})
		SET(GLEW_INCLUDE_DIRS ${GLEW_INCLUDE_DIR})
	ELSE(GLEW_FOUND)
		SET(GLEW_LIBRARIES)
		SET(GLEW_INCLUDE_DIRS)
	ENDIF(GLEW_FOUND)
	MARK_AS_ADVANCED(GLEW_INCLUDE_DIRS GLEW_LIBRARIES)
	include_directories(${GLEW_INCLUDE_DIRS})
	link_directories(${GLEW_LIBRARY_DIRS})
	add_definitions(${GLEW_DEFINITIONS})
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

if(NOT GLEW_FOUND)
    message(ERROR " GLEW not found!")
endif(NOT GLEW_FOUND)

########################################################
# Linking & stuff
#########################################################

 target_link_libraries( ${Executable_file} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY}  )


