/* Author: brondan */
/* This is a base class of various devices */
#include "base_device.h"
#include <boost/locale/encoding.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

/* boost xml */
namespace xml = boost::property_tree::xml_parser;
/* boost locale */
namespace conv = boost::locale::conv;
/* boost log */
namespace logging = boost::log;
namespace keywords = boost::log::keywords;
namespace sinks = boost::log::sinks;
using namespace boost::log::trivial;

namespace brondan {

BaseDevice::BaseDevice(const string& config_file) : config_file_(config_file) {
  xml::read_xml(config_file_, pt_);
}

int BaseDevice::LogInit(const string& path) {
  logging::add_file_log(
      keywords::file_name = path,
      keywords::rotation_size = DEFAULT_ROTATION_SIZE,
      keywords::time_based_rotation =
          sinks::file::rotation_at_time_point(DEFAULT_UPDATE_HOUR,
                                            DEFAULT_UPDATE_MIN,
                                            DEFAULT_UPDATE_SEC)
  );

  BOOST_LOG(log_) << "log ready";
}

}  /* brondan */