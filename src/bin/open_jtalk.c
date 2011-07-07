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

#ifndef OPEN_JTALK_C
#define OPEN_JTALK_C

#ifdef __cplusplus
#define OPEN_JTALK_C_START extern "C" {
#define OPEN_JTALK_C_END   }
#else
#define OPEN_JTALK_C_START
#define OPEN_JTALK_C_END
#endif                          /* __CPLUSPLUS */

OPEN_JTALK_C_START;

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

/* Main headers */
#include "mecab.h"
#include "njd.h"
#include "jpcommon.h"
#include "HTS_engine.h"

/* Sub headers */
#include "text2mecab.h"
#include "mecab2njd.h"
#include "njd_set_pronunciation.h"
#include "njd_set_digit.h"
#include "njd_set_accent_phrase.h"
#include "njd_set_accent_type.h"
#include "njd_set_unvoiced_vowel.h"
#include "njd_set_long_vowel.h"
#include "njd2jpcommon.h"

#define MAXBUFLEN 1024

typedef struct _OpenJTalk {
   Mecab mecab;
   NJD njd;
   JPCommon jpcommon;
   HTS_Engine engine;
} OpenJTalk;

void OpenJTalk_initialize(OpenJTalk * open_jtalk, HTS_Boolean use_lpf, int sampling_rate,
                          int fperiod, double alpha, int stage, double beta, int audio_buff_size,
                          double uv_threshold, HTS_Boolean use_log_gain, double gv_weight_mgc,
                          double gv_weight_lf0, double gv_weight_lpf)
{
   Mecab_initialize(&open_jtalk->mecab);
   NJD_initialize(&open_jtalk->njd);
   JPCommon_initialize(&open_jtalk->jpcommon);
   if (use_lpf)
      HTS_Engine_initialize(&open_jtalk->engine, 3);
   else
      HTS_Engine_initialize(&open_jtalk->engine, 2);
   HTS_Engine_set_sampling_rate(&open_jtalk->engine, sampling_rate);
   HTS_Engine_set_fperiod(&open_jtalk->engine, fperiod);
   HTS_Engine_set_alpha(&open_jtalk->engine, alpha);
   HTS_Engine_set_gamma(&open_jtalk->engine, stage);
   HTS_Engine_set_log_gain(&open_jtalk->engine, use_log_gain);
   HTS_Engine_set_beta(&open_jtalk->engine, beta);
   HTS_Engine_set_audio_buff_size(&open_jtalk->engine, audio_buff_size);
   HTS_Engine_set_msd_threshold(&open_jtalk->engine, 1, uv_threshold);
   HTS_Engine_set_gv_weight(&open_jtalk->engine, 0, gv_weight_mgc);
   HTS_Engine_set_gv_weight(&open_jtalk->engine, 1, gv_weight_lf0);
   if (use_lpf)
      HTS_Engine_set_gv_weight(&open_jtalk->engine, 2, gv_weight_lpf);
}

