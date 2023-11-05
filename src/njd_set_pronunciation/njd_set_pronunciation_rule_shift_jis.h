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

#ifndef NJD_SET_PRONUNCIATION_RULE_H
#define NJD_SET_PRONUNCIATION_RULE_H

#ifdef __cplusplus
#define NJD_SET_PRONUNCIATION_RULE_H_START extern "C" {
#define NJD_SET_PRONUNCIATION_RULE_H_END   }
#else
#define NJD_SET_PRONUNCIATION_RULE_H_START
#define NJD_SET_PRONUNCIATION_RULE_H_END
#endif                          /* __CPLUSPLUS */

NJD_SET_PRONUNCIATION_RULE_H_START;

static const char *njd_set_pronunciation_list[] = {
   "����", "����", "1",
   "����", "����", "1",
   "����", "����", "1",
   "���H", "���H", "1",
   "���F", "���F", "1",
   "���B", "���B", "1",
   "���@", "���@", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "����", "����", "1",
   "����", "����", "1",
   "����", "����", "1",
   "���F", "���F", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "�~��", "�~��", "1",
   "�~��", "�~��", "1",
   "�~��", "�~��", "1",
   "�~�F", "�~�F", "1",
   "�~", "�~", "1",
   "�}", "�}", "1",
   "�|", "�|", "1",
   "�{", "�{", "1",
   "�z", "�z", "1",
   "�y", "�y", "1",
   "�x", "�x", "1",
   "�w", "�w", "1",
   "�v", "�v", "1",
   "�u", "�u", "1",
   "�t�H", "�t�H", "1",
   "�t�F", "�t�F", "1",
   "�t�B", "�t�B", "1",
   "�t�@", "�t�@", "1",
   "�t", "�t", "1",
   "�s��", "�s��", "1",
   "�s��", "�s��", "1",
   "�s��", "�s��", "1",
   "�s�F", "�s�F", "1",
   "�s", "�s", "1",
   "�r��", "�r��", "1",
   "�r��", "�r��", "1",
   "�r��", "�r��", "1",
   "�r�F", "�r�F", "1",
   "�r", "�r", "1",
   "�q��", "�q��", "1",
   "�q��", "�q��", "1",
   "�q��", "�q��", "1",
   "�q�F", "�q�F", "1",
   "�q", "�q", "1",
   "�p", "�p", "1",
   "�o", "�o", "1",
   "�n", "�n", "1",
   "�m", "�m", "1",
   "�l", "�l", "1",
   "�k", "�k", "1",
   "�j��", "�j��", "1",
   "�j��", "�j��", "1",
   "�j��", "�j��", "1",
   "�j�F", "�j�F", "1",
   "�j", "�j", "1",
   "�i", "�i", "1",
   "�h�D", "�h�D", "1",
   "�h", "�h", "1",
   "�g�D", "�g�D", "1",
   "�g", "�g", "1",
   "�f��", "�f��", "1",
   "�f��", "�f��", "1",
   "�f��", "�f��", "1",
   "�f�B", "�f�B", "1",
   "�f", "�f", "1",
   "�e��", "�e��", "1",
   "�e��", "�e��", "1",
   "�e��", "�e��", "1",
   "�e�B", "�e�B", "1",
   "�e", "�e", "1",
   "�d", "�d", "1",
   "�c�H", "�c�H", "1",
   "�c�F", "�c�F", "1",
   "�c�B", "�c�B", "1",
   "�c�@", "�c�@", "1",
   "�c", "�c", "1",
   "�b", "�b", "1",
   "�a", "�a", "1",
   "�`��", "�`��", "1",
   "�`��", "�`��", "1",
   "�`��", "�`��", "1",
   "�`�F", "�`�F", "1",
   "�`", "�`", "1",
   "�_", "�_", "1",
   "�^", "�^", "1",
   "�]", "�]", "1",
   "�\", "�\", "1",
   "�[", "�[", "1",
   "�Z", "�Z", "1",
   "�Y�B", "�Y�B", "1",
   "�Y", "�Y", "1",
   "�X�B", "�X�B", "1",
   "�X", "�X", "1",
   "�W��", "�W��", "1",
   "�W��", "�W��", "1",
   "�W��", "�W��", "1",
   "�W�F", "�W�F", "1",
   "�W", "�W", "1",
   "�V��", "�V��", "1",
   "�V��", "�V��", "1",
   "�V��", "�V��", "1",
   "�V�F", "�V�F", "1",
   "�V", "�V", "1",
   "�U", "�U", "1",
   "�T", "�T", "1",
   "�S", "�S", "1",
   "�R", "�R", "1",
   "�Q", "�Q", "1",
   "�P", "�P", "1",
   "�O", "�O", "1",
   "�N", "�N", "1",
   "�M��", "�M��", "1",
   "�M��", "�M��", "1",
   "�M��", "�M��", "1",
   "�M�F", "�M�F", "1",
   "�M", "�M", "1",
   "�L��", "�L��", "1",
   "�L��", "�L��", "1",
   "�L��", "�L��", "1",
   "�L�F", "�L�F", "1",
   "�L", "�L", "1",
   "�K", "�K", "1",
   "�J", "�J", "1",
   "�I", "�I", "1",
   "�H", "�H", "1",
   "�G", "�G", "1",
   "�F", "�F", "1",
   "�E�H", "�E�H", "1",
   "�E�F", "�E�F", "1",
   "�E�B", "�E�B", "1",
   "�E", "�E", "1",
   "�D", "�D", "1",
   "�C�F", "�C�F", "1",
   "�C", "�C", "1",
   "�B", "�B", "1",
   "�A", "�A", "1",
   "�@", "�@", "1",
   "����", "����", "1", /* none in this charcode */
   "����", "����", "1", /* none in this charcode */
   "����", "����", "1", /* none in this charcode */
   "����", "���H", "1", /* none in this charcode */
   "����", "���F", "1", /* none in this charcode */
   "����", "���B", "1", /* none in this charcode */
   "����", "���@", "1", /* none in this charcode */
   "��", "��", "1", /* none in this charcode */
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "���", "����", "1",
   "���", "����", "1",
   "���", "����", "1",
   "�肥", "���F", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "��", "��", "1",
   "�݂�", "�~��", "1",
   "�݂�", "�~��", "1",
   "�݂�", "�~��", "1",
   "�݂�", "�~�F", "1",
   "��", "�~", "1",
   "��", "�}", "1",
   "��", "�|", "1",
   "��", "�{", "1",
   "��", "�z", "1",
   "��", "�y", "1",
   "��", "�x", "1",
   "��", "�w", "1",
   "��", "�v", "1",
   "��", "�u", "1",
   "�ӂ�", "�t�H", "1",
   "�ӂ�", "�t�F", "1",
   "�ӂ�", "�t�B", "1",
   "�ӂ�", "�t�@", "1",
   "��", "�t", "1",
   "�҂�", "�s��", "1",
   "�҂�", "�s��", "1",
   "�҂�", "�s��", "1",
   "�҂�", "�s�F", "1",
   "��", "�s", "1",
   "�т�", "�r��", "1",
   "�т�", "�r��", "1",
   "�т�", "�r��", "1",
   "�т�", "�r�F", "1",
   "��", "�r", "1",
   "�Ђ�", "�q��", "1",
   "�Ђ�", "�q��", "1",
   "�Ђ�", "�q��", "1",
   "�Ђ�", "�q�F", "1",
   "��", "�q", "1",
   "��", "�p", "1",
   "��", "�o", "1",
   "��", "�n", "1",
   "��", "�m", "1",
   "��", "�l", "1",
   "��", "�k", "1",
   "�ɂ�", "�j��", "1",
   "�ɂ�", "�j��", "1",
   "�ɂ�", "�j��", "1",
   "�ɂ�", "�j�F", "1",
   "��", "�j", "1",
   "��", "�i", "1",
   "�ǂ�", "�h�D", "1",
   "��", "�h", "1",
   "�Ƃ�", "�g�D", "1",
   "��", "�g", "1",
   "�ł�", "�f��", "1",
   "�ł�", "�f��", "1",
   "�ł�", "�f��", "1",
   "�ł�", "�f�B", "1",
   "��", "�f", "1",
   "�Ă�", "�e��", "1",
   "�Ă�", "�e��", "1",
   "�Ă�", "�e��", "1",
   "�Ă�", "�e�B", "1",
   "��", "�e", "1",
   "��", "�d", "1",
   "��", "�c�H", "1",
   "��", "�c�F", "1",
   "��", "�c�B", "1",
   "��", "�c�@", "1",
   "��", "�c", "1",
   "��", "�b", "1",
   "��", "�a", "1",
   "����", "�`��", "1",
   "����", "�`��", "1",
   "����", "�`��", "1",
   "����", "�`�F", "1",
   "��", "�`", "1",
   "��", "�_", "1",
   "��", "�^", "1",
   "��", "�]", "1",
   "��", "�\", "1",
   "��", "�[", "1",
   "��", "�Z", "1",
   "����", "�Y�B", "1",
   "��", "�Y", "1",
   "����", "�X�B", "1",
   "��", "�X", "1",
   "����", "�W��", "1",
   "����", "�W��", "1",
   "����", "�W��", "1",
   "����", "�W�F", "1",
   "��", "�W", "1",
   "����", "�V��", "1",
   "����", "�V��", "1",
   "����", "�V��", "1",
   "����", "�V�F", "1",
   "��", "�V", "1",
   "��", "�U", "1",
   "��", "�T", "1",
   "��", "�S", "1",
   "��", "�R", "1",
   "��", "�Q", "1",
   "��", "�P", "1",
   "��", "�O", "1",
   "��", "�N", "1",
   "����", "�M��", "1",
   "����", "�M��", "1",
   "����", "�M��", "1",
   "����", "�M�F", "1",
   "��", "�M", "1",
   "����", "�L��", "1",
   "����", "�L��", "1",
   "����", "�L��", "1",
   "����", "�L�F", "1",
   "��", "�L", "1",
   "��", "�K", "1",
   "��", "�J", "1",
   "��", "�I", "1",
   "��", "�H", "1",
   "��", "�G", "1",
   "��", "�F", "1",
   "����", "�E�H", "1",
   "����", "�E�F", "1",
   "����", "�E�B", "1",
   "��", "�E", "1",
   "��", "�D", "1",
   "����", "�C�F", "1",
   "��", "�C", "1",
   "��", "�B", "1",
   "��", "�A", "1",
   "��", "�@", "1",
   "��", "�Y�B�[", "2",
   "��", "���C", "2",
   "��", "�G�b�N�X", "4",
   "��", "�_�u�����[", "4",
   "��", "�u�C", "2",
   "��", "���[", "2",
   "��", "�e�B�[", "2",
   "��", "�G�X", "2",
   "��", "�A�[��", "3",
   "��", "�L���[", "2",
   "��", "�s�[", "2",
   "��", "�I�[", "2",
   "��", "�G�k", "2",
   "��", "�G��", "2",
   "��", "�G��", "2",
   "��", "�P�[", "2",
   "��", "�W�F�[", "2",
   "��", "�A�C", "2",
   "��", "�G�C�`", "3",
   "��", "�W�[", "2",
   "��", "�G�t", "2",
   "��", "�C�[", "2",
   "��", "�f�B�[", "2",
   "��", "�V�[", "2",
   "��", "�r�[", "2",
   "��", "�G�[", "2",
   "�y", "�Y�B�[", "2",
   "�x", "���C", "2",
   "�w", "�G�b�N�X", "4",
   "�v", "�_�u�����[", "4",
   "�u", "�u�C", "2",
   "�t", "���[", "2",
   "�s", "�e�B�[", "2",
   "�r", "�G�X", "2",
   "�q", "�A�[��", "3",
   "�p", "�L���[", "2",
   "�o", "�s�[", "2",
   "�n", "�I�[", "2",
   "�m", "�G�k", "2",
   "�l", "�G��", "2",
   "�k", "�G��", "2",
   "�j", "�P�[", "2",
   "�i", "�W�F�[", "2",
   "�h", "�A�C", "2",
   "�g", "�G�C�`", "3",
   "�f", "�W�[", "2",
   "�e", "�G�t", "2",
   "�d", "�C�[", "2",
   "�c", "�f�B�[", "2",
   "�b", "�V�[", "2",
   "�a", "�r�[", "2",
   "�`", "�G�[", "2",
   "�[", "�[", "1",
   NULL, NULL, NULL
};

