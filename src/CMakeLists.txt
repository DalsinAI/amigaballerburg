

include_directories(${CMAKE_BINARY_DIR} ${SDL_INCLUDE_DIR})

if(MATH_INCLUDE_DIR)
	include_directories(${MATH_INCLUDE_DIR})
endif(MATH_INCLUDE_DIR)

add_executable (ballerburg baller1.c baller2.c ballergui.c cannoneer.c
			screen.c psg.c dlgAlert.c sdlgui.c market.c
			music.c paths.c settings.c sdlgfx.c)

target_link_libraries(ballerburg ${SDL_LIBRARY})

if(SDLMAIN_LIBRARY)
	target_link_libraries(ballerburg ${SDLMAIN_LIBRARY})
endif(SDLMAIN_LIBRARY)

if(MATH_LIBRARY)
	target_link_libraries(ballerburg ${MATH_LIBRARY})
endif(MATH_LIBRARY)

if(EMSCRIPTEN)
	set_target_properties(ballerburg PROPERTIES LINK_FLAGS
		"-s USE_SDL=2 -s ASYNCIFY -s ASSERTIONS=0 \
		-s EXPORTED_RUNTIME_METHODS='[\"ccall\",\"cwrap\"]' \
		--preload-file ${CMAKE_SOURCE_DIR}/src/baller.mus@baller.mus \
		--preload-file ${CMAKE_SOURCE_DIR}/src/baller.dat@baller.dat"
	)
endif()

install(TARGETS ballerburg RUNTIME DESTINATION ${BINDIR})
install(FILES baller.dat baller.mus DESTINATION ${DATADIR})
