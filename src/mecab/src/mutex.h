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

#ifndef MECAB_MUTEX_H
#define MECAB_MUTEX_H

#include <string>
#include "common.h"
#include "string_buffer.h"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifndef MECAB_WITHOUT_MUTEX_LOCK
#ifdef HAVE_PTHREAD_H
#define _USE_PTHREAD_MUTEX
#include <pthread.h>
#else
#if defined(_WIN32) && !defined(__CYGWIN__)
#ifdef HAVE_WINDOWS_H
#include <windows.h>
#endif
#define _USE_WINDOWS_MUTEX
#endif
#endif
#endif

namespace MeCab {

class Mutex {
 private:
#ifdef _USE_PTHREAD_MUTEX
  pthread_mutex_t mutex_;
#else
#ifdef _USE_WINDOWS_MUTEX
  CRITICAL_SECTION mutex_;
#endif
#endif
  whatlog what_;

 public:
  const char *what() { return what_.str(); }

#ifdef _USE_PTHREAD_MUTEX
  Mutex()       { pthread_mutex_init(&mutex_, NULL); }
  virtual ~Mutex() {  pthread_mutex_destroy(&mutex_); }
  void lock()   { pthread_mutex_lock(&mutex_); }
  void unlock() { pthread_mutex_unlock(&mutex_); }
#else
#ifdef _USE_WINDOWS_MUTEX
  Mutex()       { InitializeCriticalSection(&mutex_); }
  virtual ~Mutex() {
    unlock();
    DeleteCriticalSection(&mutex_);
  }
  void lock()   { EnterCriticalSection(&mutex_); }
  void unlock() { LeaveCriticalSection(&mutex_); }
#else
  Mutex() { /* WHAT("this machine does not support mutex"); */ } /* for Open JTalk */
  virtual ~Mutex() {}
  void lock()   {}
  void unlock() {}
#endif
#endif
};
}

#endif
