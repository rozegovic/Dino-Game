set(DINO_NAME Dino)				#Naziv prvog projekta u solution-u

file(GLOB DINO_SOURCES  ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)
file(GLOB DINO_INCS  ${CMAKE_CURRENT_LIST_DIR}/src/*.h)
set(DINO_PLIST  ${CMAKE_CURRENT_LIST_DIR}/src/Info.plist)

# add executable
add_executable(${DINO_NAME} ${DINO_INCS} ${DINO_SOURCES})

source_group("inc"            FILES ${DINO_INCS})
source_group("src"            FILES ${DINO_SOURCES})

target_link_libraries(${DINO_NAME} debug ${MU_LIB_DEBUG} debug ${NATGUI_LIB_DEBUG} 
										optimized ${MU_LIB_RELEASE} optimized ${NATGUI_LIB_RELEASE})

setTargetPropertiesForGUIApp(${DINO_NAME} ${DINO_PLIST})

setIDEPropertiesForGUIExecutable(${DINO_NAME} ${CMAKE_CURRENT_LIST_DIR})

setPlatformDLLPath(${DINO_NAME})

#Set MU_WINDOWS|MU_MACOS|MU_LINUX, MU_64BIT|MU_32BIT
addMUCompileDefinitions(${DINO_NAME})
