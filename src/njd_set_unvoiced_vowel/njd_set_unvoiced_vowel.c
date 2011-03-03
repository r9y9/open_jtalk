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

#ifndef NJD_SET_UNVOICED_VOWEL_C
#define NJD_SET_UNVOICED_VOWEL_C

#ifdef __cplusplus
#define NJD_SET_UNVOICED_VOWEL_C_START extern "C" {
#define NJD_SET_UNVOICED_VOWEL_C_END   }
#else
#define NJD_SET_UNVOICED_VOWEL_C_START
#define NJD_SET_UNVOICED_VOWEL_C_END
#endif                          /* __CPLUSPLUS */

NJD_SET_UNVOICED_VOWEL_C_START;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "njd.h"
#include "njd_set_unvoiced_vowel.h"

#if defined(CHARSET_EUC_JP)
#include "njd_set_unvoiced_vowel_rule_euc_jp.h"
#elif defined(CHARSET_SHIFT_JIS)
#include "njd_set_unvoiced_vowel_rule_shift_jis.h"
#elif defined(CHARSET_UTF_8)
#include "njd_set_unvoiced_vowel_rule_utf_8.h"
#else
#error CHARSET is not specified
#endif

#define MAXBUFLEN 1024

static int strtopcmp(char *str, const char *pattern)
{
   int i;

   for (i = 0;; i++) {
      if (pattern[i] == '\0')
         return i;
      if (str[i] == '\0')
         return -1;
      if (str[i] != pattern[i])
         return -1;
   }
}

static int check_next_mora(char *str)
{
   int i;

   for (i = 0; njd_set_unvoiced_vowel_next_mora_list[i] != NULL; i++) {
      if (strtopcmp(str, njd_set_unvoiced_vowel_next_mora_list[i]) > 0)
         return 1;
   }
   return 0;
}

static int strcat_unvoiced(char *buff, const char *str, int *last_unvoiced_flag, int *mora_in_word,
                           int *mora_in_accent_phrase)
{
   strcat(buff, str);
   strcat(buff, NJD_SET_UNVOICED_VOWEL_QUOTATION);
   *last_unvoiced_flag = 1;
   *mora_in_word += 1;
   *mora_in_accent_phrase += 1;
   return strlen(str);
}

static int strcat_skip(char *buff, char *str, int *last_unvoiced_flag, int *mora_in_word,
                       int *mora_in_accent_phrase)
{
   int i, byte;

   for (i = 0; njd_set_unvoiced_vowel_mora_list[i] != NULL; i++) {
      byte = strtopcmp(str, njd_set_unvoiced_vowel_mora_list[i]);
      if (byte > 0) {
         strncat(buff, njd_set_unvoiced_vowel_mora_list[i], byte);
         *last_unvoiced_flag = 0;
         *mora_in_word += 1;
         *mora_in_accent_phrase += 1;
         return strlen(njd_set_unvoiced_vowel_mora_list[i]);
      }
   }
   if (strtopcmp(str, NJD_SET_UNVOICED_VOWEL_TOUTEN) > 0) {
      strcat(buff, NJD_SET_UNVOICED_VOWEL_TOUTEN);
      *last_unvoiced_flag = 0;
      return strlen(NJD_SET_UNVOICED_VOWEL_TOUTEN);
   }
   if (strtopcmp(str, NJD_SET_UNVOICED_VOWEL_QUESTION) > 0) {
      strcat(buff, NJD_SET_UNVOICED_VOWEL_QUESTION);
      *last_unvoiced_flag = 0;
      return strlen(NJD_SET_UNVOICED_VOWEL_QUESTION);
   }
   if (strtopcmp(str, NJD_SET_UNVOICED_VOWEL_QUOTATION) > 0) {
      strcat(buff, NJD_SET_UNVOICED_VOWEL_QUOTATION);
      *last_unvoiced_flag = 1;
      return strlen(NJD_SET_UNVOICED_VOWEL_QUOTATION);
   }
   fprintf(stderr, "WARNING: strcat_voiced() in njd_set_unvoiced_vowel.c: Wrong pron.");
   return 1;
}

