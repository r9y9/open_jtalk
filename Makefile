# Makefile for Open JTalk
#
# Simple Makefile following the pattern from .github/workflows/ccpp.yaml

# Build configuration
BUILD_TYPE ?= Release
BUILD_DIR = build
SRC_DIR = src

# Test configuration
TEST_DIR = tests
TEST_PROG = test_issue12
TEST_DICT_DIR = $(SRC_DIR)/mecab-naist-jdic/build
DICT_INDEX = $(BUILD_DIR)/mecab-dict-index
CC ?= gcc
CFLAGS = -Wall -O2 -I$(SRC_DIR)/jpcommon -I$(SRC_DIR)/mecab/src \
         -I$(SRC_DIR)/mecab2njd -I$(SRC_DIR)/njd -I$(SRC_DIR)/njd2jpcommon \
         -I$(SRC_DIR)/njd_set_accent_phrase -I$(SRC_DIR)/njd_set_accent_type \
         -I$(SRC_DIR)/njd_set_digit -I$(SRC_DIR)/njd_set_long_vowel \
         -I$(SRC_DIR)/njd_set_pronunciation -I$(SRC_DIR)/njd_set_unvoiced_vowel \
         -I$(SRC_DIR)/text2mecab
LDFLAGS = -L$(BUILD_DIR) -lopenjtalk

.PHONY: all build clean test dict help

# Default target
all: build

# Help target
help:
	@echo "Open JTalk Makefile"
	@echo "==================="
	@echo ""
	@echo "Targets:"
	@echo "  make build    - Build the Open JTalk library"
	@echo "  make dict     - Build the MeCab dictionary (needed once)"
	@echo "  make test     - Build and run test for issue #12"
	@echo "  make clean    - Clean build artifacts"
	@echo ""
	@echo "Example:"
	@echo "  make build"
	@echo "  make dict     # First time only"
	@echo "  make test"

# Build the Open JTalk library (same as CI workflow)
build:
	@echo "Building Open JTalk library..."
	cd $(SRC_DIR) && cmake -D CMAKE_BUILD_TYPE=$(BUILD_TYPE) -D BUILD_SHARED_LIBS=ON -S . -B ../$(BUILD_DIR)
	cmake --build $(BUILD_DIR) --config $(BUILD_TYPE)
	@echo "Build complete!"

# Build dictionary compiler
$(DICT_INDEX): build
	@echo "Building dictionary compiler..."
	g++ -O2 -DHAVE_CONFIG_H -DDIC_VERSION=102 -DMECAB_DEFAULT_RC=\"dummy\" \
		-DCHARSET_UTF_8 -DMECAB_CHARSET=utf-8 -DPACKAGE=\"open_jtalk\" \
		-DVERSION=\"1.11\" -I$(SRC_DIR)/mecab/src \
		$(SRC_DIR)/mecab/src/mecab-dict-index.cpp \
		$(SRC_DIR)/mecab/src/dictionary*.cpp \
		$(SRC_DIR)/mecab/src/eval.cpp \
		$(SRC_DIR)/mecab/src/feature_index.cpp \
		$(SRC_DIR)/mecab/src/lbfgs.cpp \
		$(SRC_DIR)/mecab/src/learner*.cpp \
		$(SRC_DIR)/mecab/src/libmecab.cpp \
		$(SRC_DIR)/mecab/src/nbest_generator.cpp \
		$(SRC_DIR)/mecab/src/param.cpp \
		$(SRC_DIR)/mecab/src/string_buffer.cpp \
		$(SRC_DIR)/mecab/src/tagger.cpp \
		$(SRC_DIR)/mecab/src/tokenizer.cpp \
		$(SRC_DIR)/mecab/src/utils.cpp \
		$(SRC_DIR)/mecab/src/viterbi.cpp \
		$(SRC_DIR)/mecab/src/writer.cpp \
		$(SRC_DIR)/mecab/src/char_property.cpp \
		$(SRC_DIR)/mecab/src/connector.cpp \
		$(SRC_DIR)/mecab/src/context_id.cpp \
		$(SRC_DIR)/mecab/src/iconv_utils.cpp \
		-o $(DICT_INDEX) -lstdc++ 2>&1 | grep -v "warning:"

# Build dictionary
dict: $(DICT_INDEX)
	@echo "Building MeCab dictionary..."
	@mkdir -p $(TEST_DICT_DIR)
	cd $(SRC_DIR)/mecab-naist-jdic && ../../$(DICT_INDEX) -d . -o build -f utf-8 -t utf-8
	@echo "Dictionary built successfully!"

# Build test program
$(TEST_DIR)/$(TEST_PROG): $(TEST_DIR)/$(TEST_PROG).c build
	$(CC) $(CFLAGS) -o $(TEST_DIR)/$(TEST_PROG) $(TEST_DIR)/$(TEST_PROG).c $(LDFLAGS)

# Run test
test: $(TEST_DIR)/$(TEST_PROG)
	@if [ ! -d "$(TEST_DICT_DIR)" ]; then \
		echo "Dictionary not found. Building..."; \
		$(MAKE) dict; \
	fi
	@export DYLD_LIBRARY_PATH=$(BUILD_DIR):$$DYLD_LIBRARY_PATH; \
	export LD_LIBRARY_PATH=$(BUILD_DIR):$$LD_LIBRARY_PATH; \
	./$(TEST_DIR)/$(TEST_PROG) $(TEST_DICT_DIR)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(TEST_DIR)/$(TEST_PROG) $(SRC_DIR)/mecab/src/config.h $(TEST_DICT_DIR)
