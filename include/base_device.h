/* Author: brondan */
/* This is a base class of various devices */
#ifndef BASE_DEVICE_H_
#define BASE_DEVICE_H_

#include <string>
/* boost xml */
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
/* boost log */
#include <boost/log/sources/logger.hpp>

using std::string;
namespace src = boost::log::sources;
namespace pt = boost::property_tree;

namespace brondan {

class BaseDevice {
 public:
  enum LogDefault {
    DEFAULT_ROTATION_SIZE = 10 * 1024 * 1024,
    DEFAULT_UPDATE_HOUR = 0,
    DEFAULT_UPDATE_MIN = 0,
    DEFAULT_UPDATE_SEC = 0,
  };
  const char* DEFAULT_PATH = "debug.log";

  explicit BaseDevice(const string& config_file);

  int LogInit(const string& path=DEFAULT_PATH);

 private:
  string config_file_;
  pt::ptree pt_;
  src::logger log_;
};

}  /* brondan */

#endif  /* BASE_DEVICE_H_ */