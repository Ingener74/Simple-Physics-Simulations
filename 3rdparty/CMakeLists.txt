cmake_minimum_required(VERSION 2.8)

include(ExternalProject)

ExternalProject_Add(
	external_OpenCV
	URL            ${CMAKE_CURRENT_LIST_DIR}/opencv-2.4.5.tar.gz
	CMAKE_ARGS     -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/3RDPARTY
	)

set(EXTERNAL_GLM external_glm)
ExternalProject_Add(
	${EXTERNAL_GLM}
	URL               ${CMAKE_CURRENT_LIST_DIR}/glm-0.9.3.4.tar.gz
	CMAKE_COMMAND     ""
	CONFIGURE_COMMAND ""
	BUILD_COMMAND     ""
	INSTALL_COMMAND   cp -R ${CMAKE_BINARY_DIR}/3rdparty/${EXTERNAL_GLM}-prefix/src/${EXTERNAL_GLM}/glm ${CMAKE_BINARY_DIR}/3RDPARTY/include
	)

set(EXTERNAL_GLEW external_GLEW)
ExternalProject_Add(
	${EXTERNAL_GLEW}
	URL                ${CMAKE_CURRENT_LIST_DIR}/glew-1.9.0.tgz
	CONFIGURE_COMMAND  ""
	BINARY_DIR         ${CMAKE_BINARY_DIR}/3rdparty/${EXTERNAL_GLEW}-prefix/src/${EXTERNAL_GLEW}
	INSTALL_COMMAND    export GLEW_DEST=${CMAKE_BINARY_DIR}/3RDPARTY && make install
	)

