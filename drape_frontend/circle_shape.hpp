#pragma once

#include "drape_frontend/map_shape.hpp"
#include "drape_frontend/shape_view_params.hpp"

namespace df
{

class CircleShape : public MapShape
{
public:
  CircleShape(m2::PointF const & mercatorPt, CircleViewParams const & params);

  virtual void Draw(dp::RefPointer<dp::Batcher> batcher, dp::RefPointer<dp::TextureManager> textures) const;

private:
  m2::PointF m_pt;
  CircleViewParams m_params;
};

} //namespace df