void OpenJTalk_load(OpenJTalk * open_jtalk, char *dn_mecab, char *fn_ms_dur, char *fn_ts_dur,
                    char *fn_ms_mgc, char *fn_ts_mgc, char **fn_ws_mgc, int num_ws_mgc,
                    char *fn_ms_lf0, char *fn_ts_lf0, char **fn_ws_lf0, int num_ws_lf0,
                    char *fn_ms_lpf, char *fn_ts_lpf, char **fn_ws_lpf, int num_ws_lpf,
                    char *fn_ms_gvm, char *fn_ts_gvm, char *fn_ms_gvl, char *fn_ts_gvl,
                    char *fn_ms_gvf, char *fn_ts_gvf, char *fn_gv_switch)
{
   Mecab_load(&open_jtalk->mecab, dn_mecab);
   HTS_Engine_load_duration_from_fn(&open_jtalk->engine, &fn_ms_dur, &fn_ts_dur, 1);
   HTS_Engine_load_parameter_from_fn(&open_jtalk->engine, &fn_ms_mgc, &fn_ts_mgc, fn_ws_mgc, 0,
                                     FALSE, num_ws_mgc, 1);
   HTS_Engine_load_parameter_from_fn(&open_jtalk->engine, &fn_ms_lf0, &fn_ts_lf0, fn_ws_lf0, 1,
                                     TRUE, num_ws_lf0, 1);
   if (HTS_Engine_get_nstream(&open_jtalk->engine) == 3)
      HTS_Engine_load_parameter_from_fn(&open_jtalk->engine, &fn_ms_lpf, &fn_ts_lpf, fn_ws_lpf, 2,
                                        FALSE, num_ws_lpf, 1);
   if (fn_ms_gvm != NULL) {
      if (fn_ts_gvm != NULL)
         HTS_Engine_load_gv_from_fn(&open_jtalk->engine, &fn_ms_gvm, &fn_ts_gvm, 0, 1);
      else
         HTS_Engine_load_gv_from_fn(&open_jtalk->engine, &fn_ms_gvm, NULL, 0, 1);
   }
   if (fn_ms_gvl != NULL) {
      if (fn_ts_gvl != NULL)
         HTS_Engine_load_gv_from_fn(&open_jtalk->engine, &fn_ms_gvl, &fn_ts_gvl, 1, 1);
      else
         HTS_Engine_load_gv_from_fn(&open_jtalk->engine, &fn_ms_gvl, NULL, 1, 1);
   }
   if (HTS_Engine_get_nstream(&open_jtalk->engine) == 3 && fn_ms_gvf != NULL) {
      if (fn_ts_gvf != NULL)
         HTS_Engine_load_gv_from_fn(&open_jtalk->engine, &fn_ms_gvf, &fn_ts_gvf, 2, 1);
      else
         HTS_Engine_load_gv_from_fn(&open_jtalk->engine, &fn_ms_gvf, NULL, 2, 1);
   }
   if (fn_gv_switch != NULL)
      HTS_Engine_load_gv_switch_from_fn(&open_jtalk->engine, fn_gv_switch);
}

void OpenJTalk_synthesis(OpenJTalk * open_jtalk, char *txt, FILE * wavfp, FILE * logfp)
{
   char buff[MAXBUFLEN];

   text2mecab(buff, txt);
   Mecab_analysis(&open_jtalk->mecab, buff);
   mecab2njd(&open_jtalk->njd, Mecab_get_feature(&open_jtalk->mecab),
             Mecab_get_size(&open_jtalk->mecab));
   njd_set_pronunciation(&open_jtalk->njd);
   njd_set_digit(&open_jtalk->njd);
   njd_set_accent_phrase(&open_jtalk->njd);
   njd_set_accent_type(&open_jtalk->njd);
   njd_set_unvoiced_vowel(&open_jtalk->njd);
   njd_set_long_vowel(&open_jtalk->njd);
   njd2jpcommon(&open_jtalk->jpcommon, &open_jtalk->njd);
   JPCommon_make_label(&open_jtalk->jpcommon);
   if (JPCommon_get_label_size(&open_jtalk->jpcommon) > 2) {
      HTS_Engine_load_label_from_string_list(&open_jtalk->engine,
                                             JPCommon_get_label_feature(&open_jtalk->jpcommon),
                                             JPCommon_get_label_size(&open_jtalk->jpcommon));
      HTS_Engine_create_sstream(&open_jtalk->engine);
      HTS_Engine_create_pstream(&open_jtalk->engine);
      HTS_Engine_create_gstream(&open_jtalk->engine);
      if (wavfp != NULL)
         HTS_Engine_save_riff(&open_jtalk->engine, wavfp);
      if (logfp != NULL) {
         fprintf(logfp, "[Text analysis result]\n");
         NJD_fprint(&open_jtalk->njd, logfp);
         fprintf(logfp, "\n[Output label]\n");
         HTS_Engine_save_label(&open_jtalk->engine, logfp);
         fprintf(logfp, "\n");
         HTS_Engine_save_information(&open_jtalk->engine, logfp);
      }
      HTS_Engine_refresh(&open_jtalk->engine);
   }
   JPCommon_refresh(&open_jtalk->jpcommon);
   NJD_refresh(&open_jtalk->njd);
   Mecab_refresh(&open_jtalk->mecab);
}

