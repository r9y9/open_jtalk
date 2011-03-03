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

#ifndef NJD_NODE_C
#define NJD_NODE_C

#ifdef __cplusplus
#define NJD_NODE_C_START extern "C" {
#define NJD_NODE_C_END   }
#else
#define NJD_NODE_C_START
#define NJD_NODE_C_END
#endif                          /* __CPLUSPLUS */

NJD_NODE_C_START;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "njd.h"

#if defined(CHARSET_EUC_JP)
#include "njd_rule_euc_jp.h"
#elif defined(CHARSET_SHIFT_JIS)
#include "njd_rule_shift_jis.h"
#elif defined(CHARSET_UTF_8)
#include "njd_rule_utf_8.h"
#else
#error CHARSET is not specified
#endif

#define MAXBUFLEN 1024

/* If head of 'str' is equal to 'pattern', return length of 'pattern'.
   If head of 'str' is not equal to 'pattern', return '-1'. */
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

/* Copy 'n' mora from 'str' to 'buff' and return length of 'buff'.
   If 'str' is not appropriate mora, return '0'. */
static int morancpy(char *buff, char *str, int n)
{
   int i, j;
   int s = 0, e = 0;

   for (i = 0; i < n; i++) {
      for (j = 0; njd_mora_list[j] != NULL; j++) {
         e = strtopcmp(&str[s], njd_mora_list[j]);
         if (e != -1)
            break;
      }
      if (e != -1)
         s += e;
      else {
         buff[0] = '\0';
         return 0;
      }
   }
   strncpy(buff, str, s);
   buff[s] = '\0';
   return s;
}

static void get_token_from_string(char *str, int *index, char *buff, const char d)
{
   char c;
   int i = 0;

   c = str[(*index)];
   if (c != '\0') {
      while (c != d && c != '\0') {
         buff[i++] = c;
         c = str[++(*index)];
      }
      if (c == d)
         (*index)++;
   }
   buff[i] = '\0';
}

void NJDNode_initialize(NJDNode * node)
{
   node->string = NULL;
   node->pos = NULL;
   node->pos_group1 = NULL;
   node->pos_group2 = NULL;
   node->pos_group3 = NULL;
   node->ctype = NULL;
   node->cform = NULL;
   node->orig = NULL;
   node->read = NULL;
   node->pron = NULL;
   node->acc = 0;
   node->mora_size = 0;
   node->chain_rule = NULL;
   node->chain_flag = -1;
   node->prev = NULL;
   node->next = NULL;
}

void NJDNode_set_string(NJDNode * node, char *str)
{
   if (node->string != NULL)
      free(node->string);
   if (str == NULL || strlen(str) == 0)
      node->string = NULL;
   else
      node->string = strdup(str);
}

void NJDNode_set_pos(NJDNode * node, char *str)
{
   if (node->pos != NULL)
      free(node->pos);
   if (str == NULL || strlen(str) == 0)
      node->pos = NULL;
   else
      node->pos = strdup(str);
}

void NJDNode_set_pos_group1(NJDNode * node, char *str)
{
   if (node->pos_group1 != NULL)
      free(node->pos_group1);
   if (str == NULL || strlen(str) == 0)
      node->pos_group1 = NULL;
   else
      node->pos_group1 = strdup(str);
}

void NJDNode_set_pos_group2(NJDNode * node, char *str)
{
   if (node->pos_group2 != NULL)
      free(node->pos_group2);
   if (str == NULL || strlen(str) == 0)
      node->pos_group2 = NULL;
   else
      node->pos_group2 = strdup(str);
}

void NJDNode_set_pos_group3(NJDNode * node, char *str)
{
   if (node->pos_group3 != NULL)
      free(node->pos_group3);
   if (str == NULL || strlen(str) == 0)
      node->pos_group3 = NULL;
   else
      node->pos_group3 = strdup(str);
}

void NJDNode_set_ctype(NJDNode * node, char *str)
{
   if (node->ctype != NULL)
      free(node->ctype);
   if (str == NULL || strlen(str) == 0)
      node->ctype = NULL;
   else
      node->ctype = strdup(str);
}

void NJDNode_set_cform(NJDNode * node, char *str)
{
   if (node->cform != NULL)
      free(node->cform);
   if (str == NULL || strlen(str) == 0)
      node->cform = NULL;
   else
      node->cform = strdup(str);
}

