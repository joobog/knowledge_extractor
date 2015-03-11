project ( MLPlugin )

add_executable ( knowledgeextractortest
	amuxplugintest.cpp 
	)

target_link_libraries ( knowledgeextractortest
	siox-core-ModuleLoader
	siox-monitoring-activityPlugin-KnowledgeExtractor
	)
	