void OpenJTalk_clear(OpenJTalk * open_jtalk)
{
   Mecab_clear(&open_jtalk->mecab);
   NJD_clear(&open_jtalk->njd);
   JPCommon_clear(&open_jtalk->jpcommon);
   HTS_Engine_clear(&open_jtalk->engine);
}

void Usage()
{
   fprintf(stderr, "\n");
   fprintf(stderr, "The Japanese TTS System \"Open JTalk\"\n");
   fprintf(stderr, "Open JTalk version 1.04 (http://open-jtalk.sourceforge.net/)\n");
   fprintf(stderr, "Copyright (C) 2008-2011  Nagoya Institute of Technology\n");
   fprintf(stderr, "All rights reserved.\n");
   HTS_show_copyright(stderr);
   fprintf(stderr, "\n");
   fprintf(stderr, "Yet Another Part-of-Speech and Morphological Analyzer (Mecab)\n");
   fprintf(stderr, "mecab version 0.98 (http://mecab.sourceforge.net/)\n");
   fprintf(stderr, "Copyright (C) 2001-2008  Taku Kudo\n");
   fprintf(stderr, "              2004-2008  Nippon Telegraph and Telephone Corporation\n");
   fprintf(stderr, "All rights reserved.\n");
   fprintf(stderr, "\n");
   fprintf(stderr, "NAIST Japanese Dictionary\n");
   fprintf(stderr, "mecab-naist-jdic version 0.6.1-20090630 (http://naist-jdic.sourceforge.jp/)\n");
   fprintf(stderr, "Copyright (C) 2009  Nara Institute of Science and Technology\n");
   fprintf(stderr, "All rights reserved.\n");
   fprintf(stderr, "\n");
   fprintf(stderr, "open_jtalk - The Japanese TTS system \"Open JTalk\"\n");
   fprintf(stderr, "\n");
   fprintf(stderr, "  usage:\n");
   fprintf(stderr, "       open_jtalk [ options ] [ infile ] \n");
   fprintf(stderr,
           "  options:                                                                   [  def][ min--max]\n");
   fprintf(stderr,
           "    -x dir         : dictionary directory                                    [  N/A]\n");
   fprintf(stderr,
           "    -td tree       : decision trees file for state duration                  [  N/A]\n");
   fprintf(stderr,
           "    -tm tree       : decision trees file for spectrum                        [  N/A]\n");
   fprintf(stderr,
           "    -tf tree       : decision trees file for Log F0                          [  N/A]\n");
   fprintf(stderr,
           "    -tl tree       : decision trees file for low-pass filter                 [  N/A]\n");
   fprintf(stderr,
           "    -md pdf        : model file for state duration                           [  N/A]\n");
   fprintf(stderr,
           "    -mm pdf        : model file for spectrum                                 [  N/A]\n");
   fprintf(stderr,
           "    -mf pdf        : model file for Log F0                                   [  N/A]\n");
   fprintf(stderr,
           "    -ml pdf        : model file for low-pass filter                          [  N/A]\n");
   fprintf(stderr,
           "    -dm win        : window files for calculation delta of spectrum          [  N/A]\n");
   fprintf(stderr,
           "    -df win        : window files for calculation delta of Log F0            [  N/A]\n");
   fprintf(stderr,
           "    -dl win        : window files for calculation delta of low-pass filter   [  N/A]\n");
   fprintf(stderr,
           "    -ow s          : filename of output wav audio (generated speech)         [  N/A]\n");
   fprintf(stderr,
           "    -ot s          : filename of output trace information                    [  N/A]\n");
   fprintf(stderr,
           "    -s  i          : sampling frequency                                      [16000][   1--48000]\n");
   fprintf(stderr,
           "    -p  i          : frame period (point)                                    [   80][   1--]\n");
   fprintf(stderr,
           "    -a  f          : all-pass constant                                       [ 0.42][ 0.0--1.0]\n");
   fprintf(stderr,
           "    -g  i          : gamma = -1 / i (if i=0 then gamma=0)                    [    0][   0-- ]\n");
   fprintf(stderr,
           "    -b  f          : postfiltering coefficient                               [  0.0][-0.8--0.8]\n");
   fprintf(stderr,
           "    -l             : regard input as log gain and output linear one (LSP)    [  N/A]\n");
   fprintf(stderr,
           "    -u  f          : voiced/unvoiced threshold                               [  0.5][ 0.0--1.0]\n");
   fprintf(stderr,
           "    -em tree       : decision tree file for GV of spectrum                   [  N/A]\n");
   fprintf(stderr,
           "    -ef tree       : decision tree file for GV of Log F0                     [  N/A]\n");
   fprintf(stderr,
           "    -el tree       : decision tree file for GV of low-pass filter            [  N/A]\n");
   fprintf(stderr,
           "    -cm pdf        : filename of GV for spectrum                             [  N/A]\n");
   fprintf(stderr,
           "    -cf pdf        : filename of GV for Log F0                               [  N/A]\n");
   fprintf(stderr,
           "    -cl pdf        : filename of GV for low-pass filter                      [  N/A]\n");
   fprintf(stderr,
           "    -jm f          : weight of GV for spectrum                               [  1.0][ 0.0--2.0]\n");
   fprintf(stderr,
           "    -jf f          : weight of GV for Log F0                                 [  1.0][ 0.0--2.0]\n");
   fprintf(stderr,
           "    -jl f          : weight of GV for low-pass filter                        [  1.0][ 0.0--2.0]\n");
   fprintf(stderr,
           "    -k  tree       : use GV switch                                           [  N/A]\n");
   fprintf(stderr,
           "    -z  i          : audio buffer size                                       [ 1600][   0--48000]\n");
   fprintf(stderr, "  infile:\n");
   fprintf(stderr,
           "    text file                                                                [stdin]\n");
   fprintf(stderr, "  note:\n");
   fprintf(stderr, "    option '-d' may be repeated to use multiple delta parameters.\n");
   fprintf(stderr, "    generated spectrum, log F0, and low-pass filter coefficient\n");
   fprintf(stderr, "    sequences are saved in natural endian, binary (float) format.\n");
   fprintf(stderr, "\n");

   exit(0);
}

