/*
 * SimpleHash.cpp
 *
 *  Created on: 2014年5月20日
 *      Author: Jayin Ton
 */

#include "SimpleHash.h"

/*key为一个字符串，nTableLength为哈希表的长度
 *该函数得到的hash值分布比较均匀*/
unsigned long getHashIndex(const char *key, int nTableLength) {
	unsigned long nHash = 0;

	while (*key) {
		nHash = (nHash << 5) + nHash + *key++;
	}

	return (nHash % nTableLength);
}

