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

#define NJD_SET_DIGIT_KIGOU "�L��"
#define NJD_SET_DIGIT_MEISHI "����"
#define NJD_SET_DIGIT_KAZU "��"
#define NJD_SET_DIGIT_SUUSETSUZOKU "���ڑ�"
#define NJD_SET_DIGIT_JOSUUSHI "������"
#define NJD_SET_DIGIT_FUKUSHIKANOU "�����\"
#define NJD_SET_DIGIT_HAIHUN1 "�\"     /* horizontal bar */
#define NJD_SET_DIGIT_HAIHUN2 "�|"     /* minus sign */
#define NJD_SET_DIGIT_HAIHUN3 "�]"     /* hyphen */
#define NJD_SET_DIGIT_HAIHUN4 "�\"     /* em dash */
#define NJD_SET_DIGIT_HAIHUN5 "�|"     /* fullwidth hyphen-minus */
#define NJD_SET_DIGIT_KAKKO1 "�i"
#define NJD_SET_DIGIT_KAKKO2 "�j"
#define NJD_SET_DIGIT_BANGOU "�ԍ�"
#define NJD_SET_DIGIT_COMMA "�C"
#define NJD_SET_DIGIT_TEN1 "�D"
#define NJD_SET_DIGIT_TEN2 "�E"
#define NJD_SET_DIGIT_TEN_FEATURE "�D,����,�ڔ�,������,*,*,*,�D,�e��,�e��,0/2,*,-1"
#define NJD_SET_DIGIT_ZERO1 "�Z"
#define NJD_SET_DIGIT_ZERO2 "�O"
#define NJD_SET_DIGIT_ZERO_BEFORE_DP "���["
#define NJD_SET_DIGIT_ZERO_AFTER_DP "�[��"
#define NJD_SET_DIGIT_TWO "��"
#define NJD_SET_DIGIT_TWO_BEFORE_DP "�j�["
#define NJD_SET_DIGIT_TWO_AFTER_DP "�j�["
#define NJD_SET_DIGIT_FIVE "��"
#define NJD_SET_DIGIT_FIVE_BEFORE_DP "�S�["
#define NJD_SET_DIGIT_FIVE_AFTER_DP "�S�["
#define NJD_SET_DIGIT_SIX "�Z"
#define NJD_SET_DIGIT_NIN "�l"
#define NJD_SET_DIGIT_GATSU "��"
#define NJD_SET_DIGIT_NICHI "��"
#define NJD_SET_DIGIT_NICHIKAN "����"
#define NJD_SET_DIGIT_ONE "��"
#define NJD_SET_DIGIT_TSUITACHI "���,����,�����\,*,*,*,*,���,�c�C�^�`,�c�C�^�`,4/4,*"
#define NJD_SET_DIGIT_FOUR "�l"
#define NJD_SET_DIGIT_TEN "�\"
#define NJD_SET_DIGIT_JUYOKKA "�\�l��,����,�����\,*,*,*,*,�\�l��,�W���E���b�J,�W���[���b�J,1/5,*"
#define NJD_SET_DIGIT_JUYOKKAKAN "�\�l����,����,�����\,*,*,*,*,�\�l����,�W���E���b�J�J��,�W���[���b�J�J��,5/7,*"
#define NJD_SET_DIGIT_NIJU "��\,����,�����\,*,*,*,*,��\,�j�W���E,�j�W���[,1/3,*"
#define NJD_SET_DITIT_YOKKA "�l��,����,�����\,*,*,*,*,�l��,���b�J,���b�J,0/3,*,0"
#define NJD_SET_DIGIT_YOKKAKAN "�l����,����,�����\,*,*,*,*,�l����,���b�J�J��,���b�J�J��,3/5,*,0"
#define NJD_SET_DITIT_HATSUKA "��\��,����,�����\,*,*,*,*,��\��,�n�c�J,�n�c�J,0/3,*"
#define NJD_SET_DIGIT_HATSUKAKAN "��\����,����,�����\,*,*,*,*,��\����,�n�c�J�J��,�n�c�J�J��,3/5,*"

