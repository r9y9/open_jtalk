/* ----------------------------------------------------------------- */
/*           The HMM-Based Speech Synthesis System (HTS)             */
/*           Open JTalk developed by HTS Working Group               */
/*           http://open-jtalk.sourceforge.net/                      */
/* ----------------------------------------------------------------- */
/*                                                                   */
/*  Copyright (c) 2008-2010  Nagoya Institute of Technology          */
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "njd.h"

void NJD_initialize(NJD * njd)
{
   njd->head = NULL;
   njd->tail = NULL;
}

int NJD_get_size(NJD * njd)
{
   int i;
   NJDNode *node = njd->head;

   for (i = 0; node != NULL; i++)
      node = node->next;
   return i;
}

void NJD_push_node(NJD * njd, NJDNode * node)
{
   if (njd->head == NULL) {
      njd->head = node;
   } else {
      njd->tail->next = node;
      node->prev = njd->tail;
   }
   while (node->next != NULL)
      node = node->next;
   njd->tail = node;
}

void NJD_insert_node(NJD * njd, NJDNode * prev, NJDNode * next, NJDNode * node)
{
   NJDNode *tail;

   if (prev == NULL && next == NULL) {
      fprintf(stderr, "ERROR: NJD_insert_node() in njd.c: NJDNodes are not specified.\n");
      exit(1);
   }
   tail = node;
   while (tail->next != NULL)
      tail = tail->next;
   if (prev == NULL) {
      if (next != njd->head) {
         fprintf(stderr, "ERROR: NJD_insert_node() in njd.c: NJDNodes are wrong.\n");
         exit(1);
      }
      tail->next = njd->head;
      node->prev = NULL;
      njd->head->prev = tail;
      njd->head = node;
   } else if (next == NULL) {
      if (prev != njd->tail) {
         fprintf(stderr, "ERROR: NJD_insert_node() in njd.c: NJDNodes are wrong.\n");
         exit(1);
      }
      tail->next = NULL;
      node->prev = njd->tail;
      njd->tail->next = node;
      njd->tail = tail;
   } else {
      if (prev->next != next || prev != next->prev) {
         fprintf(stderr, "ERROR: NJD_insert_node() in njd.c: NJDNodes are wrong.\n");
         exit(1);
      }
      prev->next = node;
      node->prev = prev;
      next->prev = tail;
      tail->next = next;
   }
}

void NJD_remove_silent_node(NJD * njd)
{
   NJDNode *node;
   NJDNode *next;

   for (node = njd->head; node != NULL;) {
      if (NJDNode_get_pron(node) == NULL || strcmp(NJDNode_get_pron(node), "") == 0) {
         if (node == njd->head && node == njd->tail) {
            njd->head = NULL;
            njd->tail = NULL;
            next = NULL;
         } else if (node == njd->head) {
            njd->head = node->next;
            njd->head->prev = NULL;
            next = njd->head;
         } else if (node == njd->tail) {
            njd->tail = node->prev;
            njd->tail->next = NULL;
            next = NULL;
         } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            next = node->next;
         }
         NJDNode_clear(node);
         free(node);
         node = next;
      } else {
         node = node->next;
      }
   }
}

void NJD_print(NJD * njd)
{
   NJD_fprint(njd, stdout);
}

void NJD_fprint(NJD * njd, FILE * fp)
{
   NJDNode *node;

   for (node = njd->head; node != NULL; node = node->next)
      NJDNode_fprint(node, fp);
}

void NJD_refresh(NJD * njd)
{
   NJD_clear(njd);
   NJD_initialize(njd);
}

void NJD_clear(NJD * njd)
{
   NJDNode *node;

   while (njd->head != NULL) {
      node = njd->head->next;
      NJDNode_clear(njd->head);
      free(njd->head);
      njd->head = node;
   }
   njd->tail = NULL;
}