static void set_unvoiced_vowel(NJDNode * node, int *acc_in_accent_phrase,
                               int *mora_in_accent_phrase, int *last_unvoiced_flag)
{
   int i, j;
   int len, mora_in_word;
   char buff[MAXBUFLEN];
   char *str;
   const char *tmp;
   int find;

   /* initialize */
   str = NJDNode_get_pron(node);
   buff[0] = '\0';

   /* Rule 1 */
   if (strcmp(NJDNode_get_pos(node), NJD_SET_UNVOICED_VOWEL_JODOUSHI) == 0) {
      for (i = 0; njd_set_unvoiced_vowel_jodoushi_table[i] != NULL; i += 3) {
         if (strcmp(str, njd_set_unvoiced_vowel_jodoushi_table[i]) == 0) {
            NJDNode_set_pron(node, (char *) njd_set_unvoiced_vowel_jodoushi_table[i + 1]);
            *mora_in_accent_phrase += atoi(njd_set_unvoiced_vowel_jodoushi_table[i + 2]);
            *last_unvoiced_flag = 1;
            return;
         }
      }
   }

   len = strlen(str);
   mora_in_word = 0;
   for (i = 0; i < len;) {
      if (*last_unvoiced_flag == 1) {
         /* Rule 2 */
         i += strcat_skip(buff, &str[i], last_unvoiced_flag, &mora_in_word, mora_in_accent_phrase);
      } else if (*acc_in_accent_phrase == *mora_in_accent_phrase + 1) {
         /* Rule 3 */
         i += strcat_skip(buff, &str[i], last_unvoiced_flag, &mora_in_word, mora_in_accent_phrase);
      } else {
         /* Rule 4 */
         tmp = NULL;
         for (j = 0; njd_set_unvoiced_vowel_mora_list[j] != NULL; j++) {
            if (strtopcmp(&str[i], njd_set_unvoiced_vowel_mora_list[j]) > 0) {
               tmp = njd_set_unvoiced_vowel_mora_list[j];
               break;
            }
         }
         if (tmp == NULL) {
            /* unknown mora */
            i += strcat_skip(buff, &str[i], last_unvoiced_flag, &mora_in_word,
                             mora_in_accent_phrase);
         } else {
            find = 0;
            for (j = 0; njd_set_unvoiced_vowel_candidate_list[j] != NULL; j++) {
               if (strcmp(tmp, njd_set_unvoiced_vowel_candidate_list[j]) == 0) {
                  if (check_next_mora(&str[i + strlen(tmp)]) == 1) {
                     find = 1;
                  } else if (NJDNode_get_mora_size(node) == mora_in_word + 1 && node->next != NULL
                             && check_next_mora(NJDNode_get_pron(node->next)) == 1) {
                     find = 1;
                  } else {
                     find = 0;
                  }
                  break;
               }
            }
            if (find == 1)      /* unvoiced */
               i += strcat_unvoiced(buff, njd_set_unvoiced_vowel_candidate_list[j],
                                    last_unvoiced_flag, &mora_in_word, mora_in_accent_phrase);
            else                /* skip */
               i += strcat_skip(buff, &str[i], last_unvoiced_flag, &mora_in_word,
                                mora_in_accent_phrase);
         }
      }
   }
   NJDNode_set_pron(node, buff);
}

void njd_set_unvoiced_vowel(NJD * njd)
{
   int acc_in_accent_phrase = 0;
   int mora_in_accent_phrase = 0;
   int last_unvoiced_flag = 0;
   NJDNode *node;

   for (node = njd->head; node != NULL; node = node->next) {
      if (NJDNode_get_chain_flag(node) <= 0) {
         acc_in_accent_phrase = NJDNode_get_acc(node);
         mora_in_accent_phrase = 0;
      }
      set_unvoiced_vowel(node, &acc_in_accent_phrase, &mora_in_accent_phrase, &last_unvoiced_flag);
   }
}

NJD_SET_UNVOICED_VOWEL_C_END;

#endif                          /* !NJD_SET_UNVOICED_VOWEL_C */
