/*
 * SimpleHash.cpp
 *
 *  Created on: 2014年5月20日
 *      Author: Jayin Ton
 */

#include "SimpleHash.h"

/*key为一个字符串，nTableLength为哈希表的长度
 *
 */
unsigned long getHashIndex(const char *key, int nTableLength) {
	unsigned long nHash = 0;

	while (*key) {
		nHash = (nHash << 5) + nHash + *key++;
	}

	return (nHash % nTableLength);
}

/**
 * hash a string into integer
 * using java's hashCode() implementation
 */
unsigned long hash_string(const char * str, unsigned long len) {
	unsigned long hash = 0;
	unsigned long i;
	for (i = 0; i < len; i++) {
		hash = 31 * hash + (unsigned char) str[i];
	}

	return hash;
}
/**see: http://www.isthe.com/chongo/tech/comp/fnv/index.html#FNV-1a */
unsigned long hash_fnv1a(const char * str, unsigned long len) {
	unsigned long prime = 16777619U;
	unsigned long hash = 2166136261U;

	for (unsigned long i = 0; i < len; i++) {
		hash = hash ^ str[i];
		hash = hash * prime;
	}
	return hash;
}
