/*
  MeCab -- Yet Another Part-of-Speech and Morphological Analyzer


  Copyright(C) 2001-2006 Taku Kudo <taku@chasen.org>
  Copyright(C) 2004-2006 Nippon Telegraph and Telephone Corporation
*/

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

#ifndef MECAB_MECAB_H
#define MECAB_MECAB_H

/* C/C++ common data structures  */
struct mecab_dictionary_info_t {
  const char                     *filename;
  const char                     *charset;
  unsigned int                    size;
  int                             type;
  unsigned int                    lsize;
  unsigned int                    rsize;
  unsigned short                  version;
  struct mecab_dictionary_info_t *next;
};

struct mecab_path_t {
  struct mecab_node_t* rnode;
  struct mecab_path_t* rnext;
  struct mecab_node_t* lnode;
  struct mecab_path_t* lnext;
  int                  cost;
  float                prob;
};

struct mecab_learner_path_t {
  struct mecab_learner_node_t*  rnode;
  struct mecab_learner_path_t*  rnext;
  struct mecab_learner_node_t*  lnode;
  struct mecab_learner_path_t*  lnext;
  double                        cost;
  const int                     *fvector;
};

struct mecab_token_t {
  unsigned short lcAttr;
  unsigned short rcAttr;
  unsigned short posid;
  short wcost;
  unsigned int   feature;
  unsigned int   compound;  /* reserved for noun compound */
};

struct mecab_node_t {
  struct mecab_node_t  *prev;
  struct mecab_node_t  *next;
  struct mecab_node_t  *enext;
  struct mecab_node_t  *bnext;
  struct mecab_path_t  *rpath;
  struct mecab_path_t  *lpath;
  struct mecab_node_t **begin_node_list;
  struct mecab_node_t **end_node_list;
  const char           *surface;
  const char           *feature;
  unsigned int          id;
  unsigned short        length; /* length of morph */
  unsigned short        rlength; /* real length of morph(include white space before the morph) */
  unsigned short        rcAttr;
  unsigned short        lcAttr;
  unsigned short        posid;
  unsigned char         char_type;
  unsigned char         stat;
  unsigned char         isbest;
  unsigned int          sentence_length; /* it is avaialbe only when BOS node */
  float                 alpha;
  float                 beta;
  float                 prob;
  short                 wcost;
  long                  cost;
  struct mecab_token_t  *token;
};

/* almost the same as mecab_node_t.
   used only for cost estimation */
struct mecab_learner_node_t {
  struct mecab_learner_node_t *prev;
  struct mecab_learner_node_t *next;
  struct mecab_learner_node_t *enext;
  struct mecab_learner_node_t *bnext;
  struct mecab_learner_path_t *rpath;
  struct mecab_learner_path_t *lpath;
  struct mecab_learner_node_t *anext;
  const char                  *surface;
  const char                  *feature;
  unsigned int                 id;
  unsigned short               length;
  unsigned short               rlength;
  unsigned short               rcAttr;
  unsigned short               lcAttr;
  unsigned short               posid;
  unsigned char                char_type;
  unsigned char                stat;
  unsigned char                isbest;
  double                       alpha;
  double                       beta;
  short                        wcost2;
  double                       wcost;
  double                       cost;
  const int                    *fvector;
  struct mecab_token_t         *token;
};

#define MECAB_NOR_NODE  (0)
#define MECAB_UNK_NODE  (1)
#define MECAB_BOS_NODE  (2)
#define MECAB_EOS_NODE  (3)
#define MECAB_EON_NODE  (4)

#define MECAB_USR_DIC   (1)
#define MECAB_SYS_DIC   (0)
#define MECAB_UNK_DIC   (2)

/* C interface  */
#ifdef __cplusplus
#include <cstdio>
#else
#include <stdio.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
#include <windows.h>
/* for Open JTalk
#  ifdef DLL_EXPORT
#    define MECAB_DLL_EXTERN  __declspec(dllexport)
#  else
#    define MECAB_DLL_EXTERN  __declspec(dllimport)
#  endif
*/
#endif

