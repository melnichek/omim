#pragma once

#include "render_policy_mt.hpp"

class BenchmarkRenderPolicyMT : public RenderPolicyMT
{
public:
  BenchmarkRenderPolicyMT(VideoTimer * videoTimer,
                          DrawerYG::Params const & params,
                          shared_ptr<yg::gl::RenderContext> const & primaryRC);

  void DrawFrame(shared_ptr<PaintEvent> const & e, ScreenBase const & s);
};
