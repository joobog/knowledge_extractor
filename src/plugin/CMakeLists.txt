project ( KnowledgeExtractor )

include_directories (
	${Siox_INCLUDE_DIR}
	${Predictor_INCLUDE_DIR}
	${Shogun_INCLUDE_DIR}
	)

add_library ( siox-monitoring-activityPlugin-KnowledgeExtractor SHARED
	#ActivityStore.cpp
	KnowledgeExtractor.cpp
	KnowledgeExtractorOptions.cpp
	)

target_link_libraries ( siox-monitoring-activityPlugin-KnowledgeExtractor
	siox-core-ModuleLoader
	siox-core-AutoConfigurator
	prediction
	${Boost_LIBRARIES}
	)

siox_run_serializer( KnowledgeExtractorOptions.hpp KnowledgeExtractorOptions.cpp )

install (TARGETS siox-monitoring-activityPlugin-KnowledgeExtractor LIBRARY DESTINATION ${KE_INSTALL_LIBRARY_DIR})

add_subdirectory( test )

