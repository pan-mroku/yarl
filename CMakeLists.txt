CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(yarl)
SET(LIBS odb-sqlite odb QtCore QtGui)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-O2 -DDATABASE_SQLITE")

FIND_PACKAGE(Qt REQUIRED QtCore QtGui)

INCLUDE_DIRECTORIES(${QT_INCLUDES})
LINK_DIRECTORIES(${QT_LIBRARY_DIR})

ADD_CUSTOM_COMMAND(
  OUTPUT artist-odb.hxx artist-odb.cxx artist-odb.ixx
  COMMAND odb --profile qt -I${QT_HEADERS_DIR} --database sqlite --generate-query --generate-schema artist.hpp
  DEPENDS artist.hpp
)

ADD_EXECUTABLE(${PROJECT_NAME} main.cpp artist.hpp artist.cpp artist-odb.hxx artist-odb.cxx)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${LIBS})
