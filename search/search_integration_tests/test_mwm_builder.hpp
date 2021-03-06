#pragma once

#include "geometry/point2d.hpp"

#include "std/string.hpp"
#include "std/unique_ptr.hpp"

class Classificator;

namespace feature
{
class FeaturesCollector;
}
namespace platform
{
class LocalCountryFile;
}

class TestMwmBuilder
{
public:
  TestMwmBuilder(platform::LocalCountryFile & file);

  ~TestMwmBuilder();

  void AddPOI(m2::PointD const & p, string const & name, string const & lang);

  void Finish();

private:
  platform::LocalCountryFile & m_file;
  unique_ptr<feature::FeaturesCollector> m_collector;
  Classificator const & m_classificator;
};