void NJDNode_set_orig(NJDNode * node, char *str)
{
   if (node->orig != NULL)
      free(node->orig);
   if (str == NULL || strlen(str) == 0)
      node->orig = NULL;
   else
      node->orig = strdup(str);
}

void NJDNode_set_read(NJDNode * node, char *str)
{
   if (node->read != NULL)
      free(node->read);
   if (str == NULL || strlen(str) == 0)
      node->read = NULL;
   else
      node->read = strdup(str);
}

void NJDNode_set_pron(NJDNode * node, char *str)
{
   if (node->pron != NULL)
      free(node->pron);
   if (str == NULL || strlen(str) == 0)
      node->pron = NULL;
   else
      node->pron = strdup(str);
}

void NJDNode_set_acc(NJDNode * node, int acc)
{
   node->acc = acc;
   if (node->acc < 0) {
      fprintf(stderr, "WARNING: NJDNode_set_acc() in njd_node.c: Accent must be positive value.\n");
      node->acc = 0;
   }
}

void NJDNode_set_mora_size(NJDNode * node, int size)
{
   node->mora_size = size;
   if (node->mora_size < 0) {
      fprintf(stderr,
              "WARNING: NJDNode_set_mora_size() in njd_node.c: Mora size must be positive value.\n");
      node->mora_size = 0;
   }
}

void NJDNode_set_chain_rule(NJDNode * node, char *str)
{
   if (node->chain_rule != NULL)
      free(node->chain_rule);
   if (str == NULL || strlen(str) == 0)
      node->chain_rule = NULL;
   else
      node->chain_rule = strdup(str);
}

void NJDNode_set_chain_flag(NJDNode * node, int flag)
{
   node->chain_flag = flag;
}

void NJDNode_add_read(NJDNode * node, char *str)
{
   char *c;

   if (str != NULL) {
      if (node->read == NULL) {
         node->read = strdup(str);
      } else {
         c = (char *) calloc(strlen(node->read) + strlen(str) + 1, sizeof(char));
         strcpy(c, node->read);
         strcat(c, str);
         free(node->read);
         node->read = c;
      }
   }
}

void NJDNode_add_pron(NJDNode * node, char *str)
{
   char *c;

   if (str != NULL) {
      if (node->pron == NULL) {
         node->pron = strdup(str);
      } else {
         c = (char *) calloc(strlen(node->pron) + strlen(str) + 1, sizeof(char));
         strcpy(c, node->pron);
         strcat(c, str);
         free(node->pron);
         node->pron = c;
      }
   }
}

void NJDNode_add_acc(NJDNode * node, int acc)
{
   node->acc += acc;
   if (node->acc < 0) {
      fprintf(stderr, "WARNING: NJDNode_add_acc() in njd_node.c: Accent must be positive value.\n");
      node->acc = 0;
   }
}

void NJDNode_add_mora_size(NJDNode * node, int size)
{
   node->mora_size += size;
   if (node->mora_size < 0) {
      fprintf(stderr,
              "WARNING: NJDNode_add_mora_size() in njd_node.c: Mora size must be positive value.\n");
      node->mora_size = 0;
   }
}

char *NJDNode_get_string(NJDNode * node)
{
   return node->string;
}

char *NJDNode_get_pos(NJDNode * node)
{
   return node->pos;
}

char *NJDNode_get_pos_group1(NJDNode * node)
{
   return node->pos_group1;
}

char *NJDNode_get_pos_group2(NJDNode * node)
{
   return node->pos_group2;
}

char *NJDNode_get_pos_group3(NJDNode * node)
{
   return node->pos_group3;
}

char *NJDNode_get_ctype(NJDNode * node)
{
   return node->ctype;
}

char *NJDNode_get_cform(NJDNode * node)
{
   return node->cform;
}

char *NJDNode_get_orig(NJDNode * node)
{
   return node->orig;
}

char *NJDNode_get_read(NJDNode * node)
{
   return node->read;
}

char *NJDNode_get_pron(NJDNode * node)
{
   return node->pron;
}

int NJDNode_get_acc(NJDNode * node)
{
   return node->acc;
}

int NJDNode_get_mora_size(NJDNode * node)
{
   return node->mora_size;
}

char *NJDNode_get_chain_rule(NJDNode * node)
{
   return node->chain_rule;
}

int NJDNode_get_chain_flag(NJDNode * node)
{
   return node->chain_flag;
}

