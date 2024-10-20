PROJECT_NAME?=TeamBuilder

BUILD_DIR?=build
SOURCE_DIR?=src

CXX?=clang++
CXXFLAGS+=-Wall -std=c++17 -Iinclude

# basic targets
main: iograph
	${CXX} ${CXXFLAGS} -o ${BUILD_DIR}/${PROJECT_NAME} ${SOURCE_DIR}/main.cpp ${BUILD_DIR}/graph.o ${BUILD_DIR}/iograph.o

mkBuildDir:
	if [ ! -d ${BUILD_DIR} ]; then mkdir ${BUILD_DIR}; fi

clean:
	rm -f ${BUILD_DIR}/*.o

# objects
graph: mkBuildDir
	${CXX} ${CXXFLAGS} -c -o ${BUILD_DIR}/graph.o ${SOURCE_DIR}/graph.cpp

iograph: graph
	${CXX} ${CXXFLAGS} -c -o ${BUILD_DIR}/iograph.o ${SOURCE_DIR}/iograph.cpp