CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

set(TARGET_EXE_NAME program2)
file(GLOB SOURCES "*.c*")

include_directories("${PROJECT_SOURCE_DIR}/modules")
add_executable(${TARGET_EXE_NAME} ${SOURCES})
target_link_libraries(${TARGET_EXE_NAME} ${STATIC_LIBS})

install (TARGETS ${TARGET_EXE_NAME} 
  DESTINATION "bin/${TARGET_EXE_NAME}")