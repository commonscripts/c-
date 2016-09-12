#ifndef __EBK2FILEHEADER_H__
#define __EBK2FILEHEADER_H__

#include <iostream>
#include "Ebk2Limits.h"
#include "CommonTools.h"

namespace ebk2totxt_v1_hjf
{
    class Ebk2FileHeader
    {
        private:
            int   book_id;
            int   head_data_size;
            int   ebk_version;
            int   ebk_size;
            char  book_name[MAX_NAME_SIZE];
            int   file_size;
            int   head_compress_size;
            int   first_compress_block_size;
            int   chapter_count;
            int   compress_block_count;
            int   media_count;
            int   media_data_length;
            int   txt_compress_size;

            char  book_name_utf8[MAX_NAME_SIZE * 3];

            void initEbk2FileHeader();

        public:
            Ebk2FileHeader();
            Ebk2FileHeader(const char * buf);

            int getBook_id();
            int getHead_data_size();
            int getEbk_version();
            int getEbk_size();
            char *getBook_name(bool origin_name);
            int getFile_size();
            int getHead_compress_size();
            int getFirst_compress_block_size();
            int getChapter_count();
            int getCompress_block_count();
            int getMedia_count();
            int getMedia_data_length();
            int getTxt_compress_size();

            void displayEbk2FileHeader(bool origin_name);

            ~Ebk2FileHeader();  
    };
}

#endif


