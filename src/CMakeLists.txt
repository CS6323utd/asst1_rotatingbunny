cmake_minimum_required(VERSION 2.8)

#-------------------------------------------------------------------------------
# Set include directories
#-------------------------------------------------------------------------------
include_directories(
    ${GLEW_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS}
    ${APP_INCLUDE_DIRS}
)

if (WIN32)
    include_directories(dirent)
endif(WIN32)

#-------------------------------------------------------------------------------
# Set link directories
#-------------------------------------------------------------------------------
link_directories(
    ${GLEW_LIBRARY_DIRS}
    ${GLFW_LIBRARY_DIRS}
)

# Set app source
set(APP_SOURCE
    Animation.cpp
    Renderer.cpp
    main.cpp
)

if (WIN32)
    list(APPEND APP_SOURCE dirent/dirent.c)
endif(WIN32)

# Set app header
set(APP_HEADER
    Animation.h
    Camera.h
    Lighting.h
    Object.h
    Renderer.h
    Shader.h
)

#-------------------------------------------------------------------------------
# Add executable
#-------------------------------------------------------------------------------
add_executable( asst1
    ${APP_SOURCE}
    ${APP_HEADER}
)

# Link asst1 executable (static link reference solution)
target_link_libraries( asst1
    nanogui ${NANOGUI_EXTRA_LIBS}
    ${OPENGL_LIBRARIES}
    glew ${GLEW_LIBRARIES}
    glfw ${GLFW_LIBRARIES}
    glm
)


if (APPLE) # Frameworks required on osx
  target_link_libraries(asst1  
    ${COCOA_LIBRARIES}
    ${IOKIT_LIBRARIES}
    ${COREVIDEO_LIBRARIES}
  )
else(UNIX)  #LINUX
target_link_libraries( asst1
    ${GLEW_LIBRARIES}
    ${GLFW_LIBRARIES}
    ${OPENGL_LIBRARIES}
    -fopenmp 
    -lXi 
    -lXxf86vm 
    -lXinerama 
    -lXcursor 
    -lXfixes 
    -lXrandr 
    -lXext 
    -lXrender 
    -lX11 
    -lpthread 
    -lxcb 
    -lXau
)
endif()

# Put executable in build directory root
set(EXECUTABLE_OUTPUT_PATH ..)

# Install to project root
install(TARGETS asst1 DESTINATION ${asst1_SOURCE_DIR})