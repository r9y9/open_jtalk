#
# CMake configuration for open_jtalk
#
# adapted from https://gist.github.com/hkrn/889259/266e798f48a49d041d7f1e41a579d878134f1fca
cmake_minimum_required(VERSION 2.6)

# set library version
set(OPEN_JTALK_VERSION 1.11)
set(PACKAGE "open_jtalk")
set(PACKAGE_BUGREPORT "https://github.com/r9y9/open_jtalk/")
set(PACKAGE_NAME "open_jtalk")
set(PACKAGE_URL "")
set(PACKAGE_VERSION ${OPEN_JTALK_VERSION})
set(PACKAGE_STRING "${PACKAGE_NAME} ${PACKAGE_VERSION}")

# build configuration
project(openjtalk)
aux_source_directory(jpcommon libjpcommon_source)
aux_source_directory(mecab/src libmecab_source)
aux_source_directory(mecab2njd libmecab2njd_source)
aux_source_directory(njd libnjd_source)
aux_source_directory(njd2jpcommon libnjd2jpcommon_source)
aux_source_directory(njd_set_accent_phrase libnjd_set_accent_phrase_source)
aux_source_directory(njd_set_accent_type libnjd_set_accent_type_source)
aux_source_directory(njd_set_digit libnjd_set_digit_source)
aux_source_directory(njd_set_long_vowel libnjd_set_long_vowel_source)
aux_source_directory(njd_set_pronunciation libnjd_set_pronunciation_source)
aux_source_directory(njd_set_unvoiced_vowel libnjd_set_unvoiced_vowel_source)
aux_source_directory(text2mecab libtext2mecab_source)
include_directories(jpcommon mecab/src mecab2njd njd njd2jpcommon njd_set_accent_phrase
                    njd_set_accent_type njd_set_digit njd_set_long_vowel
                    njd_set_pronunciation njd_set_unvoiced_vowel text2mecab)

add_library(openjtalk ${libjpcommon_source} ${libmecab_source} ${libmecab2njd_source}
                      ${libnjd_source} ${libnjd2jpcommon_source}
                      ${libnjd_set_accent_phrase_source} ${libnjd_set_accent_type_source}
                      ${libnjd_set_digit_source} ${libnjd_set_long_vowel_source}
                      ${libnjd_set_pronunciation_source} ${libnjd_set_unvoiced_vowel_source}
                      ${libtext2mecab_source})
set_target_properties(openjtalk PROPERTIES VERSION ${OPEN_JTALK_VERSION})
set_target_properties(openjtalk PROPERTIES SO_VERSION ${OPEN_JTALK_VERSION})

# generate mecab/config.h
include(CheckIncludeFiles)
include(CheckFunctionExists)
include(CheckLibraryExists)
include(CheckTypeSize)
check_include_files(ctype.h HAVE_CTYPE_H)
check_include_files(dirent.h HAVE_DIRENT_H)
check_include_files(fcntl.h HAVE_FCNTL_H)
check_include_files(inttypes.h HAVE_INTTYPES_H)
check_include_files(io.h HAVE_IO_H)
check_include_files(memory.h HAVE_MEMORY_H)
check_include_files(setjmp.h HAVE_SETJMP_H)
check_include_files(stdint.h HAVE_STDINT_H)
check_include_files(stdlib.h HAVE_STDLIB_H)
check_include_files(strings.h HAVE_STRINGS_H)
check_include_files(string.h HAVE_STRING_H)
check_include_files(sys/mman.h HAVE_SYS_MMAN_H)
check_include_files(sys/stat.h HAVE_SYS_STAT_H)
check_include_files(sys/times.h HAVE_SYS_TIMES_H)
check_include_files(sys/types.h HAVE_SYS_TYPES_H)
check_include_files(unistd.h HAVE_UNISTD_H)
check_include_files(windows.h HAVE_WINDOWS_H)
check_function_exists(getenv HAVE_GETENV)
check_function_exists(getpagesize HAVE_GETPAGESIZE)
check_function_exists(mmap HAVE_MMAP)
check_function_exists(opendir HAVE_OPENDIR)
check_function_exists(setjmp HAVE_SETJMP)
check_function_exists(sqrt HAVE_SQRT)
check_function_exists(strstr HAVE_STRSTR)
check_library_exists(iconv iconv_open "" ICONV_CONST)
check_library_exists(m sqrt "" HAVE_LIBM)
check_type_size(char SIZEOF_CHAR)
check_type_size(int SIZEOF_INT)
check_type_size(long SIZEOF_LONG)
check_type_size("long long" SIZEOF_LONG_LONG)
check_type_size(short SIZEOF_SHORT)
check_type_size(size_t SIZEOF_SIZE_T)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/mecab/config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/mecab/src/config.h)
add_definitions(-DHAVE_CONFIG_H
                -DDIC_VERSION=102
                -DMECAB_DEFAULT_RC="dummy"
                -DMECAB_WITHOUT_SHARE_DIC
                -DPACKAGE="open_jtalk"
                -DVERSION="${OPEN_JTALK_VERSION}")

