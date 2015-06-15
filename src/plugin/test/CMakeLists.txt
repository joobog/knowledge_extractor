project ( KnowledgeExtractor )

add_executable ( knowledgeextractortest
	amuxplugintest.cpp 
	)

target_link_libraries ( knowledgeextractortest
	${Boost_LIBRARIES}
	siox-core-ModuleLoader
	siox-monitoring-activityPlugin-KnowledgeExtractor
	)
	
