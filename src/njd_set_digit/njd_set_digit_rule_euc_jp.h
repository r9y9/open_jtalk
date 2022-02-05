/* ----------------------------------------------------------------- */
/*           The Japanese TTS System "Open JTalk"                    */
/*           developed by HTS Working Group                          */
/*           http://open-jtalk.sourceforge.net/                      */
/* ----------------------------------------------------------------- */
/*                                                                   */
/*  Copyright (c) 2008-2016  Nagoya Institute of Technology          */
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

#ifndef NJD_SET_DIGIT_RULE_H
#define NJD_SET_DIGIT_RULE_H

#ifdef __cplusplus
#define NJD_SET_DIGIT_RULE_H_START extern "C" {
#define NJD_SET_DIGIT_RULE_H_END   }
#else
#define NJD_SET_DIGIT_RULE_H_START
#define NJD_SET_DIGIT_RULE_H_END
#endif                          /* __CPLUSPLUS */

NJD_SET_DIGIT_RULE_H_START;

#define NJD_SET_DIGIT_KIGOU "����"
#define NJD_SET_DIGIT_MEISHI "̾��"
#define NJD_SET_DIGIT_KAZU "��"
#define NJD_SET_DIGIT_SUUSETSUZOKU "����³"
#define NJD_SET_DIGIT_JOSUUSHI "������"
#define NJD_SET_DIGIT_FUKUSHIKANOU "�����ǽ"
#define NJD_SET_DIGIT_HAIHUN1 "��"     /* horizontal bar */
#define NJD_SET_DIGIT_HAIHUN2 "��"     /* minus sign */
#define NJD_SET_DIGIT_HAIHUN3 "��"     /* hyphen */
#define NJD_SET_DIGIT_HAIHUN4 "��"     /* em dash */
#define NJD_SET_DIGIT_HAIHUN5 "��"     /* fullwidth hyphen-minus */
#define NJD_SET_DIGIT_KAKKO1 "��"
#define NJD_SET_DIGIT_KAKKO2 "��"
#define NJD_SET_DIGIT_BANGOU "�ֹ�"
#define NJD_SET_DIGIT_COMMA "��"
#define NJD_SET_DIGIT_TEN1 "��"
#define NJD_SET_DIGIT_TEN2 "��"
#define NJD_SET_DIGIT_TEN_FEATURE "��,̾��,����,������,*,*,*,��,�ƥ�,�ƥ�,0/2,*,-1"
#define NJD_SET_DIGIT_ZERO1 "��"
#define NJD_SET_DIGIT_ZERO2 "��"
#define NJD_SET_DIGIT_ZERO_BEFORE_DP "�졼"
#define NJD_SET_DIGIT_ZERO_AFTER_DP "����"
#define NJD_SET_DIGIT_TWO "��"
#define NJD_SET_DIGIT_TWO_BEFORE_DP "�ˡ�"
#define NJD_SET_DIGIT_TWO_AFTER_DP "�ˡ�"
#define NJD_SET_DIGIT_FIVE "��"
#define NJD_SET_DIGIT_FIVE_BEFORE_DP "����"
#define NJD_SET_DIGIT_FIVE_AFTER_DP "����"
#define NJD_SET_DIGIT_SIX "ϻ"
#define NJD_SET_DIGIT_NIN "��"
#define NJD_SET_DIGIT_GATSU "��"
#define NJD_SET_DIGIT_NICHI "��"
#define NJD_SET_DIGIT_NICHIKAN "����"
#define NJD_SET_DIGIT_ONE "��"
#define NJD_SET_DIGIT_TSUITACHI "����,̾��,�����ǽ,*,*,*,*,����,�ĥ�����,�ĥ�����,4/4,*"
#define NJD_SET_DIGIT_FOUR "��"
#define NJD_SET_DIGIT_TEN "��"
#define NJD_SET_DIGIT_JUYOKKA "������,̾��,�����ǽ,*,*,*,*,������,���奦��å�,���塼��å�,1/5,*"
#define NJD_SET_DIGIT_JUYOKKAKAN "��������,̾��,�����ǽ,*,*,*,*,��������,���奦��å�����,���塼��å�����,5/7,*"
#define NJD_SET_DIGIT_NIJU "��,̾��,�����ǽ,*,*,*,*,��,�˥��奦,�˥��塼,1/3,*"
#define NJD_SET_DITIT_YOKKA "����,̾��,�����ǽ,*,*,*,*,����,��å�,��å�,0/3,*,0"
#define NJD_SET_DIGIT_YOKKAKAN "������,̾��,�����ǽ,*,*,*,*,������,��å�����,��å�����,3/5,*,0"
#define NJD_SET_DITIT_HATSUKA "����,̾��,�����ǽ,*,*,*,*,����,�ϥĥ�,�ϥĥ�,0/3,*"
#define NJD_SET_DIGIT_HATSUKAKAN "������,̾��,�����ǽ,*,*,*,*,������,�ϥĥ�����,�ϥĥ�����,3/5,*"

