/*
 * =====================================================================================
 *
 *       Filename:  AMumPlugin.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/09/2015 02:00:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef KNOWLEDGEEXTRACTOR_HPP
#define KNOWLEDGEEXTRACTOR_HPP

#include <monitoring/activity_multiplexer/ActivityMultiplexerPluginImplementation.hpp>
#include <monitoring/datatypes/Activity.hpp>
#include <core/reporting/ComponentReportInterface.hpp>
#include "KnowledgeExtractorOptions.hpp"

class KnowledgeExtractor : public monitoring::ActivityMultiplexerPlugin, public core::ComponentReportInterface {
	public:
		void Notify(const shared_ptr<Activity>& activity, int lost);
		void initPlugin() override;
//		void start() override;
//		void stop() override;
 		ComponentOptions* AvailableOptions() override;
		ComponentReport prepareReport() override {return ComponentReport{};}
		void finalize() override;
};

#endif
