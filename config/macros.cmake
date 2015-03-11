macro(SIOX_RUN_SERIALIZER IN OUT)
	add_custom_command(
		OUTPUT ${OUT}
		COMMENT "Generating boost serialization ${IN}"
		COMMAND ${PYTHON_EXECUTABLE} ${Siox_DEV_ROOT_DIR}/devel/scripts/serialization-code-generator.py
		ARGS -I ${Siox_DEV_ROOT_DIR}/src/include ${Siox_DEV_ROOT_DIR}/src -i ${CMAKE_CURRENT_SOURCE_DIR}/${IN} -o ${OUT}
		)
endmacro(SIOX_RUN_SERIALIZER)


macro(SET_LIBRARY_INSTALL_SUFFIX)
	get_property(LIB64 GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS)
	if (${LIB64} STREQUAL "TRUE")
		set(LIBRARY_INSTALL_SUFFIX 64)
	else()
		set(LIBRARY_INSTALL_SUFFIX "")
	endif()
endmacro(SET_LIBRARY_INSTALL_SUFFIX)
