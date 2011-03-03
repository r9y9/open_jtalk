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

#ifndef NJD_RULE_H
#define NJD_RULE_H

#ifdef __cplusplus
#define NJD_RULE_H_START extern "C" {
#define NJD_RULE_H_END   }
#else
#define NJD_RULE_H_START
#define NJD_RULE_H_END
#endif                          /* __CPLUSPLUS */

NJD_RULE_H_START;

static const char *njd_mora_list[] = {
   "ヴョ",
   "ヴュ",
   "ヴャ",
   "ヴォ",
   "ヴェ",
   "ヴィ",
   "ヴァ",
   "ヴ",
   "ン",
   "ヲ",
   "ヱ",
   "ヰ",
   "ワ",
   "ロ",
   "レ",
   "ル",
   "リョ",
   "リュ",
   "リャ",
   "リェ",
   "リ",
   "ラ",
   "ヨ",
   "ョ",
   "ユ",
   "ュ",
   "ヤ",
   "ャ",
   "モ",
   "メ",
   "ム",
   "ミョ",
   "ミュ",
   "ミャ",
   "ミェ",
   "ミ",
   "マ",
   "ポ",
   "ボ",
   "ホ",
   "ペ",
   "ベ",
   "ヘ",
   "プ",
   "ブ",
   "フォ",
   "フェ",
   "フィ",
   "ファ",
   "フ",
   "ピョ",
   "ピュ",
   "ピャ",
   "ピェ",
   "ピ",
   "ビョ",
   "ビュ",
   "ビャ",
   "ビェ",
   "ビ",
   "ヒョ",
   "ヒュ",
   "ヒャ",
   "ヒェ",
   "ヒ",
   "パ",
   "バ",
   "ハ",
   "ノ",
   "ネ",
   "ヌ",
   "ニョ",
   "ニュ",
   "ニャ",
   "ニェ",
   "ニ",
   "ナ",
   "ドゥ",
   "ド",
   "ト",
   "デョ",
   "デュ",
   "デャ",
   "デェ",
   "ディ",
   "デ",
   "テョ",
   "テュ",
   "テャ",
   "ティ",
   "テ",
   "ヅ",
   "ツォ",
   "ツェ",
   "ツィ",
   "ツァ",
   "ツ",
   "ッ",
   "ヂ",
   "チョ",
   "チュ",
   "チャ",
   "チェ",
   "チ",
   "ダ",
   "タ",
   "ゾ",
   "ソ",
   "ゼ",
   "セ",
   "ズィ",
   "ズ",
   "スィ",
   "ス",
   "ジョ",
   "ジュ",
   "ジャ",
   "ジェ",
   "ジ",
   "ショ",
   "シュ",
   "シャ",
   "シェ",
   "シ",
   "ザ",
   "サ",
   "ゴ",
   "コ",
   "ゲ",
   "ケ",
   "グ",
   "ク",
   "ギョ",
   "ギュ",
   "ギャ",
   "ギェ",
   "ギ",
   "キョ",
   "キュ",
   "キャ",
   "キェ",
   "キ",
   "ガ",
   "カ",
   "オ",
   "ォ",
   "エ",
   "ェ",
   "ウォ",
   "ウェ",
   "ウィ",
   "ウ",
   "ゥ",
   "イェ",
   "イ",
   "ィ",
   "ア",
   "ァ",
   "ー",
   NULL
};

NJD_RULE_H_END;

#endif                          /* !NJD_RULE_H */
