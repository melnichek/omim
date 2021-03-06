#pragma once

#include "drape_frontend/memory_feature_index.hpp"
#include "drape_frontend/engine_context.hpp"
#include "drape_frontend/tile_info.hpp"
#include "drape_frontend/read_mwm_task.hpp"

#include "geometry/screenbase.hpp"

#include "drape/pointers.hpp"
#include "drape/object_pool.hpp"

#include "base/thread_pool.hpp"

#include "std/set.hpp"
#include "std/shared_ptr.hpp"

namespace df
{

class MapDataProvider;
class CoverageUpdateDescriptor;

typedef shared_ptr<TileInfo> tileinfo_ptr;

class ReadManager
{
public:
  ReadManager(EngineContext & context, MapDataProvider & model);

  void UpdateCoverage(ScreenBase const & screen, set<TileKey> const & tiles);
  void Invalidate(set<TileKey> const & keyStorage);
  void Stop();

  static size_t ReadCount();

private:
  void OnTaskFinished(threads::IRoutine * task);
  bool MustDropAllTiles(ScreenBase const & screen) const;

  void PushTaskBackForTileKey(TileKey const & tileKey);
  void PushTaskFront(tileinfo_ptr const & tileToReread);

private:
  MemoryFeatureIndex m_memIndex;
  EngineContext & m_context;

  MapDataProvider & m_model;

  dp::MasterPointer<threads::ThreadPool> m_pool;

  ScreenBase m_currentViewport;

  struct LessByTileKey
  {
    bool operator ()(tileinfo_ptr const & l, tileinfo_ptr const & r) const
    {
      return *l < *r;
    }
  };

  typedef set<tileinfo_ptr, LessByTileKey> tile_set_t;
  tile_set_t m_tileInfos;

  ObjectPool<ReadMWMTask, ReadMWMTaskFactory> myPool;

  void CancelTileInfo(tileinfo_ptr const & tileToCancel);
  void ClearTileInfo(tileinfo_ptr const & tileToClear);
};

} // namespace df
