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

#ifndef NJD2JPCOMMON_RULE_H
#define NJD2JPCOMMON_RULE_H

#ifdef __cplusplus
#define NJD2JPCOMMON_RULE_H_START extern "C" {
#define NJD2JPCOMMON_RULE_H_END   }
#else
#define NJD2JPCOMMON_RULE_H_START
#define NJD2JPCOMMON_RULE_H_END
#endif                          /* __CPLUSPLUS */

NJD2JPCOMMON_RULE_H_START;

static const char *njd2jpcommon_pos_list[] = {
   "���̑�", "�ԓ�", "*", "*", "���̑�",
   "�t�B���[", "*", "*", "*", "������",
   "������", "*", "*", "*", "������",
   "�L��", "*", "*", "*", "�L��",
   "�L��", "�A���t�@�x�b�g", "*", "*", "�L��",
   "�L��", "���", "*", "*", "�L��",
   "�L��", "���ʊJ", "*", "*", "�L��",
   "�L��", "���ʕ�", "*", "*", "�L��",
   "�L��", "��_", "*", "*", "�L��",
   "�L��", "��", "*", "*", "�L��",
   "�L��", "��", "*", "*", "�L��",
   "�L��", "�Ǔ_", "*", "*", "�L��",
   "�`�e��", "����", "*", "*", "�`�e��",
   "�`�e��", "�ڔ�", "*", "*", "�ڔ���-�`�e���I",
   "�`�e��", "�񎩗�", "*", "*", "�`�e��",
   "����", "�i����", "���", "*", "����-�i����",
   "����", "�i����", "���p", "*", "����-�i����",
   "����", "�i����", "�A��", "*", "����-�i����",
   "����", "�W����", "*", "*", "����-�W����",
   "����", "�I����", "*", "*", "����-�I����",
   "����", "�ڑ�����", "*", "*", "����-�ڑ�����",
   "����", "����", "*", "*", "����-���̑�",
   "����", "������", "*", "*", "����-���̑�",
   "����", "������", "*", "*", "����-������",
   "����", "�������^���������^�I����", "*", "*", "����-���̑�",
   "����", "��������", "*", "*", "����-���̑�",
   "����", "�A�̉�", "*", "*", "����-���̑�",
   "������", "*", "*", "*", "������",
   "�ڑ���", "*", "*", "*", "�ڑ���",
   "�ړ���", "�`�e���ڑ�", "*", "*", "�ړ���",
   "�ړ���", "���ڑ�", "*", "*", "�ړ���",
   "�ړ���", "�����ڑ�", "*", "*", "�ړ���",
   "�ړ���", "�����ڑ�", "*", "*", "�ړ���",
   "����", "����", "*", "*", "����",
   "����", "�ڔ�", "*", "*", "�ڔ���-�����I",
   "����", "�񎩗�", "*", "*", "����-�񎩗�",
   "����", "*", "*", "*", "����",
   "����", "���", "*", "*", "����",
   "����", "�����ސڑ�", "*", "*", "����",
   "����", "�T�ϐڑ�", "*", "*", "����-�T�ϐڑ�",
   "����", "�i�C�`�e���ꊲ", "*", "*", "����-���ʖ���",
   "����", "���", "*", "*", "����-���ʖ���",
   "����", "���p������", "*", "*", "����-���ʖ���",
   "����", "�`�e�����ꊲ", "*", "*", "�`��",
   "����", "�ŗL����", "���", "*", "����-�ŗL����",
   "����", "�ŗL����", "�l��", "���", "����-�ŗL����",
   "����", "�ŗL����", "�l��", "��", "����-�ŗL����",
   "����", "�ŗL����", "�l��", "��", "����-�ŗL����",
   "����", "�ŗL����", "�g�D", "*", "����-�ŗL����",
   "����", "�ŗL����", "�n��", "���", "����-�ŗL����",
   "����", "�ŗL����", "�n��", "��", "����-�ŗL����",
   "����", "��", "*", "*", "����-����",
   "����", "�ڑ����I", "*", "*", "����-���ʖ���",
   "����", "�ڔ�", "�T�ϐڑ�", "*", "�ڔ���-�����I",
   "����", "�ڔ�", "���", "*", "�ڔ���-�����I",
   "����", "�ڔ�", "�`�e�����ꊲ", "*", "�ڔ���-�`�󎌓I",
   "����", "�ڔ�", "������", "*", "�ڔ���-�����I",
   "����", "�ڔ�", "�������ꊲ", "*", "�ڔ���-�����I",
   "����", "�ڔ�", "�l��", "*", "�ڔ���-�����I",
   "����", "�ڔ�", "�n��", "*", "�ڔ���-�����I",
   "����", "�ڔ�", "����", "*", "�ڔ���-�����I",
   "����", "�ڔ�", "�����\", "*", "�ڔ���-�����I",
   "����", "�㖼��", "���", "*", "�㖼��",
   "����", "�㖼��", "�k��", "*", "�㖼��",
   "����", "�����񎩗��I", "*", "*", "����-���ʖ���",
   "����", "����", "�������ꊲ", "*", "����-���ʖ���",
   "����", "�񎩗�", "���", "*", "����-�񎩗�",
   "����", "�񎩗�", "�`�e�����ꊲ", "*", "����-�񎩗�",
   "����", "�񎩗�", "�������ꊲ", "*", "����-�񎩗�",
   "����", "�񎩗�", "�����\", "*", "����-�񎩗�",
   "����", "�񎩗�", "*", "*", "����-�񎩗�",
   "����", "�����\", "*", "*", "����-���ʖ���",
   "�A�̎�", "*", "*", "*", "�A�̎�",
   NULL, NULL, NULL, NULL, NULL
};

