
EXTRA_DIST = COPYING naist-jdic.csv matrix.def left-id.def pos-id.def rewrite.def right-id.def char.def unk.def feature.def

DISTCLEANFILES = *.log *.out *~

MAINTAINERCLEANFILES = Makefile.in char.bin matrix.bin sys.dic unk.dic

dicdir = @prefix@/dic

dic_DATA   = matrix.bin char.bin sys.dic unk.dic left-id.def right-id.def rewrite.def pos-id.def

matrix.bin char.bin sys.dic unk.dic: naist-jdic.csv matrix.def left-id.def rewrite.def pos-id.def right-id.def char.def unk.def feature.def
	../mecab/src/mecab-dict-index -d . -o . -f EUC-JP -t @MECAB_CHARSET@

clean:
	rm -f char.bin matrix.bin sys.dic unk.dic
