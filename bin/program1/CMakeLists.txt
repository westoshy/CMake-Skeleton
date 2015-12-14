CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

# file(GLOB data_files "${PROJECT_SOURCE_DIR}/data/*")
# foreach(data_file ${data_files})
#   configure_file(data ${PROJECT_SOURCE_DIR}/data COPYONLY)


set(TARGET_EXE_NAME program1)
file(GLOB SOURCES "${CMAKE_CURRENT_LIST_DIR}/*.c*")


if(OpenCV_FOUND)
  include_directories("${PROJECT_SOURCE_DIR}/modules")
  include_directories("${OpenCV_DIR}/include")
  add_executable(${TARGET_EXE_NAME} ${SOURCES})
  target_link_libraries(${TARGET_EXE_NAME}
   ${STATIC_LIBS} ${OpenCV_LIBS})
 install (TARGETS ${TARGET_EXE_NAME} 
  DESTINATION "bin/${TARGET_EXE_NAME}") 
else()
  message([[
    OpenCV is not found in this environments.
    This project is not created!
    ]])
endif(OpenCV_FOUND)

