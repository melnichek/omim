#pragma once

#include "framework.hpp"

#include "../geometry/rect2d.hpp"

#include "../base/timer.hpp"

#include "../std/string.hpp"
#include "../std/vector.hpp"
#include "../std/shared_ptr.hpp"

struct BenchmarkRectProvider;
class WindowHandle;
class PaintEvent;

template <typename TModel>
class BenchmarkFramework : public Framework<TModel>
{
private:

  typedef Framework<TModel> base_type;

  double m_paintDuration;
  double m_maxDuration;
  m2::RectD m_maxDurationRect;
  m2::RectD m_curBenchmarkRect;

  string m_startTime;

  struct BenchmarkResult
  {
    string m_name;
    m2::RectD m_rect;
    double m_time;
  };

  vector<BenchmarkResult> m_benchmarkResults;
  my::Timer m_benchmarksTimer;

  struct Benchmark
  {
    shared_ptr<BenchmarkRectProvider> m_provider;
    string m_name;
  };

  vector<Benchmark> m_benchmarks;
  size_t m_curBenchmark;

  bool m_isBenchmarkFinished;
  bool m_isBenchmarkInitialized;

  void BenchmarkCommandFinished();
  void NextBenchmarkCommand();
  void SaveBenchmarkResults();
  void SendBenchmarkResults();

  void MarkBenchmarkResultsStart();
  void MarkBenchmarkResultsEnd();

  void InitBenchmark();

  /// Removes all maps added in base class and adds only benchmarking maps
  void ReAddLocalMaps();

public:

  BenchmarkFramework();

  void OnSize(int w, int h);

  virtual void DoPaint(shared_ptr<PaintEvent> const & e);
};