static const char *njd_set_digit_rule_numeral_list1[] = {
   "��", "0", "�Z",
   "�P", "1", "��",
   "�Q", "2", "��",
   "�R", "3", "�O",
   "�S", "4", "�l",
   "�T", "5", "��",
   "�U", "6", "�Z",
   "�V", "7", "��",
   "�W", "8", "��",
   "�X", "9", "��",
   "��", "1", "��",
   "��", "2", "��",
   "�O", "3", "�O",
   "�l", "4", "�l",
   "��", "5", "��",
   "�Z", "6", "�Z",
   "��", "7", "��",
   "��", "8", "��",
   "��", "9", "��",
   "����", "1", "��",
   "��", "2", "��",
   "����", "3", "�O",
   "���", "4", "�l",
   "��", "5", "��",
   "�낭", "6", "�Z",
   "�Ȃ�", "7", "��",
   "�͂�", "8", "��",
   "���イ", "9", "��",
   "�Z", "0", "�Z",
   "�O", "0", "�O",
   "��", "1", "��",
   "��", "2", "��",
   "��", "2", "��",
   "�j", "2", "��",
   "�Q", "3", "�O",
   "��", "4", "�l",
   "����", "7", "��",
   "��", "9", "��",
   NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numeral_list2[] = {
   "",
   "�\,����,��,*,*,*,*,�\,�W���E,�W���[,1/2,*",
   "�S,����,��,*,*,*,*,�S,�q���N,�q���N,2/2,*",
   "��,����,��,*,*,*,*,��,�Z��,�Z��,1/2,*",
   NULL
};

static const char *njd_set_digit_rule_numeral_list3[] = {
   "",
   "��,����,��,*,*,*,*,��,�}��,�}��,1/2,*",
   "��,����,��,*,*,*,*,��,�I�N,�I�N,1/2,*",
   "��,����,��,*,*,*,*,��,�`���E,�`���[,1/2,C3",
   "��,����,��,*,*,*,*,��,�P�C,�P�[,1/2,*",
   "��,����,��,*,*,*,*,��,�K�C,�K�C,1/2,*",
   "�ї\,����,��,*,*,*,*,�ї\,�W��,�W��,1/1,*", /* none in this charcode */
   "��,����,��,*,*,*,*,��,�W���E,�W���[,1/2,*",
   "�a,����,��,*,*,*,*,�a,�R�E,�R�E,1/2,*",
   "��,����,��,*,*,*,*,��,�J��,�J��,1/2,*",
   "��,����,��,*,*,*,*,��,�Z�C,�Z�[,1/2,*",
   "��,����,��,*,*,*,*,��,�T�C,�T�C,1/2,*",
   "��,����,��,*,*,*,*,��,�S�N,�S�N,1/2,*",
   "�P�͍�,����,��,*,*,*,*,�P�͍�,�S�E�K�V��,�S�E�K�V��,1/4,*",
   "���m�_,����,��,*,*,*,*,���m�_,�A�\�E�M,�A�\�[�M,2/4,*",
   "�ߗR��,����,��,*,*,*,*,�ߗR��,�i���^,�i���^,1/3,*",
   "�s�v�c,����,��,*,*,*,*,�s�v�c,�t�J�V�M,�t�J�V�M,2/4,*",
   "���ʑ吔,����,��,*,*,*,*,���ʑ吔,�������E�^�C�X�E,�������[�^�C�X�[,6/7,*",
   NULL
};

static const char *njd_set_digit_rule_numeral_list4[] = {
   "��", "��", "�O", "�l", "��", "�Z", "��", "��", "��", "��", "��", "��",
   NULL
};

static const char *njd_set_digit_rule_numeral_list5[] = {
   "�\", "�S", "��", "��", "��", "��", "��", "��",
   "�ї\", /* none in this charcode */
   "��", "�a", "��", "��", "��", "��",
   "�P�͍�", "���m�_", "�ߗR��", "�s�v�c", "���ʑ吔",
   NULL
};

static const char *njd_set_digit_rule_numeral_list6[] = {
   "�S", "��", NULL
};

static const char *njd_set_digit_rule_numeral_list7[] = {
   "�O", "1",
   "�Z", "2",
   "��", "2",
   "��", "1",
   NULL, NULL
};

static const char *njd_set_digit_rule_numeral_list8[] = {
   "�S", NULL
};

static const char *njd_set_digit_rule_numeral_list9[] = {
   "�Z", "���b", "0", "2",
   "��", "�n�b", "0", "2",
   NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numeral_list10[] = {
   "��", "��", NULL
};

static const char *njd_set_digit_rule_numeral_list11[] = {
   "��", "�C�b", "0", "2",
   "��", "�n�b", "0", "2",
   "�\", "�W���b", "1", "2",
   NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1b[] = {
   /* from paper */
   "�N" /* �˂� */ , "�~",
   /* from dictionary */
   "�N��", "�N��", "�N��", "�N�x", "�N��", "�N�]", "�N�]", "�N��", "����",
   NULL
};

static const char *njd_set_digit_rule_conv_table1b[] = {
   "�l", "��", "0", "1",
   NULL, NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1c1[] = {
   /* from paper */
   "�l",
   /* from dictionary */
   "�l��", "�l�O", "�l�g",
   NULL
};

static const char *njd_set_digit_rule_conv_table1c1[] = {
   "�l", "��", "0", "1",
   "��", "�V�`", "1", "2",
   NULL, NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1c2[] = {
   /* from paper */
   "��", "����",
   /* from dictionary */
   "����", "����",
   NULL
};

static const char *njd_set_digit_rule_conv_table1c2[] = {
   "�l", "��", "0", "1",
   "��", "�V�`", "1", "2",
   "��", "�N", "0", "1",
   NULL, NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1d[] = {
   /* from paper */
   "��" /* �ɂ� */ ,
   /* from dictionary */
   "����",
   NULL
};

static const char *njd_set_digit_rule_conv_table1d[] = {
   /* "�l", "���b", "1", "2", *//* modified */
   "��", "�V�`", "1", "2",
   "��", "�N", "0", "1",
   NULL, NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1e[] = {
   /* from paper */
   "��" /* ���� */ ,
   NULL
};

static const char *njd_set_digit_rule_conv_table1e[] = {
   "�l", "�V", "0", "1",
   "��", "�V�`", "1", "2",
   "��", "�N", "0", "1",
   NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1f[] = {
   /* from paper */
   /* "�H", "�c", *//* modified */
   NULL
};

static const char *njd_set_digit_rule_conv_table1f[] = {
   "�Z", "���b", "1", "2",
   "��", "�n�b", "1", "2",
   "�\", "�W���b", "1", "2",
   "�S", "�q���b", "1", "2",
   NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1g[] = {
   /* from paper */
   "��", "�K", "��" /* �ӂ� */ , "��", "�{", "��", "��", "�؂�", "��",
   /* from dictionary */
   "����", "����", "����", "����", "����", "���N", "�J��", "�J��", "�J��", "�J��", "�J��", "�J��",
   "�J�X", "�J�N", "�P��", "�P��", "�P��", "�P��", "�P��", "�P�N", "����", "����", "����",
   "����", "����", "���N", "����", "����", "����", "����", "����", "���N", "��", "��",
   "��", "��", "�N", "�ӌ�", "�Ӎ�", "�ӏ�", "�ӏ�", "�ӔN", "����", "������", "����",
   "��", "��", "��", "��", "���", "��", "���", "���", "��", "�C��", "�J�C��", "�\", "�p",
   "��", "��", "��", "��", "��", "�і�", "��", "��", "��", "����", "�@", "�C��", "�G", "�R",
   "�q", "�r", "��", "��", "��", "��", "��", "��", "�d��", "��", "��", "��", "��", "��", "�v",
   "��", "�P�^", "�Z", "�`", /* "�s", */ "��", "�g", "��", "��", "��", "��", "��", "���N", "��",
   "�҂�", "�؂�", "�g", "�h", "�s", "�t", "��", "��", "��", "��", "��", "�C", "�D", "�M", "�U",
   "�[", "�i", "����", "����", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
   "�@", "�{����", "���g",
   NULL
};

static const char *njd_set_digit_rule_conv_table1g[] = {
   "��", "�C�b", "1", "2",
   "�Z", "���b", "1", "2",
   "��", "�n�b", "1", "2",
   "�\", "�W���b", "1", "2",
   "�S", "�q���b", "1", "2",
   NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1h[] = {
   /* from paper */
   "�D", "�E", "��", "��", "��", "��", "��", "��", "�ʂ�", "�Z���`", "�V�[�V�[",
   /* from dictionary */
   "�b�b", "����", "����", "�T�C�N��", "�T���`�[��", "�V�[�Y��", "�V�[�g", "�V�����O",
   "�V���K�|�[���h��", "�X�C�X�t����", "�X�E�F�[�f���N���[�l", "�X�N��", "�Z�b�g", "�Z���g",
   "�\��", "�]�[��", "�W", "�W", "��", "��", "����", "��", "�Ύ�", "��", "��", "��", "�M", "��",
   "�z", "�q", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "����", "���N", "�B",
   "�T", "�T��", "�W", "�h", "��", "��", "��", "��", "��", "�F", "�F", "�H", "�e��", "�i",
   "�i��", "�i", "����", "����", "���낢", "��", "��", "��", "��", "��", "��", "��", "��", "��",
   "��", "�I", "�K", "�w", "��", "��", "����", "����", "����", "��", "�܂�", "��",
   "�܂�", "�Ƃ���", "�Ƃ�", "�Ƃ���", "�Ƃ�", "��", "��", "��", "��", "����", "��", "��",
   "��", "�M", "��", "��", "����", "��", "��", "�͂�", "��", "�H", "�X", "�]", "�_", "�l", "��",
   "��", "��", "��", "����", "���n", "����", "��", "��", "��", "��", "���", "�Δn", "���I",
   "�Ԏ�",
   NULL
};

static const char *njd_set_digit_rule_conv_table1h[] = {
   "��", "�C�b", "1", "2",
   "��", "�n�b", "1", "2",
   "�\", "�W���b", "1", "2",
   NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1i[] = {
   /* from paper */
   "�L��", "�J�����[",
   /* from dictionary */
   "������", "����", "����", "����", "����", "����", "����", "���O����", "���o�C�g", "���w���c",
   "�����[�g��", "�����b�g��", "�����b�g", "�J�i�_�h��", "�J���b�g", "�K����", "�L�����[",
   "�L���J�����[", "�L���O����", "�L���g��", "�L���o�C�g", "�L���w���c", "�L�����[�g��",
   "�L�����b�g��", "�L�����b�g", "�L�����b�g��", "�N���X", "�N���[�i", "�N���[�l", "�O�@���j",
   "�P�[�X", "�R�[�X", "��",
   NULL
};

static const char *njd_set_digit_rule_conv_table1i[] = {
   "�Z", "���b", "1", "2",
   "�\", "�W���b", "1", "2",
   "�S", "�q���b", "1", "2",
   NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1j[] = {
   /* from paper */
   "�g��",
   /* from dictionary */
   "��", "�^��", "�e��", "�g���C",
   NULL
};

static const char *njd_set_digit_rule_conv_table1j[] = {
   "��", "�C�b", "1", "2",
   "�\", "�W���b", "1", "2",
   NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class1k[] = {
   /* from paper */
   "�[" /* �ӂ� */ , "��", "��", "�|���h",
   /* from dictionary */
   "����", "������", "�p�[�Z���g", "�p�[�~��", "�p�X�J��", "�p�b�N", "�p�b�g", "�s�[�s�[�G��",
   "�s�R", "�y�[�W", "��", "�y�A", "�y�Z�^", "�y�\", "�y�j�[", "�y�j�q", "�y���X", "�|�C���g",
   "�U��", "�j", "��", "����", "����", "�����L��", "�����L�����[�g��", "�����Z���`���[�g��",
   "�������[�g��", "�i��",
   NULL
};

static const char *njd_set_digit_rule_conv_table1k[] = {
   "�\", "�W���b", "1", "2",
   NULL, NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class2b[] = {
   /* from paper */
   "��", "��", "�s", "��", "��", "��",
   /* from dictionary */
   "�g", "�h", "��", "��", "��", "�i", "����", "����", "��", "��", "��", "��", "��", "��", "��",
   "��",
   NULL
};

static const char *njd_set_digit_rule_conv_table2b[] = {
   "��", "2",
   "�O", "2",
   "�l", "2",
   "�Z", "2",
   "��", "2",
   "�\", "2",
   "�S", "2",
   "��", "2",
   "��", "2",
   "��", "2",
   NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class2c[] = {
   /* from paper */
   "�{", "�C", "�D", "�[", "�U", "��",
   /* from dictionary */
   "�{����", "�t", "�j", "��",
   NULL
};

static const char *njd_set_digit_rule_conv_table2c[] = {
   "��", "2",
   "�O", "1",
   "�Z", "2",
   "��", "2",
   "�\", "2",
   "�S", "2",
   "��", "1",
   "��", "1",
   "��", "1",
   NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class2d[] = {
   /* from paper */
   /* "�H", "�c", *//* modified */
   NULL
};

static const char *njd_set_digit_rule_conv_table2d[] = {
   "�O", "1",
   "�Z", "2",
   "��", "2",
   "�\", "2",
   "�S", "2",
   "��", "1",
   "��", "1",
   "��", "1",
   NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class2e[] = {
   /* from paper */
   "��", "��", "��", "��",
   /* from dictionary */
   "����", "�d��", "��", "��",
   NULL
};

static const char *njd_set_digit_rule_conv_table2e[] = {
   "�O", "1",
   "��", "1",
   "��", "1",
   NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class2f[] = {
   /* from paper */
   "�K",
   NULL
};

static const char *njd_set_digit_rule_conv_table2f[] = {
   "�O", "1",
   NULL, NULL
};

static const char *njd_set_digit_rule_voiced_sound_symbol_list[] = {
   "�J", "�K",
   "�L", "�M",
   "�N", "�O",
   "�P", "�Q",
   "�R", "�S",
   "�T", "�U",
   "�V", "�W",
   "�X", "�Y",
   "�Z", "�[",
   "�\", "�]",
   "�^", "�_",
   "�`", "�a",
   "�c", "�d",
   "�e", "�f",
   "�g", "�h",
   "�n", "�o",
   "�q", "�r",
   "�t", "�u",
   "�w", "�x",
   "�z", "�{",
   NULL, NULL
};

static const char *njd_set_digit_rule_semivoiced_sound_symbol_list[] = {
   "�n", "�p",
   "�q", "�s",
   "�t", "�v",
   "�w", "�y",
   "�z", "�|",
   NULL, NULL
};

static const char *njd_set_digit_rule_numerative_class3[] = {
   /* from paper */
   "��", "���l",
   /* from dictionary */
   "����", "�J�P",
   "������", "�N�_��",
   "����", "�P�^",
   "����", "�X�W",
   "���낢", "�\���C",
   "����", "�^�r",
   "����", "�c�J�~",
   "����", "�c�K�C",
   "�܂�", "�c�}�~",
   "�Ƃ���", "�g�I��",
   "�Ƃ���", "�g�R��",
   "�Ƃ�", "�g�Z",
   "�܂��", "�}����",
   "�V�[�Y��", "�V�[�Y��",
   "�Z�b�g", "�Z�b�g",
   "����", "�j�M��",
   "���", "�}����",
   "��", "�J�u",
   "��", "�T�I",
   "��", "�X�W",
   "��", "�P�^",
   "�P�^", "�P�^",
   "��", "�c�L",
   "��", "�R�g",
   "��", "�N�`",
   "����", "�T�V",
   "�M", "�T��",
   "�R", "���}",
   "��", "�V���N",
   "��", "�V���N",
   "�d��", "�J�T�l",
   "�U��", "�t��",
   "�j", "�n��",
   "�؂�", "�L��",
   "��", "�^�o",
   "����", "�c�d�L",
   "��", "�\���C",
   "��", "�t�N��",
   "��", "�n�V��",
   "����", "�n��",
   "�ʂ�", "�g�I��",
   "�͂�", "�c�J�~",
   "��", "�c�{",
   "��", "�n�R",
   "��", "�n�`",
   "��", "�o��",
   "�i", "�V�i",
   "�r", "�r��",
   "����", "���P",
   "��", "�}�N",
   "��", "��",
   "��", "��",
   "��", "�c�u",
   "�g", "���N",
   "��", "�T�I",
   "��", "�c�I��",
   "�܂�", "�c�I��",
   "��", "�c�u",
   "��", "�c�u",
   "�Ƃ�", "�g�L",
   "�d��", "�K�T�l",
   NULL, NULL
};

static const char *njd_set_digit_rule_conv_table3[] = {
   "��", "�q�g", "0", "2",
   "��", "�t�^", "0", "2",
   /* "�O", "�~", "1", "1", *//* modified */
   NULL, NULL, NULL, NULL
};

static const char *njd_set_digit_rule_conv_table4[] = {
   "��", "��l,����,�����\,*,*,*,*,��l,�q�g��,�q�g��,2/3,*",
   "��", "��l,����,�����\,*,*,*,*,��l,�t�^��,�t�^��,3/3,*",
   NULL, NULL
};

static const char *njd_set_digit_rule_conv_table5[] = {
   "��", "���,����,�����\,*,*,*,*,���,�C�`�j�`,�C�`�j�`,4/4,*",
   "��", "���,����,�����\,*,*,*,*,���,�t�c�J,�t�c�J,0/3,*",
   "�O", "�O��,����,�����\,*,*,*,*,�O��,�~�b�J,�~�b�J,0/3,*",
   "�l", "�l��,����,�����\,*,*,*,*,�l��,���b�J,���b�J,0/3,*",
   "��", "�ܓ�,����,�����\,*,*,*,*,�ܓ�,�C�c�J,�C�c�J,0/3,*",
   "�Z", "�Z��,����,�����\,*,*,*,*,�Z��,���C�J,���C�J,0/3,*",
   "��", "����,����,�����\,*,*,*,*,����,�i�m�J,�i�m�J,0/3,*",
   "��", "����,����,�����\,*,*,*,*,����,���E�J,���[�J,0/3,*",
   "��", "���,����,�����\,*,*,*,*,���,�R�R�m�J,�R�R�m�J,0/4,*",
   "�\", "�\��,����,�����\,*,*,*,*,�\��,�g�E�J,�g�[�J,0/3,*",
   NULL, NULL
};

static const char *njd_set_digit_rule_conv_table6[] = {
   "��", "�����,����,�����\,*,*,*,*,�����,�C�`�j�`�J��,�C�`�j�`�J��,4/6,*",
   "��", "�����,����,�����\,*,*,*,*,���,�t�c�J�J��,�t�c�J�J��,3/5,*",
   "�O", "�O����,����,�����\,*,*,*,*,�O��,�~�b�J�J��,�~�b�J�J��,3/5,*",
   "�l", "�l����,����,�����\,*,*,*,*,�l��,���b�J�J��,���b�J�J��,3/5,*",
   "��", "�ܓ���,����,�����\,*,*,*,*,�ܓ�,�C�c�J�J��,�C�c�J�J��,3/5,*",
   "�Z", "�Z����,����,�����\,*,*,*,*,�Z��,���C�J�J��,���C�J�J��,3/5,*",
   "��", "������,����,�����\,*,*,*,*,����,�i�m�J�J��,�i�m�J�J��,3/5,*",
   "��", "������,����,�����\,*,*,*,*,����,���E�J�J��,���[�J�J��,3/5,*",
   "��", "�����,����,�����\,*,*,*,*,���,�R�R�m�J�J��,�R�R�m�J�J��,4/6,*",
   "�\", "�\����,����,�����\,*,*,*,*,�\��,�g�E�J�J��,�g�[�J�J��,3/5,*",
   NULL, NULL
};

NJD_SET_DIGIT_RULE_H_END;

#endif                          /* !NJD_SET_DIGIT_RULE_H */