#ifndef MECAB_DLL_EXTERN
#  define MECAB_DLL_EXTERN extern
#endif

  typedef struct mecab_t                 mecab_t;
  typedef struct mecab_dictionary_info_t mecab_dictionary_info_t;
  typedef struct mecab_node_t            mecab_node_t;
  typedef struct mecab_learner_node_t    mecab_learner_node_t;
  typedef struct mecab_path_t            mecab_path_t;
  typedef struct mecab_learner_path_t    mecab_learner_path_t;
  typedef struct mecab_token_t           mecab_token_t;

#ifndef SWIG
  /* C interface */
  MECAB_DLL_EXTERN int           mecab_do (int argc, char **argv);

  MECAB_DLL_EXTERN mecab_t*      mecab_new(int argc, char **argv);
  MECAB_DLL_EXTERN mecab_t*      mecab_new2(const char *arg);
  MECAB_DLL_EXTERN const char*   mecab_version();
  MECAB_DLL_EXTERN const char*   mecab_strerror(mecab_t *mecab);
  MECAB_DLL_EXTERN void          mecab_destroy(mecab_t *mecab);

  MECAB_DLL_EXTERN int           mecab_get_partial(mecab_t *mecab);
  MECAB_DLL_EXTERN void          mecab_set_partial(mecab_t *mecab, int partial);
  MECAB_DLL_EXTERN float         mecab_get_theta(mecab_t *mecab);
  MECAB_DLL_EXTERN void          mecab_set_theta(mecab_t *mecab, float theta);
  MECAB_DLL_EXTERN int           mecab_get_lattice_level(mecab_t *mecab);
  MECAB_DLL_EXTERN void          mecab_set_lattice_level(mecab_t *mecab, int level);
  MECAB_DLL_EXTERN int           mecab_get_all_morphs(mecab_t *mecab);
  MECAB_DLL_EXTERN void          mecab_set_all_morphs(mecab_t *mecab, int all_morphs);

  MECAB_DLL_EXTERN const char*   mecab_sparse_tostr(mecab_t *mecab, const char *str);
  MECAB_DLL_EXTERN const char*   mecab_sparse_tostr2(mecab_t *mecab, const char *str, size_t len);
  MECAB_DLL_EXTERN char*         mecab_sparse_tostr3(mecab_t *mecab, const char *str, size_t len,
                                                     char *ostr, size_t olen);
  MECAB_DLL_EXTERN const mecab_node_t* mecab_sparse_tonode(mecab_t *mecab, const char*);
  MECAB_DLL_EXTERN const mecab_node_t* mecab_sparse_tonode2(mecab_t *mecab, const char*, size_t);
  MECAB_DLL_EXTERN const char*   mecab_nbest_sparse_tostr(mecab_t *mecab, size_t N, const char *str);
  MECAB_DLL_EXTERN const char*   mecab_nbest_sparse_tostr2(mecab_t *mecab, size_t N,
                                                           const char *str, size_t len);
  MECAB_DLL_EXTERN char*         mecab_nbest_sparse_tostr3(mecab_t *mecab, size_t N,
                                                           const char *str, size_t len,
                                                           char *ostr, size_t olen);
  MECAB_DLL_EXTERN int           mecab_nbest_init(mecab_t *mecab, const char *str);
  MECAB_DLL_EXTERN int           mecab_nbest_init2(mecab_t *mecab, const char *str, size_t len);
  MECAB_DLL_EXTERN const char*   mecab_nbest_next_tostr(mecab_t *mecab);
  MECAB_DLL_EXTERN char*         mecab_nbest_next_tostr2(mecab_t *mecab, char *ostr, size_t olen);
  MECAB_DLL_EXTERN const mecab_node_t* mecab_nbest_next_tonode(mecab_t *mecab);
  MECAB_DLL_EXTERN const char*   mecab_format_node(mecab_t *mecab, const mecab_node_t *node);
  MECAB_DLL_EXTERN const mecab_dictionary_info_t* mecab_dictionary_info(mecab_t *mecab);
  MECAB_DLL_EXTERN int           mecab_dict_index(int argc, char **argv);
  MECAB_DLL_EXTERN int           mecab_dict_gen(int argc, char **argv);
  MECAB_DLL_EXTERN int           mecab_cost_train(int argc, char **argv);
  MECAB_DLL_EXTERN int           mecab_system_eval(int argc, char **argv);
  MECAB_DLL_EXTERN int           mecab_test_gen(int argc, char **argv);
