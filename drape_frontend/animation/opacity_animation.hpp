#pragma once

#include "drape_frontend/animation/base_interpolator.hpp"

#include "drape/uniform_values_storage.hpp"

namespace df
{

class OpacityAnimation : public BaseInterpolator
{
  using TBase = BaseInterpolator;

public:
  OpacityAnimation(double duration, double startOpacity, double endOpacity);

  void Advance(double elapsedSeconds) override;
  double GetOpacity() const { return m_opacity; }

private:
  double m_startOpacity;
  double m_endOpacity;
  double m_opacity;
};

}