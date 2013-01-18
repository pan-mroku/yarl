CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(yarl)
SET(LIBS odb-sqlite odb QtCore QtGui)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-O2 -DDATABASE_SQLITE -std=c++0x -g")

FIND_PACKAGE(Qt REQUIRED QtCore QtGui)

INCLUDE_DIRECTORIES(${QT_INCLUDES})
LINK_DIRECTORIES(${QT_LIBRARY_DIR})

SET(ODB_CLASSES artist album library cd track treeitem)

FOREACH(HPP ${ODB_CLASSES})
  ADD_CUSTOM_COMMAND(
    OUTPUT ${HPP}-odb.hxx ${HPP}-odb.cxx ${HPP}-odb.ixx 
    COMMAND odb --std c++11 --profile qt -I${QT_HEADERS_DIR} --database sqlite --generate-query --generate-schema ${HPP}.hpp 
    DEPENDS ${HPP}.hpp
    )
SET(ODB_FILES ${ODB_FILES} ${HPP}.hpp ${HPP}.cpp ${HPP}-odb.hxx ${HPP}-odb.cxx ${HPP}-odb.ixx)
ENDFOREACH(HPP)

QT4_WRAP_UI(UIS mainwindow.ui dialog.ui)
QT4_WRAP_CPP(MOCS mainwindow.hpp dialog.hpp)

ADD_EXECUTABLE(${PROJECT_NAME} 
  main.cpp 
  model.hpp model.cpp
  mainwindow.hpp mainwindow.cpp
  dialog.hpp dialog.cpp
  ${ODB_FILES}
  ${UIS}
  ${MOCS}
  )

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${LIBS})
