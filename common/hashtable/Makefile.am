
AM_CPPFLAGS =  -g

LIBS = 

noinst_LIBRARIES = libhashmap.a libHashTable.a
libhashmap_a_SOURCES = ctool_hashmap.c
libhashmap_a_LIBADD = 

libHashTable_a_SOURCES = HashTable.cpp
libHashTable_a_LIBADD = 

noinst_PROGRAMS = ctool_hashmap_tools  HashTable_test
ctool_hashmap_tools_SOURCES = ctool_hashmap_tools.cc
ctool_hashmap_tools_LDADD = libhashmap.a

HashTable_test_SOURCES = Hashtable-test.cpp
HashTable_test_LDADD = libHashTable.a

