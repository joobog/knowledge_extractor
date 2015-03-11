/*
 * =====================================================================================
 *
 *       Filename:  amuxplugintest.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/09/2015 12:42:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <amuxplugin/KnowledgeExtractor.hpp>
#include <core/module/ModuleLoader.hpp>

int main(int argc, char ** argv) {
	using namespace std;


ActivityMultiplexer * multiplexer = core::module_create_instance<ActivityMultiplexer>("", "siox-monitoring-ActivityMultiplexerAsync", "monitoring_activitymultiplexer" );

	KnowledgeExtractor* knowledge_extractor = core::module_create_instance<KnowledgeExtractor>("", "siox-monitoring-activityPlugin-KnowledgeExtractor", ACTIVITY_MULTIPLEXER_PLUGIN_INTERFACE);

	KnowledgeExtractorOptions& op  = (KnowledgeExtractorOptions&) knowledge_extractor->getOptions();
	op.filename = "test.dat";
	op.multiplexer.componentPointer = multiplexer;

	multiplexer->init();
	knowledge_extractor->init();
	multiplexer->start();
	knowledge_extractor->start();
	
	
	multiplexer->stop();
	knowledge_extractor->stop();

	delete knowledge_extractor;
	delete multiplexer;

	cout << __PRETTY_FUNCTION__ << endl;
	return 0;
}
