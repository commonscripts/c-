#ifndef __COMMONTOOLS_H__
#define __COMMONTOOLS_H__

namespace ebk2totxt_v1_hjf
{
    class CommonTools
    {
        public:
            static void copyMove(void *dst, const char **src, size_t n);
            static void *bigToLittleEndian(void *dst, const void *src, size_t n);
            static void *codeConvert(const char *from_charset, const char *to_charset,
                                     const char *in, size_t inlen, char *out, size_t outlen);
            static void unCompress(const char *src, int src_len, char *dst, int *uncompr_size);
    };
}

#endif __COMMONTOOLS_H__

