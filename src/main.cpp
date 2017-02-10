#include <string>
#include "base_device.h"

int main(int argc, char *argv[]) {
  string a;
  int b;
  string c;

  brondan::BaseDevice base_device("config.xml");

  base_device.LogInit();

  brondan::BaseDevice base_device("config.xml");

  base_device.LogInit("another.log");

  return 0;
}