void NJDNode_load(NJDNode * node, char *str)
{
   int i, j;
   int index = 0;
   char pron[1024];
   char buff[1024];
   char acc[1024];
   int count;
   int *alist;
   int *mlist;
   NJDNode *prev = NULL;

   /* load */
   get_token_from_string(str, &index, buff, ',');
   NJDNode_set_string(node, buff);
   get_token_from_string(str, &index, buff, ',');
   NJDNode_set_pos(node, buff);
   get_token_from_string(str, &index, buff, ',');
   NJDNode_set_pos_group1(node, buff);
   get_token_from_string(str, &index, buff, ',');
   NJDNode_set_pos_group2(node, buff);
   get_token_from_string(str, &index, buff, ',');
   NJDNode_set_pos_group3(node, buff);
   get_token_from_string(str, &index, buff, ',');
   NJDNode_set_ctype(node, buff);
   get_token_from_string(str, &index, buff, ',');
   NJDNode_set_cform(node, buff);
   get_token_from_string(str, &index, buff, ',');
   if (strcmp(buff, "") == 0)
      NJDNode_set_orig(node, NULL);
   else
      NJDNode_set_orig(node, buff);
   get_token_from_string(str, &index, buff, ',');
   if (strcmp(buff, "") == 0)
      NJDNode_set_read(node, NULL);
   else
      NJDNode_set_read(node, buff);
   get_token_from_string(str, &index, buff, ',');
   strcpy(pron, buff);
   get_token_from_string(str, &index, buff, ',');
   strcpy(acc, buff);
   get_token_from_string(str, &index, buff, ',');
   if (strcmp(buff, "") == 0)
      NJDNode_set_chain_rule(node, "-1");
   else
      NJDNode_set_chain_rule(node, buff);

   /* for symbol */
   if (strstr(acc, "*") != NULL) {
      NJDNode_set_acc(node, 0);
      NJDNode_set_mora_size(node, 0);
      if (strcmp(pron, "") == 0)
         NJDNode_set_pron(node, NULL);
      else
         NJDNode_set_pron(node, pron);
      return;
   }

   /* count chained node */
   for (i = 0, count = 0; acc[i] != '\0'; i++)
      if (acc[i] == '/')
         count++;

   /* get accent types and mora sizes */
   alist = (int *) calloc(count, sizeof(int));
   mlist = (int *) calloc(count, sizeof(int));
   for (i = 0, index = 0; i < count; i++) {
      get_token_from_string(acc, &index, buff, '/');
      alist[i] = 0;
      if (buff[0] == '\0') {
         fprintf(stderr, "WARNING: NJDNode_load() in njd_node.c: Accent is empty.\n");
      } else {
         j = atoi(buff);
         if (j >= 0)
            alist[i] = j;
      }
      get_token_from_string(acc, &index, buff, ':');
      mlist[i] = 0;
      if (buff[0] == '\0') {
         fprintf(stderr, "WARNING: NJDNode_load() in njd_node.c: Mora size is empty.\n");
      } else {
         j = atoi(buff);
         if (j >= 0)
            mlist[i] = j;
      }
   }

   /* set nodes to NJDNode */
   if (count == 1) {
      NJDNode_set_acc(node, alist[0]);
      NJDNode_set_mora_size(node, mlist[0]);
      if (strcmp(pron, "") == 0)
         NJDNode_set_pron(node, NULL);
      else
         NJDNode_set_pron(node, pron);
   } else {
      for (i = 0, index = 0; i < count; i++) {
         if (i > 0) {
            node = (NJDNode *) calloc(1, sizeof(NJDNode));
            NJDNode_initialize(node);
            NJDNode_copy(node, prev);
            NJDNode_set_string(node, "");
            NJDNode_set_chain_flag(node, 0);
            node->prev = prev;
            prev->next = node;
         }
         j = morancpy(buff, &pron[index], mlist[i]);
         if (j > 0) {
            index += j;
            NJDNode_set_acc(node, alist[i]);
            NJDNode_set_mora_size(node, mlist[i]);
            NJDNode_set_pron(node, buff);
         } else {
            fprintf(stderr,
                    "WARNING: NJDNode_load() in njd_node.c: %s is not appropriate mora list.\n",
                    &pron[index]);
            NJDNode_set_acc(node, 0);
            NJDNode_set_mora_size(node, 0);
            NJDNode_set_pron(node, NULL);
            break;
         }
         prev = node;
      }
   }
   free(mlist);
   free(alist);
}

