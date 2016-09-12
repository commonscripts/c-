#include <iostream>
#include <cassert>
#include <string.h>
#include <iconv.h>
#include <cstdlib>
#include "CommonTools.h"
#include "Ebk2Limits.h"
#include "zlib.h"

using namespace std;

namespace ebk2totxt_v1_hjf
{
    void CommonTools::copyMove(void *dst, const char **src, size_t n)
    {       
        assert(dst && src && (*src));

        memcpy(dst, *src, n);
        *src += n;
    }

    void *CommonTools::bigToLittleEndian(void *dst, const void *src, size_t n)
    {
        char *d, *s;

        assert(dst && src);
        d = (char *)dst;
        s = (char *)src + n - 1;

        while(s >= (char *)src)
        {
            *d++ = *s--;
        }

        return dst;
    }

    void *CommonTools::codeConvert(const char *from_charset, const char *to_charset,
                                   const char *in, size_t inlen, char *out, size_t outlen)
    {
        assert(from_charset && to_charset && in && out);

        int             rc; 
        iconv_t         cd;
        char          **pout = &out;
        const char    **pin = &in;      

        cd = iconv_open(to_charset, from_charset);
        if(cd == (iconv_t)-1)
        {
            cout<<"get error cd: "<<cd<<endl;
            exit(EXIT_FAILURE);
        }

        memset(out, 0, outlen);

        rc = iconv(cd, pin, &inlen, pout, &outlen);
        if(rc == -1)
        {
            cout<<"convert faild: "<<rc<<endl;
            exit(EXIT_FAILURE);
        }

        iconv_close(cd);
    }

    void CommonTools::unCompress(const char *src, int src_len, char *dst, int *uncompr_size)
    {
        int    rc;

        dst = NULL;
        dst = (char *)malloc(TEMP_BUFFER_SIZE);
        if(dst == NULL)
        {
            cout<<"no enough memory!"<<endl;
        }

        memset(dst, 0, TEMP_BUFFER_SIZE);

        rc = uncompress((Bytef *)dst, (uLongf *)uncompr_size, (const Bytef *)src, (uLong)src_len);
        if(rc != Z_OK)
        {
            cout<<"uncompress failed: "<<rc<<endl;
            exit(EXIT_FAILURE);
        }
    }
}

