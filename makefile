PROJECT_NAME?=TeamBuilder

BUILD_DIR?=build
SOURCE_DIR?=src

CXX?=clang++
CFLAGS+=-Wall -std=c++17 -Iinclude

# basic targets
main: mkBuildDir
	${CXX} ${CFLAGS} -o ${BUILD_DIR}/${PROJECT_NAME} ${SOURCE_DIR}/main.cpp

mkBuildDir:
	if [ ! -d ${BUILD_DIR} ]; then mkdir ${BUILD_DIR}; fi