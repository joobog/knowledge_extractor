#include <boost/serialization/serialization.hpp> 
#include <boost/serialization/nvp.hpp>           
#include <boost/serialization/vector.hpp>        
#include <boost/serialization/map.hpp>           
#include <boost/serialization/list.hpp>          
#include <boost/serialization/tracking.hpp>      
#include <boost/serialization/level.hpp>         
#include <boost/serialization/export.hpp>        
#include <boost/archive/xml_iarchive.hpp> 
#include <boost/archive/xml_oarchive.hpp>  
#include "/scratch/pool/CIS/m215026/git/siox_ml_plugin/src/amuxplugin/KnowledgeExtractorOptions.hpp" 

using namespace core;

#ifndef BOOST_SERIALIZABLE_Container 
#define BOOST_SERIALIZABLE_Container 
namespace boost { 
namespace serialization { 
	template<class Archive> 
	void serialize(Archive &ar, Container &a, const unsigned int version) 
	{
	}
}
}

BOOST_CLASS_EXPORT(Container) 
BOOST_CLASS_IMPLEMENTATION(Container, boost::serialization::object_serializable) 
BOOST_CLASS_TRACKING(Container, boost::serialization::track_never)
#endif

#include <include/core/component/ComponentReferenceBoostSerialization.hpp>
using namespace core;
using namespace monitoring;

#ifndef BOOST_SERIALIZABLE_ActivityMultiplexerPluginOptions 
#define BOOST_SERIALIZABLE_ActivityMultiplexerPluginOptions 
namespace boost { 
namespace serialization { 
	template<class Archive> 
	void serialize(Archive &ar, ActivityMultiplexerPluginOptions &a, const unsigned int version) 
	{
		ar &boost::serialization::make_nvp("multiplexer", a.multiplexer);
		ar &boost::serialization::make_nvp("dereferenceFacade", a.dereferenceFacade);
 
                ar &boost::serialization::make_nvp("Container", boost::serialization::base_object<Container>(a)); 
	}
}
}

BOOST_CLASS_EXPORT(ActivityMultiplexerPluginOptions) 
BOOST_CLASS_IMPLEMENTATION(ActivityMultiplexerPluginOptions, boost::serialization::object_serializable) 
BOOST_CLASS_TRACKING(ActivityMultiplexerPluginOptions, boost::serialization::track_never)
#endif

using namespace core;
using namespace monitoring;

#ifndef BOOST_SERIALIZABLE_KnowledgeExtractorOptions 
#define BOOST_SERIALIZABLE_KnowledgeExtractorOptions 
namespace boost { 
namespace serialization { 
	template<class Archive> 
	void serialize(Archive &ar, KnowledgeExtractorOptions &a, const unsigned int version) 
	{
		ar &boost::serialization::make_nvp("filename", a.filename);
		ar &boost::serialization::make_nvp("openTokens", a.openTokens);
		ar &boost::serialization::make_nvp("seekTokens", a.seekTokens);
		ar &boost::serialization::make_nvp("readTokens", a.readTokens);
		ar &boost::serialization::make_nvp("writeTokens", a.writeTokens);
		ar &boost::serialization::make_nvp("closeTokens", a.closeTokens);
 
                ar &boost::serialization::make_nvp("ActivityMultiplexerPluginOptions", boost::serialization::base_object<monitoring::ActivityMultiplexerPluginOptions>(a)); 
	}
}
}

BOOST_CLASS_EXPORT(KnowledgeExtractorOptions) 
BOOST_CLASS_IMPLEMENTATION(KnowledgeExtractorOptions, boost::serialization::object_serializable) 
BOOST_CLASS_TRACKING(KnowledgeExtractorOptions, boost::serialization::track_never)
template void boost::serialization::serialize(boost::archive::xml_oarchive &ar, KnowledgeExtractorOptions &g, const unsigned int version);
template void boost::serialization::serialize(boost::archive::xml_iarchive &ar, KnowledgeExtractorOptions &g, const unsigned int version);

#endif