# whether build as a shared library or not
option(BUILD_SHARED_LIBS "Build Shared Libraries" OFF)
if(BUILD_SHARED_LIBS)
  set(LIB_TYPE SHARED)
else()
  set(LIB_TYPE STATIC)
endif()

# find HTSEngine
find_path(HTS_ENGINE_INCLUDE_DIR HTS_engine.h)
find_library(HTS_ENGINE_LIB hts_engine_API)
if(NOT HTS_ENGINE_LIB)
  # fallback
  find_library(HTS_ENGINE_LIB HTSEngine)
endif()

if(HTS_ENGINE_INCLUDE_DIR AND HTS_ENGINE_LIB)
  target_link_libraries(openjtalk ${HTS_ENGINE_LIB})
  include_directories(openjtalk ${HTS_ENGINE_INCLUDE_DIR})
else()
  message(FATAL_ERROR "Required HTSEngine not found")
endif()

# configuration for charset
#option(CHARSET "Encoding set for mecab" "eucjp")
set(CHARSET "utf8")

if(${CHARSET} STREQUAL "sjis")
  add_definitions(-DCHARSET_SHIFT_JIS -DMECAB_CHARSET=sjis)
  foreach(flag CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)
    set(${flag} "${${flag}} -finput-charset=cp932 -fexec-charset=cp932")
  endforeach()
  target_compile_options(openjtalk
    PRIVATE $<$<C_COMPILER_ID:MSVC>:/source-charset:.932;/execution-charset:.932>
  )
elseif(${CHARSET} STREQUAL "eucjp")
  add_definitions(-DCHARSET_EUC_JP -DMECAB_CHARSET=euc-jp)
  target_compile_options(openjtalk
    PRIVATE $<$<C_COMPILER_ID:MSVC>:/source-charset:euc-jp;/execution-charset:euc-jp>
  )
elseif(${CHARSET} STREQUAL "utf8")
  add_definitions(-DCHARSET_UTF_8 -DMECAB_CHARSET=utf-8 -DMECAB_UTF8_USE_ONLY)
  foreach(flag CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)
    set(${flag} "${${flag}} -finput-charset=UTF-8 -fexec-charset=UTF-8")
  endforeach()
  target_compile_options(openjtalk
    PRIVATE $<$<C_COMPILER_ID:MSVC>:/source-charset:UTF-8;/execution-charset:UTF-8>
  )
else()
  message(FATAL_ERROR "Encoding ${CHARSET} not recognized. You can set sjis/eucjp/utf8")
endif()

# installation
if(NOT MSVC)
  install(TARGETS openjtalk DESTINATION lib)
  install(FILES jpcommon/jpcommon.h mecab/src/mecab.h mecab2njd/mecab2njd.h njd/njd.h njd2jpcommon/njd2jpcommon.h
          njd_set_accent_phrase/njd_set_accent_phrase.h njd_set_accent_type/njd_set_accent_type.h
          njd_set_digit/njd_set_digit.h njd_set_long_vowel/njd_set_long_vowel.h njd_set_pronunciation/njd_set_pronunciation.h
          njd_set_unvoiced_vowel/njd_set_unvoiced_vowel.h text2mecab/text2mecab.h
          DESTINATION include/openjtalk)
endif()
