cmake_minimum_required(VERSION 2.8)

include(ExternalProject)

ExternalProject_Add(
    external_OpenCV
    URL            ${CMAKE_CURRENT_LIST_DIR}/opencv-2.4.5.tar.gz
    CMAKE_ARGS     -DCMAKE_INSTALL_PREFIX=${SPS_INSTALL_3RDPARTY_DIR}
    )
ExternalProject_Add(
    external_glm
    URL             ${CMAKE_CURRENT_LIST_DIR}/glm-0.9.3.4.tar.gz
    CMAKE_ARGS      -DCMAKE_INSTALL_PREFIX=${SPS_INSTALL_3RDPARTY_DIR} -DGLM_TEST_ENABLE=ON
	)
set(EXTERNAL_GLEW external_GLEW)
ExternalProject_Add(
    ${EXTERNAL_GLEW}
    URL                ${CMAKE_CURRENT_LIST_DIR}/glew-1.9.0.tgz
    CONFIGURE_COMMAND  ""
    BINARY_DIR         ${CMAKE_BINARY_DIR}/3rdparty/${EXTERNAL_GLEW}-prefix/src/${EXTERNAL_GLEW}
    INSTALL_COMMAND    export GLEW_DEST=${SPS_INSTALL_3RDPARTY_DIR} && make install
    )

