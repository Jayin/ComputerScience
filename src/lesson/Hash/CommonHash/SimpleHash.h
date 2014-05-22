/*
 * SimpleHash.h
 *
 *  Created on: 2014年5月20日
 *      Author: Jayin Ton
 */

#ifndef SIMPLEHASH_H_
#define SIMPLEHASH_H_

unsigned long getHashIndex(const char *key, int nTableLength);
unsigned long hash_string(const char * str, unsigned long len);
unsigned long hash_fnv1a(const char * str, unsigned long len);

#endif /* SIMPLEHASH_H_ */