static const char *njd_set_digit_rule_numeral_list1[] = {
   "��", "0", "��",
   "��", "1", "��",
   "��", "2", "��",
   "��", "3", "��",
   "��", "4", "��",
   "��", "5", "��",
   "��", "6", "ϻ",
   "��", "7", "��",
   "��", "8", "Ȭ",
   "��", "9", "��",
   "��", "1", "��",
   "��", "2", "��",
   "��", "3", "��",
   "��", "4", "��",
   "��", "5", "��",
   "ϻ", "6", "ϻ",
   "��", "7", "��",
   "Ȭ", "8", "Ȭ",
   "��", "9", "��",
   "����", "1", "��",
   "��", "2", "��",
   "����", "3", "��",
   "���", "4", "��",
   "��", "5", "��",
   "��", "6", "ϻ",
   "�ʤ�", "7", "��",
   "�Ϥ�", "8", "Ȭ",
   "���夦", "9", "��",
   "��", "0", "��",
   "��", "0", "��",
   "��", "1", "��",
   "��", "2", "��",
   "��", "2", "��",
   "��", "2", "��",
   "��", "3", "��",
   "��", "4", "��",
   "����", "7", "��",
   "��", "9", "��",
   NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numeral_list2[] = {
   "",
   "��,̾��,��,*,*,*,*,��,���奦,���塼,1/2,*",
   "ɴ,̾��,��,*,*,*,*,ɴ,�ҥ㥯,�ҥ㥯,2/2,*",
   "��,̾��,��,*,*,*,*,��,����,����,1/2,*",
   NULL
};

static const char *njd_set_digit_rule_numeral_list3[] = {
   "",
   "��,̾��,��,*,*,*,*,��,�ޥ�,�ޥ�,1/2,*",
   "��,̾��,��,*,*,*,*,��,����,����,1/2,*",
   "��,̾��,��,*,*,*,*,��,���祦,���硼,1/2,C3",
   "��,̾��,��,*,*,*,*,��,����,����,1/2,*",
   "Զ,̾��,��,*,*,*,*,Զ,����,����,1/2,*",
   "��ͽ,̾��,��,*,*,*,*,��ͽ,����,����,1/1,*", /* none in this charcode */
   "��,̾��,��,*,*,*,*,��,���祦,���硼,1/2,*",
   "��,̾��,��,*,*,*,*,��,����,����,1/2,*",
   "��,̾��,��,*,*,*,*,��,����,����,1/2,*",
   "��,̾��,��,*,*,*,*,��,����,����,1/2,*",
   "��,̾��,��,*,*,*,*,��,����,����,1/2,*",
   "��,̾��,��,*,*,*,*,��,����,����,1/2,*",
   "���Ϻ�,̾��,��,*,*,*,*,���Ϻ�,����������,����������,1/4,*",
   "���ε�,̾��,��,*,*,*,*,���ε�,��������,��������,2/4,*",
   "��ͳ¾,̾��,��,*,*,*,*,��ͳ¾,�ʥ楿,�ʥ楿,1/3,*",
   "�ԲĻ׵�,̾��,��,*,*,*,*,�ԲĻ׵�,�ե�����,�ե�����,2/4,*",
   "̵�����,̾��,��,*,*,*,*,̵�����,���祦��������,���硼��������,6/7,*",
   NULL
};

static const char *njd_set_digit_rule_numeral_list4[] = {
   "��", "��", "��", "��", "��", "ϻ", "��", "Ȭ", "��", "��", "��", "��",
   NULL
};

static const char *njd_set_digit_rule_numeral_list5[] = {
   "��", "ɴ", "��", "��", "��", "��", "��", "Զ",
   "��ͽ", /* none in this charcode */
   "��", "��", "��", "��", "��", "��",
   "���Ϻ�", "���ε�", "��ͳ¾", "�ԲĻ׵�", "̵�����",
   NULL
};

static const char *njd_set_digit_rule_numeral_list6[] = {
   "ɴ", "��", NULL
};

static const char *njd_set_digit_rule_numeral_list7[] = {
   "��", "1",
   "ϻ", "2",
   "Ȭ", "2",
   "��", "1",
   NULL, NULL
};

static const char *njd_set_digit_rule_numeral_list8[] = {
   "ɴ", NULL
};

static const char *njd_set_digit_rule_numeral_list9[] = {
   "ϻ", "���", "0", "2",
   "Ȭ", "�ϥ�", "0", "2",
   NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numeral_list10[] = {
   "��", "��", NULL
};

static const char *njd_set_digit_rule_numeral_list11[] = {
   "��", "����", "0", "2",
   "Ȭ", "�ϥ�", "0", "2",
   "��", "�����", "1", "2",
   NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1b[] = {
   /* from paper */
   "ǯ" /* �ͤ� */ , "��",
   /* from dictionary */
   "ǯ��", "ǯ��", "ǯ��", "ǯ��", "ǯ��", "ǯ;", "ǯ;", "ǯ��", "����",
   NULL
};

static const char *njd_set_digit_rule_conv_table1b[] = {
   "��", "��", "0", "1",
   NULL, NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1c1[] = {
   /* from paper */
   "��",
   /* from dictionary */
   "�ͷ�", "����", "����",
   NULL
};

static const char *njd_set_digit_rule_conv_table1c1[] = {
   "��", "��", "0", "1",
   "��", "����", "1", "2",
   NULL, NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1c2[] = {
   /* from paper */
   "��", "����",
   /* from dictionary */
   "����", "��Ⱦ",
   NULL
};

static const char *njd_set_digit_rule_conv_table1c2[] = {
   "��", "��", "0", "1",
   "��", "����", "1", "2",
   "��", "��", "0", "1",
   NULL, NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1d[] = {
   /* from paper */
   "��" /* �ˤ� */ ,
   /* from dictionary */
   "����",
   NULL
};

static const char *njd_set_digit_rule_conv_table1d[] = {
   /* "��", "���", "1", "2", *//* modified */
   "��", "����", "1", "2",
   "��", "��", "0", "1",
   NULL, NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1e[] = {
   /* from paper */
   "��" /* ���� */ ,
   NULL
};

static const char *njd_set_digit_rule_conv_table1e[] = {
   "��", "��", "0", "1",
   "��", "����", "1", "2",
   "��", "��", "0", "1",
   NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1f[] = {
   /* from paper */
   /* "��", "��", *//* modified */
   NULL
};

static const char *njd_set_digit_rule_conv_table1f[] = {
   "ϻ", "���", "1", "2",
   "Ȭ", "�ϥ�", "1", "2",
   "��", "�����", "1", "2",
   "ɴ", "�ҥ��", "1", "2",
   NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1g[] = {
   /* from paper */
   "��", "��", "ʬ" /* �դ� */ , "ȯ", "��", "ȭ", "��", "�ڤ�", "Ȣ",
   /* from dictionary */
   "����", "����", "����", "����", "��¼", "��ǯ", "����", "����", "����", "����", "����", "��¼",
   "��Ź", "��ǯ", "����", "����", "����", "����", "��¼", "��ǯ", "����", "����", "����",
   "����", "��¼", "��ǯ", "����", "����", "����", "����", "��¼", "��ǯ", "�ķ�", "�ĸ�",
   "�Ĺ�", "�ľ�", "��ǯ", "�շ�", "�չ�", "�ս�", "�վ�", "��ǯ", "����", "������", "����",
   "��", "��", "��", "��", "���", "����", "����", "����", "��ʬ", "��Τ", "������", "��", "��",
   "��", "��", "��", "��", "��", "����", "��", "��", "��", "����", "��", "����", "��", "��",
   "��", "��", "��", "��", "��", "��", "��", "��", "�Ť�", "��", "��", "��", "��", "��", "��",
   "��", "����", "��", "��", /* "��", */ "��", "��", "��", "��", "��", "��", "��", "��ǯ", "��",
   "�Ԥ�", "�ڤ�", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ɤ", "ɥ", "ɮ", "ɶ",
   "ɼ", "��", "ʬ��", "ʬ��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
   "ˡ", "��Ω��", "Ƭ��",
   NULL
};

static const char *njd_set_digit_rule_conv_table1g[] = {
   "��", "����", "1", "2",
   "ϻ", "���", "1", "2",
   "Ȭ", "�ϥ�", "1", "2",
   "��", "�����", "1", "2",
   "ɴ", "�ҥ��", "1", "2",
   NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1h[] = {
   /* from paper */
   "��", "��", "��", "Ƭ", "��", "­", "��", "��", "�̤�", "�����", "��������",
   /* from dictionary */
   "�ã�", "���", "���", "��������", "���������", "��������", "������", "�����",
   "���󥬥ݡ���ɥ�", "�������ե��", "���������ǥ󥯥���", "������", "���å�", "�����",
   "����", "������", "��", "��", "��", "��", "����", "��", "�л�", "��", "��", "��", "��", "ܪ",
   "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "����", "��ǯ", "��",
   "��", "����", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "����", "��",
   "�ʿ�", "��", "����", "����", "����", "��", "��", "��", "��", "��", "��", "��", "��", "��",
   "��", "��", "��", "��", "��", "·", "����", "�Ĥ���", "�Ĥ���", "�Ĥ�", "�Ĥޤ�", "����",
   "���ޤ�", "�Ȥ���", "�Ȥ�", "�Ȥ���", "�Ȥ�", "��", "��", "��", "«", "³��", "��", "��",
   "��", "î", "ȿ", "��", "����", "Ļ", "��", "�Ϥ�", "��", "ũ", "Ź", "ž", "��", "��", "��",
   "��", "��", "��", "����", "����", "��ʬ", "��", "��", "��", "γ", "����", "����", "����",
   "�ּ�",
   NULL
};

static const char *njd_set_digit_rule_conv_table1h[] = {
   "��", "����", "1", "2",
   "Ȭ", "�ϥ�", "1", "2",
   "��", "�����", "1", "2",
   NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1i[] = {
   /* from paper */
   "����", "����꡼",
   /* from dictionary */
   "����", "���", "���", "���", "���", "���", "���", "�륰���", "��Х���", "��إ��",
   "��᡼�ȥ�", "���åȥ�", "���å�", "���ʥ��ɥ�", "����å�", "�����", "����꡼",
   "������꡼", "�������", "����ȥ�", "����Х���", "����إ��", "����᡼�ȥ�",
   "�����åȥ�", "�����å�", "�����åȻ�", "���饹", "������", "������", "�������",
   "������", "������", "��",
   NULL
};

static const char *njd_set_digit_rule_conv_table1i[] = {
   "ϻ", "���", "1", "2",
   "��", "�����", "1", "2",
   "ɴ", "�ҥ��", "1", "2",
   NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1j[] = {
   /* from paper */
   "�ȥ�",
   /* from dictionary */
   "��", "����", "�ƥ�", "�ȥ饤",
   NULL
};

static const char *njd_set_digit_rule_conv_table1j[] = {
   "��", "����", "1", "2",
   "��", "�����", "1", "2",
   NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1k[] = {
   /* from paper */
   "˼" /* �դ� */ , "��", "��", "�ݥ��",
   /* from dictionary */
   "���", "����", "�ѡ������", "�ѡ��ߥ�", "�ѥ�����", "�ѥå�", "�ѥå�", "�ԡ��ԡ�����",
   "�ԥ�", "�ڡ���", "��", "�ڥ�", "�ڥ���", "�ڥ�", "�ڥˡ�", "�ڥ˥�", "�ڥ�", "�ݥ����",
   "����", "��", "��", "ĥ��", "ʿ��", "ʿ������", "ʿ������᡼�ȥ�", "ʿ��������᡼�ȥ�",
   "ʿ���᡼�ȥ�", "����",
   NULL
};

static const char *njd_set_digit_rule_conv_table1k[] = {
   "��", "�����", "1", "2",
   NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class2b[] = {
   /* from paper */
   "ʬ", "��", "��", "ȯ", "��", "ȭ",
   /* from dictionary */
   "��", "��", "��", "��", "��", "��", "ʬ��", "ʬ��", "��", "��", "��", "��", "��", "��", "��",
   "��",
   NULL
};

static const char *njd_set_digit_rule_conv_table2b[] = {
   "��", "2",
   "��", "2",
   "��", "2",
   "ϻ", "2",
   "Ȭ", "2",
   "��", "2",
   "ɴ", "2",
   "��", "2",
   "��", "2",
   "��", "2",
   NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class2c[] = {
   /* from paper */
   "��", "ɤ", "ɥ", "ɼ", "ɶ", "Ȣ",
   /* from dictionary */
   "��Ω��", "��", "��", "��",
   NULL
};

static const char *njd_set_digit_rule_conv_table2c[] = {
   "��", "2",
   "��", "1",
   "ϻ", "2",
   "Ȭ", "2",
   "��", "2",
   "ɴ", "2",
   "��", "1",
   "��", "1",
   "��", "1",
   NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class2d[] = {
   /* from paper */
   /* "��", "��", *//* modified */
   NULL
};

static const char *njd_set_digit_rule_conv_table2d[] = {
   "��", "1",
   "ϻ", "2",
   "Ȭ", "2",
   "��", "2",
   "ɴ", "2",
   "��", "1",
   "��", "1",
   "��", "1",
   NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class2e[] = {
   /* from paper */
   "��", "��", "­", "��",
   /* from dictionary */
   "����", "�Ť�", "��", "��",
   NULL
};

static const char *njd_set_digit_rule_conv_table2e[] = {
   "��", "1",
   "��", "1",
   "��", "1",
   NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class2f[] = {
   /* from paper */
   "��",
   NULL
};

static const char *njd_set_digit_rule_conv_table2f[] = {
   "��", "1",
   NULL, NULL
};

static const char *njd_set_digit_rule_voiced_sound_symbol_list[] = {
   "��", "��",
   "��", "��",
   "��", "��",
   "��", "��",
   "��", "��",
   "��", "��",
   "��", "��",
   "��", "��",
   "��", "��",
   "��", "��",
   "��", "��",
   "��", "��",
   "��", "��",
   "��", "��",
   "��", "��",
   "��", "��",
   "��", "��",
   "��", "��",
   "��", "��",
   "��", "��",
   NULL, NULL
};

static const char *njd_set_digit_rule_semivoiced_sound_symbol_list[] = {
   "��", "��",
   "��", "��",
   "��", "��",
   "��", "��",
   "��", "��",
   NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class3[] = {
   /* from paper */
   "��", "���",
   /* from dictionary */
   "����", "����",
   "������", "������",
   "����", "����",
   "����", "����",
   "����", "����",
   "����", "����",
   "�Ĥ���", "�ĥ���",
   "�Ĥ���", "�ĥ���",
   "�Ĥޤ�", "�ĥޥ�",
   "�Ȥ���", "�ȥ���",
   "�Ȥ���", "�ȥ���",
   "�Ȥ�", "�ȥ�",
   "�ޤ��", "�ޥ��",
   "��������", "��������",
   "���å�", "���å�",
   "����", "�˥���",
   "���", "�ޥ��",
   "��", "����",
   "��", "����",
   "��", "����",
   "��", "����",
   "����", "����",
   "��", "�ĥ�",
   "��", "����",
   "��", "����",
   "����", "����",
   "��", "����",
   "��", "���",
   "��", "���㥯",
   "��", "���㥯",
   "�Ť�", "������",
   "����", "�ե�",
   "��", "�ϥ�",
   "�ڤ�", "����",
   "«", "����",
   "³��", "�ĥť�",
   "·", "����",
   "��", "�ե���",
   "��", "�ϥ���",
   "ĥ��", "�ϥ�",
   "�̤�", "�ȥ���",
   "�Ϥ�", "�ĥ���",
   "��", "�ĥ�",
   "Ȣ", "�ϥ�",
   "ȭ", "�ϥ�",
   "��", "�Х�",
   "��", "����",
   "��", "�ӥ�",
   "ʬ��", "�辰",
   "��", "�ޥ�",
   "��", "��",
   "��", "��",
   "γ", "�ĥ�",
   "��", "�說",
   "ܪ", "����",
   "����", "�ĥ���",
   "���ޤ�", "�ĥ���",
   "γ", "�ĥ�",
   "�Ĥ�", "�ĥ�",
   "�Ȥ�", "�ȥ�",
   "�Ť�", "������",
   NULL, NULL
};

static const char *njd_set_digit_rule_conv_table3[] = {
   "��", "�ҥ�", "0", "2",
   "��", "�ե�", "0", "2",
   /* "��", "��", "1", "1", *//* modified */
   NULL, NULL, NULL, NULL
};

static const char *njd_set_digit_rule_conv_table4[] = {
   "��", "���,̾��,�����ǽ,*,*,*,*,���,�ҥȥ�,�ҥȥ�,2/3,*",
   "��", "���,̾��,�����ǽ,*,*,*,*,���,�ե���,�ե���,3/3,*",
   NULL, NULL
};

static const char *njd_set_digit_rule_conv_table5[] = {
   "��", "����,̾��,�����ǽ,*,*,*,*,����,�����˥�,�����˥�,4/4,*",
   "��", "����,̾��,�����ǽ,*,*,*,*,����,�եĥ�,�եĥ�,0/3,*",
   "��", "����,̾��,�����ǽ,*,*,*,*,����,�ߥå�,�ߥå�,0/3,*",
   "��", "����,̾��,�����ǽ,*,*,*,*,����,��å�,��å�,0/3,*",
   "��", "����,̾��,�����ǽ,*,*,*,*,����,���ĥ�,���ĥ�,0/3,*",
   "ϻ", "ϻ��,̾��,�����ǽ,*,*,*,*,ϻ��,�।��,�।��,0/3,*",
   "��", "����,̾��,�����ǽ,*,*,*,*,����,�ʥΥ�,�ʥΥ�,0/3,*",
   "Ȭ", "Ȭ��,̾��,�����ǽ,*,*,*,*,Ȭ��,�襦��,�衼��,0/3,*",
   "��", "����,̾��,�����ǽ,*,*,*,*,����,�����Υ�,�����Υ�,0/4,*",
   "��", "����,̾��,�����ǽ,*,*,*,*,����,�ȥ���,�ȡ���,0/3,*",
   NULL, NULL
};

static const char *njd_set_digit_rule_conv_table6[] = {
   "��", "������,̾��,�����ǽ,*,*,*,*,������,�����˥�����,�����˥�����,4/6,*",
   "��", "������,̾��,�����ǽ,*,*,*,*,����,�եĥ�����,�եĥ�����,3/5,*",
   "��", "������,̾��,�����ǽ,*,*,*,*,����,�ߥå�����,�ߥå�����,3/5,*",
   "��", "������,̾��,�����ǽ,*,*,*,*,����,��å�����,��å�����,3/5,*",
   "��", "������,̾��,�����ǽ,*,*,*,*,����,���ĥ�����,���ĥ�����,3/5,*",
   "ϻ", "ϻ����,̾��,�����ǽ,*,*,*,*,ϻ��,�।������,�।������,3/5,*",
   "��", "������,̾��,�����ǽ,*,*,*,*,����,�ʥΥ�����,�ʥΥ�����,3/5,*",
   "Ȭ", "Ȭ����,̾��,�����ǽ,*,*,*,*,Ȭ��,�襦������,�衼������,3/5,*",
   "��", "������,̾��,�����ǽ,*,*,*,*,����,�����Υ�����,�����Υ�����,4/6,*",
   "��", "������,̾��,�����ǽ,*,*,*,*,����,�ȥ�������,�ȡ�������,3/5,*",
   NULL, NULL
};

NJD_SET_DIGIT_RULE_H_END;

#endif                          /* !NJD_SET_DIGIT_RULE_H */
