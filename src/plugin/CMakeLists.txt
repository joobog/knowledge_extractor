project ( KnowledgeExtractor )

include_directories (
	${Siox_INCLUDE_DIR}
	)

add_library ( siox-monitoring-activityPlugin-KnowledgeExtractor SHARED
	KnowledgeExtractor.cpp
	KnowledgeExtractorOptions.cpp
	)

target_link_libraries ( siox-monitoring-activityPlugin-KnowledgeExtractor
	-L${Siox_LIBRARY_DIR}
	siox-core-ModuleLoader
	#boost_serialization
	-L${Boost_LIBRARY_DIR}
	${Boost_LIBRARIES}
	siox-core-AutoConfigurator
	)

siox_run_serializer( KnowledgeExtractorOptions.hpp KnowledgeExtractorOptions.cpp )

install (TARGETS siox-monitoring-activityPlugin-KnowledgeExtractor LIBRARY DESTINATION ${KE_INSTALL_LIBRARY_DIR})

#add_subdirectory( test )

