CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(yarl)
SET(LIBS odb-sqlite odb QtCore QtGui)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-O2 -DDATABASE_SQLITE -std=c++0x -g")

FIND_PACKAGE(Qt REQUIRED QtCore QtGui)

INCLUDE_DIRECTORIES(${QT_INCLUDES})
LINK_DIRECTORIES(${QT_LIBRARY_DIR})

ADD_CUSTOM_COMMAND(
  OUTPUT artist-odb.hxx artist-odb.cxx artist-odb.ixx library-odb.hxx library-odb.cxx library-odb.ixx
  COMMAND odb --std c++11 --database sqlite --generate-query --generate-schema artist.hpp library.hpp
  DEPENDS artist.hpp library.hpp
)

QT4_WRAP_UI(UIS mainwindow.ui)
QT4_Wrap_CPP(MOCS mainwindow.hpp)

ADD_EXECUTABLE(${PROJECT_NAME} 
  main.cpp 
  treeitem.hpp treeitem.cpp 
  artist.hpp artist.cpp artist-odb.hxx artist-odb.cxx 
  library.hpp library.cpp library-odb.hxx library-odb.cxx 
  rootitem.hpp rootitem.cpp 
  artistitem.hpp artistitem.cpp
  model.hpp model.cpp
  mainwindow.hpp mainwindow.cpp
  ${UIS}
  ${MOCS}
)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${LIBS})