/* Getfp: wrapper for fopen */
FILE *Getfp(const char *name, const char *opt)
{
   FILE *fp = fopen(name, opt);

   if (fp == NULL) {
      fprintf(stderr, "ERROR: Getfp() in open_jtalk.c: Cannot open %s.\n", name);
      exit(1);
   }

   return (fp);
}

int main(int argc, char **argv)
{
   FILE *txtfp = stdin;
   char *txtfn = NULL;
   FILE *wavfp = NULL;
   FILE *logfp = NULL;

   /* text */
   char buff[MAXBUFLEN];

   /* engine */
   OpenJTalk open_jtalk;

   /* directory name of dictionary */
   char *dn_mecab = NULL;

   /* file names of models */
   char *fn_ms_dur = NULL;
   char *fn_ms_mgc = NULL;
   char *fn_ms_lf0 = NULL;
   char *fn_ms_lpf = NULL;

   /* file names of trees */
   char *fn_ts_dur = NULL;
   char *fn_ts_mgc = NULL;
   char *fn_ts_lf0 = NULL;
   char *fn_ts_lpf = NULL;

   /* file names of windows */
   char **fn_ws_mgc;
   char **fn_ws_lf0;
   char **fn_ws_lpf;
   int num_ws_mgc = 0, num_ws_lf0 = 0, num_ws_lpf = 0;

   /* file names of global variance */
   char *fn_ms_gvm = NULL;
   char *fn_ms_gvl = NULL;
   char *fn_ms_gvf = NULL;

   /* file names of global variance trees */
   char *fn_ts_gvm = NULL;
   char *fn_ts_gvl = NULL;
   char *fn_ts_gvf = NULL;

   /* file names of global variance switch */
   char *fn_gv_switch = NULL;

   /* global parameter */
   int sampling_rate = 16000;
   int fperiod = 80;
   double alpha = 0.42;
   int stage = 0;               /* gamma = -1.0/stage */
   double beta = 0.0;
   int audio_buff_size = 1600;
   double uv_threshold = 0.5;
   double gv_weight_mgc = 1.0;
   double gv_weight_lf0 = 1.0;
   double gv_weight_lpf = 1.0;
   HTS_Boolean use_log_gain = FALSE;
   HTS_Boolean use_lpf = FALSE;

   /* parse command line */
   if (argc == 1)
      Usage();

   /* delta window handler for mel-cepstrum */
   fn_ws_mgc = (char **) calloc(argc, sizeof(char *));
   /* delta window handler for log f0 */
   fn_ws_lf0 = (char **) calloc(argc, sizeof(char *));
   /* delta window handler for low-pass filter */
   fn_ws_lpf = (char **) calloc(argc, sizeof(char *));

   /* read command */
   while (--argc) {
      if (**++argv == '-') {
         switch (*(*argv + 1)) {
         case 'x':
            dn_mecab = *(++argv);
            --argc;
            break;
         case 't':
            switch (*(*argv + 2)) {
            case 'd':
               fn_ts_dur = *(++argv);
               break;
            case 'm':
               fn_ts_mgc = *(++argv);
               break;
            case 'f':
            case 'p':
               fn_ts_lf0 = *(++argv);
               break;
            case 'l':
               fn_ts_lpf = *(++argv);
               break;
            default:
               fprintf(stderr,
                       "ERROR: main() in open_jtalk.c: Invalid option '-t%c'.\n", *(*argv + 2));
               exit(1);
            }
            --argc;
            break;
         case 'm':
            switch (*(*argv + 2)) {
            case 'd':
               fn_ms_dur = *(++argv);
               break;
            case 'm':
               fn_ms_mgc = *(++argv);
               break;
            case 'f':
            case 'p':
               fn_ms_lf0 = *(++argv);
               break;
            case 'l':
               fn_ms_lpf = *(++argv);
               break;
            default:
               fprintf(stderr,
                       "ERROR: main() in open_jtalk.c: Invalid option '-m%c'.\n", *(*argv + 2));
               exit(1);
            }
            --argc;
            break;
         case 'd':
            switch (*(*argv + 2)) {
            case 'm':
               fn_ws_mgc[num_ws_mgc++] = *(++argv);
               break;
            case 'f':
            case 'p':
               fn_ws_lf0[num_ws_lf0++] = *(++argv);
               break;
            case 'l':
               fn_ws_lpf[num_ws_lpf++] = *(++argv);
               break;
            default:
               fprintf(stderr,
                       "ERROR: main() in open_jtalk.c: Invalid option '-d%c'.\n", *(*argv + 2));
               exit(1);
            }
            --argc;
            break;
         case 'o':
            switch (*(*argv + 2)) {
            case 'w':
               wavfp = Getfp(*(++argv), "wb");
               break;
            case 't':
               logfp = Getfp(*(++argv), "w");
               break;
            default:
               fprintf(stderr, "ERROR: main() in open_jtalk.c: Invalid option '-o%c'.\n",
                       *(*argv + 2));
               exit(1);
            }
            --argc;
            break;
         case 'h':
            Usage();
            break;
         case 's':
            sampling_rate = atoi(*++argv);
            --argc;
            break;
         case 'p':
            fperiod = atoi(*++argv);
            --argc;
            break;
         case 'a':
            alpha = atof(*++argv);
            --argc;
            break;
         case 'g':
            stage = atoi(*++argv);
            --argc;
            break;
         case 'l':
            use_log_gain = TRUE;
            break;
         case 'b':
            beta = atof(*++argv);
            --argc;
            break;
         case 'u':
            uv_threshold = atof(*++argv);
            --argc;
            break;
         case 'e':
            switch (*(*argv + 2)) {
            case 'm':
               fn_ts_gvm = *(++argv);
               break;
            case 'f':
            case 'p':
               fn_ts_gvl = *(++argv);
               break;
            case 'l':
               fn_ts_gvf = *(++argv);
               break;
            default:
               fprintf(stderr,
                       "ERROR: main() in open_jtalk.c: Invalid option '-e%c'.\n", *(*argv + 2));
               exit(1);
            }
            --argc;
            break;
         case 'c':
            switch (*(*argv + 2)) {
            case 'm':
               fn_ms_gvm = *(++argv);
               break;
            case 'f':
            case 'p':
               fn_ms_gvl = *(++argv);
               break;
            case 'l':
               fn_ms_gvf = *(++argv);
               break;
            default:
               fprintf(stderr,
                       "ERROR: main() in open_jtalk.c: Invalid option '-c%c'.\n", *(*argv + 2));
               exit(1);
            }
            --argc;
            break;
         case 'j':
            switch (*(*argv + 2)) {
            case 'm':
               gv_weight_mgc = atof(*(++argv));
               break;
            case 'f':
            case 'p':
               gv_weight_lf0 = atof(*(++argv));
               break;
            case 'l':
               gv_weight_lpf = atof(*(++argv));
               break;
            default:
               fprintf(stderr,
                       "ERROR: main() in open_jtalk.c: Invalid option '-j%c'.\n", *(*argv + 2));
               exit(1);
            }
            --argc;
            break;
         case 'k':
            fn_gv_switch = *++argv;
            --argc;
            break;
         case 'z':
            audio_buff_size = atoi(*++argv);
            --argc;
            break;
         default:
            fprintf(stderr, "ERROR: main() in open_jtalk.c: Invalid option '-%c'.\n", *(*argv + 1));
            exit(1);
         }
      } else {
         txtfn = *argv;
         txtfp = Getfp(txtfn, "rt");
      }
   }
   /* dictionary directory check */
   if (dn_mecab == NULL) {
      fprintf(stderr, "ERROR: main() in open_jtalk.c: No dictionary directory.\n");
      exit(1);
   }
   /* number of models,trees check */
   if (fn_ms_dur == NULL || fn_ms_mgc == NULL || fn_ms_lf0 == NULL ||
       fn_ts_dur == NULL || fn_ts_mgc == NULL || fn_ts_lf0 == NULL ||
       num_ws_mgc <= 0 || num_ws_lf0 <= 0) {
      fprintf(stderr,
              "ERROR: main() in open_jtalk.c: Specify models (trees) for each parameter.\n");
      exit(1);
   }
   if (fn_ms_lpf != NULL && fn_ts_lpf != NULL && num_ws_lpf > 0)
      use_lpf = TRUE;

   /* initialize and load */
   OpenJTalk_initialize(&open_jtalk, use_lpf, sampling_rate, fperiod, alpha, stage, beta,
                        audio_buff_size, uv_threshold, use_log_gain, gv_weight_mgc,
                        gv_weight_lf0, gv_weight_lpf);
   OpenJTalk_load(&open_jtalk, dn_mecab, fn_ms_dur, fn_ts_dur, fn_ms_mgc, fn_ts_mgc,
                  fn_ws_mgc, num_ws_mgc, fn_ms_lf0, fn_ts_lf0, fn_ws_lf0, num_ws_lf0,
                  fn_ms_lpf, fn_ts_lpf, fn_ws_lpf, num_ws_lpf, fn_ms_gvm, fn_ts_gvm,
                  fn_ms_gvl, fn_ts_gvl, fn_ms_gvf, fn_ts_gvf, fn_gv_switch);

   /* synthesis */
   fgets(buff, MAXBUFLEN - 1, txtfp);
   OpenJTalk_synthesis(&open_jtalk, buff, wavfp, logfp);

   /* free */
   OpenJTalk_clear(&open_jtalk);
   free(fn_ws_mgc);
   free(fn_ws_lf0);
   free(fn_ws_lpf);
   if (txtfn != NULL)
      fclose(txtfp);
   if (wavfp != NULL)
      fclose(wavfp);
   if (logfp != NULL)
      fclose(logfp);

   return 0;
}

OPEN_JTALK_C_END;
#endif                          /* !OPEN_JTALK_C */
