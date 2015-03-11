/*
 * =====================================================================================
 *
 *       Filename:  KnowledgeExtractor.cpp
 *
 *    Description: 
 *
 *        Version:  1.0
 *        Created:  03/09/2015 02:03:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "KnowledgeExtractor.hpp"

void KnowledgeExtractor::initPlugin() {
	using namespace std;
	cout << __PRETTY_FUNCTION__	<< endl;
	KnowledgeExtractorOptions& o = getOptions<KnowledgeExtractorOptions>();
	if (multiplexer == nullptr) {
		cout << __PRETTY_FUNCTION__ << " : " << "multiplexer is null" << endl;
		exit(1);
	}

	cout << "filename: " <<  o.filename << endl;
	multiplexer->registerCatchall(this, static_cast<ActivityMultiplexer::Callback>(&KnowledgeExtractor::Notify), false);	
}

void KnowledgeExtractor::Notify(const shared_ptr<Activity>& activity, int lost) {
	using namespace std;
	cout << __PRETTY_FUNCTION__	<< endl;
}

void KnowledgeExtractor::finalize() {
	using namespace std;
	cout << __PRETTY_FUNCTION__	<< endl;
	multiplexer->unregisterCatchall(this, false);	
	ActivityMultiplexerPlugin::finalize();
}

ComponentOptions* KnowledgeExtractor::AvailableOptions() {
	using namespace std;
	cout << __PRETTY_FUNCTION__	<< endl;
	return new KnowledgeExtractorOptions();
}

//void KnowledgeExtractor::start() {
//	using namespace std;
//	cout << __PRETTY_FUNCTION__	<< endl;
//}
//
//void KnowledgeExtractor::stop() {
//	using namespace std;
//	cout << __PRETTY_FUNCTION__	<< endl;
//}

extern "C" {
	void * MONITORING_ACTIVITY_MULTIPLEXER_PLUGIN_INSTANCIATOR_NAME()
	{
		return new KnowledgeExtractor();	
	}
}