#endif

#ifdef __cplusplus
}
#endif

/* C++ interface */
#ifdef __cplusplus

namespace MeCab {
typedef struct mecab_dictionary_info_t DictionaryInfo;
typedef struct mecab_path_t            Path;
typedef struct mecab_node_t            Node;
typedef struct mecab_learner_path_t    LearnerPath;
typedef struct mecab_learner_node_t    LearnerNode;
typedef struct mecab_token_t           Token;

class Tagger {
 public:

#ifndef SWIG
  virtual const char* parse(const char *str, size_t len, char *ostr, size_t olen) = 0;
  virtual const char* parse(const char *str, size_t len)                          = 0;
  virtual const Node* parseToNode(const char *str, size_t len)                    = 0;
  virtual const char* parseNBest(size_t N, const char *str, size_t len)           = 0;
  virtual bool  parseNBestInit(const char *str, size_t len)                       = 0;
#endif

  virtual const char* parse(const char *str)                = 0;
  virtual const Node* parseToNode(const char *str)          = 0;
  virtual const char* parseNBest(size_t N, const char *str) = 0;
  virtual bool  parseNBestInit(const char *str)             = 0;
  virtual const Node* nextNode()                            = 0;
  virtual const char* next()                                = 0;
  virtual const char* formatNode(const Node *node)          = 0;

  // configuration
  virtual bool  partial() const                             = 0;
  virtual void  set_partial(bool partial)                   = 0;
  virtual float theta() const                               = 0;
  virtual void  set_theta(float theta)                      = 0;
  virtual int   lattice_level() const                       = 0;
  virtual void  set_lattice_level(int level)                = 0;
  virtual bool  all_morphs() const                          = 0;
  virtual void  set_all_morphs(bool all_morphs)             = 0;

#ifndef SWIG
  virtual const char* next(char *ostr , size_t olen)                        = 0;
  virtual const char* parseNBest(size_t N, const char *str,
                                 size_t len, char *ostr, size_t olen)       = 0;
  virtual const char* formatNode(const Node *node, char *ostr, size_t olen) = 0;
#endif

  virtual const DictionaryInfo* dictionary_info() const = 0;

  virtual const char* what() = 0;

  virtual ~Tagger() {}

#ifndef SIWG
  static Tagger* create(int argc, char **argv);
  static Tagger* create(const char *arg);
#endif

  static const char *version();
};

/* factory method */
MECAB_DLL_EXTERN Tagger *createTagger(int argc, char **argv);
MECAB_DLL_EXTERN Tagger *createTagger(const char *arg);
MECAB_DLL_EXTERN const char* getTaggerError();
}

#endif

/* for Open JTalk */
#ifndef MECAB_H
#define MECAB_H

#ifdef __cplusplus
#define MECAB_H_START extern "C" {
#define MECAB_H_END   }
#else
#define MECAB_H_START
#define MECAB_H_END
#endif                          /* __CPLUSPLUS */

MECAB_H_START;

typedef struct _Mecab{
   char **feature;
   int size;
   mecab_t *mecab;
} Mecab;

void Mecab_initialize(Mecab *m);
void Mecab_load(Mecab *m, char *dicdir);
void Mecab_analysis(Mecab *m, char *str);
void Mecab_print(Mecab *m);
int Mecab_get_size(Mecab *m);
char **Mecab_get_feature(Mecab *m);
void Mecab_refresh(Mecab *m);
void Mecab_clear(Mecab *m);

MECAB_H_END;

#endif                          /* !MECAB_H */

#endif