NJDNode *NJDNode_insert(NJDNode * prev, NJDNode * next, NJDNode * node)
{
   NJDNode *tail;

   if (prev == NULL || next == NULL) {
      fprintf(stderr, "ERROR: NJDNode_insert() in njd_node.c: NJDNodes are not specified.\n");
      exit(1);
   }
   for (tail = node; tail->next != NULL; tail = tail->next);
   prev->next = node;
   node->prev = prev;
   next->prev = tail;
   tail->next = next;

   return tail;
}

void NJDNode_copy(NJDNode * node1, NJDNode * node2)
{
   NJDNode_set_string(node1, node2->string);
   NJDNode_set_pos(node1, node2->pos);
   NJDNode_set_pos_group1(node1, node2->pos_group1);
   NJDNode_set_pos_group2(node1, node2->pos_group2);
   NJDNode_set_pos_group3(node1, node2->pos_group3);
   NJDNode_set_ctype(node1, node2->ctype);
   NJDNode_set_cform(node1, node2->cform);
   NJDNode_set_orig(node1, node2->orig);
   NJDNode_set_read(node1, node2->read);
   NJDNode_set_pron(node1, node2->pron);
   NJDNode_set_acc(node1, node2->acc);
   NJDNode_set_mora_size(node1, node2->mora_size);
   NJDNode_set_chain_rule(node1, node2->chain_rule);
   NJDNode_set_chain_flag(node1, node2->chain_flag);
}

void NJDNode_print(NJDNode * node)
{
   NJDNode_fprint(node, stdout);
}

void NJDNode_fprint(NJDNode * node, FILE * fp)
{
   fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%d/%d,%s,%d\n",
           node->string == NULL ? "" : node->string, node->pos == NULL ? "" : node->pos,
           node->pos_group1 == NULL ? "" : node->pos_group1,
           node->pos_group2 == NULL ? "" : node->pos_group2,
           node->pos_group3 == NULL ? "" : node->pos_group3, node->ctype == NULL ? "" : node->ctype,
           node->cform == NULL ? "" : node->cform, node->orig == NULL ? "" : node->orig,
           node->read == NULL ? "" : node->read, node->pron == NULL ? "" : node->pron, node->acc,
           node->mora_size, node->chain_rule == NULL ? "" : node->chain_rule, node->chain_flag);
}

void NJDNode_sprint(NJDNode * node, char *buff, const char *split_code)
{
   sprintf(buff, "%s%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%d/%d,%s,%d%s", buff,
           node->string == NULL ? "" : node->string, node->pos == NULL ? "" : node->pos,
           node->pos_group1 == NULL ? "" : node->pos_group1,
           node->pos_group2 == NULL ? "" : node->pos_group2,
           node->pos_group3 == NULL ? "" : node->pos_group3, node->ctype == NULL ? "" : node->ctype,
           node->cform == NULL ? "" : node->cform, node->orig == NULL ? "" : node->orig,
           node->read == NULL ? "" : node->read, node->pron == NULL ? "" : node->pron, node->acc,
           node->mora_size, node->chain_rule == NULL ? "" : node->chain_rule, node->chain_flag,
           split_code);
}

void NJDNode_clear(NJDNode * node)
{
   if (node->string != NULL) {
      free(node->string);
      node->string = NULL;
   }
   if (node->pos != NULL) {
      free(node->pos);
      node->pos = NULL;
   }
   if (node->pos_group1 != NULL) {
      free(node->pos_group1);
      node->pos_group1 = NULL;
   }
   if (node->pos_group2 != NULL) {
      free(node->pos_group2);
      node->pos_group2 = NULL;
   }
   if (node->pos_group3 != NULL) {
      free(node->pos_group3);
      node->pos_group3 = NULL;
   }
   if (node->ctype != NULL) {
      free(node->ctype);
      node->ctype = NULL;
   }
   if (node->cform != NULL) {
      free(node->cform);
      node->cform = NULL;
   }
   if (node->orig != NULL) {
      free(node->orig);
      node->orig = NULL;
   }
   if (node->read != NULL) {
      free(node->read);
      node->read = NULL;
   }
   if (node->pron != NULL) {
      free(node->pron);
      node->pron = NULL;
   }
   node->acc = 0;
   node->mora_size = 0;
   if (node->chain_rule != NULL) {
      free(node->chain_rule);
      node->chain_rule = NULL;
   }
   node->chain_flag = 0;
   node->prev = NULL;
   node->next = NULL;
}

NJD_NODE_C_END;

#endif                          /* !NJD_NODE_C */