static const char *njd2jpcommon_cform_list[] = {
   "*", "*",
   "�K���ڑ�", "���̑�",
   "���֊�{�`", "��{�`",
   "����`", "����`",
   "����k��P", "����`",
   "����k��Q", "����`",
   "��{�`", "��{�`",
   "��{�`-������", "��{�`",
   "�����{�`", "��{�`",
   "�̌��ڑ�", "�A�̌`",
   "�̌��ڑ�����", "�A�̌`",
   "�̌��ڑ�����Q", "�A�̌`",
   "�����{�`", "��{�`",
   "���R�E�ڑ�", "���R�`",
   "���R�k�ڑ�", "���R�`",
   "���R�����ڑ�", "���R�`",
   "���R�`", "���R�`",
   "���R����", "���R�`",
   "���߂�", "���ߌ`",
   "���߂�", "���ߌ`",
   "���߂���", "���ߌ`",
   "���߂���", "���ߌ`",
   "�A�p�S�U�C�ڑ�", "�A�p�`",
   "�A�p�^�ڑ�", "�A�p�`",
   "�A�p�e�ڑ�", "�A�p�`",
   "�A�p�f�ڑ�", "�A�p�`",
   "�A�p�j�ڑ�", "�A�p�`",
   "�A�p�`", "�A�p�`",
   NULL, NULL
};

static const char *njd2jpcommon_ctype_list[] = {
   "*", "*",
   "�J�ρE�N��", "�J�s�ϊi",
   "�J�ρE����", "�J�s�ϊi",
   "�T�ρE�|�X��", "�T�s�ϊi",
   "�T�ρE�|�Y��", "�T�s�ϊi",
   "�T�ρE�X��", "�T�s�ϊi",
   "����", "���s�ϊi",
   "��i", "��i",
   "��i�E�N����", "��i",
   "��i�E����", "��i",
   "����E�J�s", "��i",
   "����E�K�s", "��i",
   "����E�^�s", "��i",
   "����E�_�s", "��i",
   "����E�n�s", "��i",
   "����E�}�s", "��i",
   "����E��", "��i",
   "�`�e���E�A�E�I�i", "�`�e��",
   "�`�e���E�C�C", "�`�e��",
   "�`�e���E�C�i", "�`�e��",
   "�ܒi�E�J�s�C����", "�ܒi",
   "�ܒi�E�J�s������", "�ܒi",
   "�ܒi�E�J�s�����փ��N", "�ܒi",
   "�ܒi�E�K�s", "�ܒi",
   "�ܒi�E�T�s", "�ܒi",
   "�ܒi�E�^�s", "�ܒi",
   "�ܒi�E�i�s", "�ܒi",
   "�ܒi�E�o�s", "�ܒi",
   "�ܒi�E�}�s", "�ܒi",
   "�ܒi�E���s", "�ܒi",
   "�ܒi�E���s�A��", "�ܒi",
   "�ܒi�E���s����", "�ܒi",
   "�ܒi�E���s�E����", "�ܒi",
   "�ܒi�E���s������", "�ܒi",
   "�l�i�E�T�s", "�l�i",
   "�l�i�E�^�s", "�l�i",
   "�l�i�E�n�s", "�l�i",
   "�l�i�E�o�s", "�l�i",
   "���E�_�s", "��i",
   "���E�n�s", "��i",
   "����E�W��", "������",
   "����E�^", "������",
   "����E�^�C", "������",
   "����E�_", "������",
   "����E�f�X", "������",
   "����E�i�C", "������",
   "����E�k", "������",
   "����E�}�X", "������",
   "����E��", "������",
   "�s�ω��^", "�s�ω�",
   "����E�L", "���ꏕ����",
   "����E�P��", "���ꏕ����",
   "����E�S�g�V", "���ꏕ����",
   "����E�i��", "���ꏕ����",
   "����E�x�V", "���ꏕ����",
   "����E�}�W", "���ꏕ����",
   "����E��", "���ꏕ����",
   "����E��", "���ꏕ����",
   NULL, NULL
};

NJD2JPCOMMON_RULE_H_END;

#endif                          /* !NJD2JPCOMMON_RULE_H */
