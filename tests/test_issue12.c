/* Test program for issue #12: very long word triggers SEGV
 *
 * This test verifies that processing very long repeated characters
 * doesn't cause a buffer overflow or segmentation fault.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Include open_jtalk headers */
#include "mecab.h"
#include "njd.h"
#include "jpcommon.h"
#include "text2mecab.h"
#include "mecab2njd.h"
#include "njd_set_pronunciation.h"
#include "njd_set_digit.h"
#include "njd_set_accent_phrase.h"
#include "njd_set_accent_type.h"
#include "njd_set_unvoiced_vowel.h"
#include "njd_set_long_vowel.h"
#include "njd2jpcommon.h"

/* Test configuration */
#define TEST_CHAR_COUNT 5000  /* Increased from 1000 to thoroughly test the fix */
#define BUFSIZE (TEST_CHAR_COUNT * 3 + 1024)  /* UTF-8 "ア" is 3 bytes */

typedef struct {
    Mecab mecab;
    NJD njd;
    JPCommon jpcommon;
} TestContext;

static void test_init(TestContext *ctx) {
    Mecab_initialize(&ctx->mecab);
    NJD_initialize(&ctx->njd);
    JPCommon_initialize(&ctx->jpcommon);
}

static void test_clear(TestContext *ctx) {
    Mecab_clear(&ctx->mecab);
    NJD_clear(&ctx->njd);
    JPCommon_clear(&ctx->jpcommon);
}

int main(int argc, char **argv) {
    TestContext ctx;
    char *input_text = NULL;
    char *buff = NULL;
    int result = 0;
    int i;
    char *dict_dir = NULL;

    printf("Test for issue #12: very long word triggers SEGV\n");
    printf("=================================================\n\n");

    /* Get dictionary directory from command line or environment */
    if (argc > 1) {
        dict_dir = argv[1];
    } else {
        dict_dir = getenv("OPEN_JTALK_DICT_DIR");
    }

    if (dict_dir == NULL) {
        fprintf(stderr, "Usage: %s <dictionary_directory>\n", argv[0]);
        fprintf(stderr, "   or set OPEN_JTALK_DICT_DIR environment variable\n");
        return 1;
    }

    /* Allocate buffers */
    input_text = (char *)malloc(BUFSIZE);
    buff = (char *)malloc(BUFSIZE);
    if (input_text == NULL || buff == NULL) {
        fprintf(stderr, "ERROR: Failed to allocate memory\n");
        result = 1;
        goto cleanup;
    }

    /* Create test input: "ア" repeated TEST_CHAR_COUNT times */
    printf("Creating test input: \"ア\" repeated %d times...\n", TEST_CHAR_COUNT);
    input_text[0] = '\0';
    for (i = 0; i < TEST_CHAR_COUNT; i++) {
        strcat(input_text, "ア");
    }
    printf("Input text length: %zu bytes\n\n", strlen(input_text));

    /* Initialize test context */
    printf("Initializing Open JTalk components...\n");
    test_init(&ctx);

    /* Load dictionary */
    printf("Loading dictionary from: %s\n", dict_dir);
    if (Mecab_load(&ctx.mecab, dict_dir) != TRUE) {
        fprintf(stderr, "ERROR: Failed to load dictionary\n");
        result = 1;
        goto cleanup_ctx;
    }
    printf("Dictionary loaded successfully\n\n");

    /* Run the processing pipeline that triggers the issue */
    printf("Testing text2mecab with long input...\n");
    text2mecab(buff, input_text);
    printf("  text2mecab: OK\n");

    printf("Testing Mecab_analysis...\n");
    Mecab_analysis(&ctx.mecab, buff);
    printf("  Mecab_analysis: OK\n");

    printf("Testing mecab2njd...\n");
    mecab2njd(&ctx.njd, Mecab_get_feature(&ctx.mecab), Mecab_get_size(&ctx.mecab));
    printf("  mecab2njd: OK\n");

    printf("Testing njd_set_pronunciation...\n");
    njd_set_pronunciation(&ctx.njd);
    printf("  njd_set_pronunciation: OK\n");

    printf("Testing njd_set_digit...\n");
    njd_set_digit(&ctx.njd);
    printf("  njd_set_digit: OK\n");

    printf("Testing njd_set_accent_phrase...\n");
    njd_set_accent_phrase(&ctx.njd);
    printf("  njd_set_accent_phrase: OK\n");

    printf("Testing njd_set_accent_type...\n");
    njd_set_accent_type(&ctx.njd);
    printf("  njd_set_accent_type: OK\n");

    printf("Testing njd_set_unvoiced_vowel...\n");
    njd_set_unvoiced_vowel(&ctx.njd);
    printf("  njd_set_unvoiced_vowel: OK\n");

    printf("Testing njd_set_long_vowel...\n");
    njd_set_long_vowel(&ctx.njd);
    printf("  njd_set_long_vowel: OK\n");

    printf("Testing njd2jpcommon...\n");
    njd2jpcommon(&ctx.jpcommon, &ctx.njd);
    printf("  njd2jpcommon: OK\n");

    printf("Testing JPCommon_make_label...\n");
    JPCommon_make_label(&ctx.jpcommon);
    printf("  JPCommon_make_label: OK\n");

    printf("\n");
    printf("SUCCESS: All tests passed!\n");
    printf("No segmentation fault occurred with %d repeated characters.\n", TEST_CHAR_COUNT);

    result = 0;

cleanup_ctx:
    test_clear(&ctx);

cleanup:
    if (input_text != NULL) free(input_text);
    if (buff != NULL) free(buff);

    return result;
}