#define NJD_SET_PRONUNCIATION_KIGOU "�L��"
#define NJD_SET_PRONUNCIATION_KAZU "��"

static const char *njd_set_pronunciation_symbol_list[] = {
   "�H", "�H",
   NULL, NULL
};

#define NJD_SET_PRONUNCIATION_FILLER "�t�B���["

#define NJD_SET_PRONUNCIATION_U        "�E"
#define NJD_SET_PRONUNCIATION_DOUSHI   "����"
#define NJD_SET_PRONUNCIATION_JODOUSHI "������"
#define NJD_SET_PRONUNCIATION_CHOUON   "�["

#define NJD_SET_PRONUNCIATION_QUESTION  "�H"
#define NJD_SET_PRONUNCIATION_DESU_STR  "�ł�"
#define NJD_SET_PRONUNCIATION_MASU_STR  "�܂�"
#define NJD_SET_PRONUNCIATION_DESU_PRON "�f�X"
#define NJD_SET_PRONUNCIATION_MASU_PRON "�}�X"

#define NJD_SET_PRONUNCIATION_TOUTEN "�A"
#define NJD_SET_PRONUNCIATION_TOUTEN_POS_GROUP1 "�Ǔ_"

NJD_SET_PRONUNCIATION_RULE_H_END;

#endif                          /* !NJD_SET_PRONUNCIATION_RULE_H */
