//  MeCab -- Yet Another Part-of-Speech and Morphological Analyzer
//
//
//  Copyright(C) 2001-2006 Taku Kudo <taku@chasen.org>
//  Copyright(C) 2004-2006 Nippon Telegraph and Telephone Corporation

/* ----------------------------------------------------------------- */
/*           The Japanese TTS System "Open JTalk"                    */
/*           developed by HTS Working Group                          */
/*           http://open-jtalk.sourceforge.net/                      */
/* ----------------------------------------------------------------- */
/*                                                                   */
/*  Copyright (c) 2008-2011  Nagoya Institute of Technology          */
/*                           Department of Computer Science          */
/*                                                                   */
/* All rights reserved.                                              */
/*                                                                   */
/* Redistribution and use in source and binary forms, with or        */
/* without modification, are permitted provided that the following   */
/* conditions are met:                                               */
/*                                                                   */
/* - Redistributions of source code must retain the above copyright  */
/*   notice, this list of conditions and the following disclaimer.   */
/* - Redistributions in binary form must reproduce the above         */
/*   copyright notice, this list of conditions and the following     */
/*   disclaimer in the documentation and/or other materials provided */
/*   with the distribution.                                          */
/* - Neither the name of the HTS working group nor the names of its  */
/*   contributors may be used to endorse or promote products derived */
/*   from this software without specific prior written permission.   */
/*                                                                   */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND            */
/* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,       */
/* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF          */
/* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE          */
/* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS */
/* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,          */
/* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED   */
/* TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     */
/* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON */
/* ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,   */
/* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY    */
/* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE           */
/* POSSIBILITY OF SUCH DAMAGE.                                       */
/* ----------------------------------------------------------------- */

#ifndef MECAB_MEM_POOL_H
#define MECAB_MEM_POOL_H

#include <map>
#ifndef MECAB_WITHOUT_SHARE_DIC

#include "mutex.h"

#define MMAP_OPEN(type, map, file, mode) do {                   \
    MemoryPool<std::string, Mmap<type> >& pool__ =              \
        getMemoryPool<std::string, Mmap<type> >();              \
    map = pool__.get((file));                                   \
    pool__.lock();                                              \
    if (map->begin() == 0 && !map->open(file.c_str(), mode)) {  \
      WHAT << map->what();                                      \
      close();                                                  \
      pool__.unlock();                                          \
      return false;                                             \
    }                                                           \
    pool__.unlock();                                            \
  } while (0)

#define MMAP_CLOSE(type, map) do {                      \
    MemoryPool<std::string, Mmap<type> >& pool__ =      \
        getMemoryPool<std::string, Mmap<type> >();      \
    pool__.release(map);                                \
    map = 0; } while (0)

namespace MeCab {

template <typename _Key, typename _Value> class MemoryPool {
 private:
  std::map<_Key, _Value*> pool_;
  std::map<_Value*, std::pair<_Key, size_t> > rpool_;
  Mutex mutex_;

 public:
  typedef _Key   key_type;
  typedef _Value value_type;

  explicit MemoryPool() {}

  virtual ~MemoryPool() {
    mutex_.lock();
    for (typename std::map<_Key, _Value*>::iterator it = pool_.begin();
         it != pool_.end(); it++)
      delete it->second;
    mutex_.unlock();
  }

  void lock() { mutex_.lock(); }
  void unlock() { mutex_.unlock(); }

  value_type* get(const key_type &key) {
    mutex_.lock();

    typename std::map<_Key, _Value*>::iterator it = pool_.find(key);
    _Value* m = 0;

    if (it == pool_.end()) {
      m = new _Value;
      pool_.insert(std::make_pair(key, m));
      rpool_[m] = std::make_pair(key, static_cast<size_t>(1));
    } else {
      m = it->second;
      rpool_[m].second++;  // reference count;
    }

    mutex_.unlock();

    return m;
  }

  void release(value_type *m = 0) {
    mutex_.lock();

    if (m) {
      typename std::map<_Value*, std::pair<_Key, size_t> >::iterator
          it = rpool_.find(m);
      if (it != rpool_.end()) {
        --it->second.second;
        if (it->second.second == 0) {
          typename std::map<_Key, _Value*>::iterator it2 =
              pool_.find(it->second.first);
          pool_.erase(it2);
          rpool_.erase(it);
          delete m;
          m = 0;
        }
      }
    }

    mutex_.unlock();
  }
};

template <class _Key, class _Value> MemoryPool<_Key, _Value>&
getMemoryPool() {
  static MemoryPool<_Key, _Value> mempool;
  return mempool;
}
}

#else

/* for Open JTalk */
#define MMAP_OPEN(type, map, file, mode) do {   \
    map = new Mmap<type>;                       \
    if (!map->open(file.c_str(), mode)) {       \
      close();                                  \
      return false;                             \
    }                                           \
  } while (0)

/* for Open JTalk */
#define MMAP_CLOSE(type, map) do {              \
    if(map) delete map; map = NULL; } while (0)

#endif
#endif
