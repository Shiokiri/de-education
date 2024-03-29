add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

### GLFW ###

add_subdirectory (glfw-3.1.2)

include_directories(
	glfw-3.1.2/include/GLFW/
	glew-1.13.0/include/
)

set(OPENGL_LIBRARY
	${OPENGL_LIBRARY}
	-lGL -lGLU -lXrandr -lXext -lX11 -lrt
	${CMAKE_DL_LIBS}
	${GLFW_LIBRARIES}
)

### GLEW ###

set(GLEW_SOURCE
	glew-1.13.0/src/glew.c
)

set(GLEW_HEADERS
)


add_library( GLEW_1130 STATIC
	${GLEW_SOURCE}
	${GLEW_INCLUDE}
)

target_link_libraries(GLEW_1130
	${OPENGL_LIBRARY}
	${EXTRA_LIBS}
)

### BULLET ###
# Bullet already has a CMakeLists.txt so let's use these

set(BULLET_VERSION 2.81)
include_directories(
	bullet-2.81-rev2613/src
)
add_subdirectory( bullet-2.81-rev2613/src/BulletSoftBody )
add_subdirectory( bullet-2.81-rev2613/src/BulletCollision )
add_subdirectory( bullet-2.81-rev2613/src/BulletDynamics )
add_subdirectory( bullet-2.81-rev2613/src/LinearMath )
