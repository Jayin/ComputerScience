/*
 * SimpleHash.h
 *
 *  Created on: 2014年5月20日
 *      Author: Jayin Ton
 */

#ifndef SIMPLEHASH_H_
#define SIMPLEHASH_H_

/*key为一个字符串，nTableLength为哈希表的长度
 *
 */
static unsigned long getHashIndex(const char *key, int nTableLength) {
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
static unsigned long hash_string(const char * str, unsigned long len) {
	unsigned long hash = 0;
	unsigned long i;
	for (i = 0; i < len; i++) {
		hash = 31 * hash + (unsigned char) str[i];
	}

	return hash;
}
/**see: http://www.isthe.com/chongo/tech/comp/fnv/index.html#FNV-1a */
static unsigned long hash_fnv1a(const char * str, unsigned long len) {
	unsigned long prime = 16777619U;
	unsigned long hash = 2166136261U;

	for (unsigned long i = 0; i < len; i++) {
		hash = hash ^ str[i];
		hash = hash * prime;
	}
	return hash;
}

static unsigned int SDBMHash(const char *str)
{
    unsigned int hash = 0;

    while (*str)
    {
        // equivalent to: hash = 65599*hash + (*str++);
        hash = (*str++) + (hash << 6) + (hash << 16) - hash;
    }

    return (hash & 0x7FFFFFFF);
}

// RS Hash Function
static unsigned int RSHash(const char *str)
{
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;

    while (*str)
    {
        hash = hash * a + (*str++);
        a *= b;
    }

    return (hash & 0x7FFFFFFF);
}

// JS Hash Function
static unsigned int JSHash(const char *str)
{
    unsigned int hash = 1315423911;

    while (*str)
    {
        hash ^= ((hash << 5) + (*str++) + (hash >> 2));
    }

    return (hash & 0x7FFFFFFF);
}

// P. J. Weinberger Hash Function
static unsigned int PJWHash(const char *str)
{
    unsigned int BitsInUnignedInt = (unsigned int)(sizeof(unsigned int) * 8);
    unsigned int ThreeQuarters    = (unsigned int)((BitsInUnignedInt  * 3) / 4);
    unsigned int OneEighth        = (unsigned int)(BitsInUnignedInt / 8);
    unsigned int HighBits         = (unsigned int)(0xFFFFFFFF) << (BitsInUnignedInt - OneEighth);
    unsigned int hash             = 0;
    unsigned int test             = 0;

    while (*str)
    {
        hash = (hash << OneEighth) + (*str++);
        if ((test = hash & HighBits) != 0)
        {
            hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
        }
    }

    return (hash & 0x7FFFFFFF);
}

// ELF Hash Function
static unsigned int ELFHash(const char *str)
{
    unsigned int hash = 0;
    unsigned int x    = 0;

    while (*str)
    {
        hash = (hash << 4) + (*str++);
        if ((x = hash & 0xF0000000L) != 0)
        {
            hash ^= (x >> 24);
            hash &= ~x;
        }
    }

    return (hash & 0x7FFFFFFF);
}

// BKDR Hash Function
static unsigned int BKDRHash(const char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;

    while (*str)
    {
        hash = hash * seed + (*str++);
    }

    return (hash & 0x7FFFFFFF);
}

// DJB Hash Function
static unsigned int DJBHash(const char *str)
{
    unsigned int hash = 5381;

    while (*str)
    {
        hash += (hash << 5) + (*str++);
    }

    return (hash & 0x7FFFFFFF);
}

// AP Hash Function
static unsigned int APHash(const char *str)
{
    unsigned int hash = 0;
    int i;

    for (i=0; *str; i++)
    {
        if ((i & 1) == 0)
        {
            hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));
        }
        else
        {
            hash ^= (~((hash << 11) ^ (*str++) ^ (hash >> 5)));
        }
    }

    return (hash & 0x7FFFFFFF);
}

#endif /* SIMPLEHASH_H_ */
