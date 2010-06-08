
EXTRA_DIST = Makefile.mak

DISTCLEANFILES = *.log *.out *~

MAINTAINERCLEANFILES = Makefile.in

INCLUDES = @CHARSET@

noinst_LIBRARIES = libnjd.a

libnjd_a_SOURCES = njd.h \
                   njd.c \
                   njd_node.c \
                   njd_rule_euc_jp.h \
                   njd_rule_shift_jis.h \
                   njd_rule_utf_8.h
