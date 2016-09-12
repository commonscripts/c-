#ifndef __CHAPTERS__
#define __CHAPTERS__

#include <list>

using namespace std;
 
namespace ebk2totxt_v1_hjf
{
    class CompressChapter
    {
        private:
            int offset;
            int length;
            int chapter_count;

            void initCompressChapter();

        public:

            CompressChapter();
            CompressChapter(int offset, int length, int chapter_count);

            int getOffset();
            int getLength();
            int getChapter_count();

            ~CompressChapter();
    };

    class UnCompressChapter
    {
        private:
            char chapter_name[MAX_NAME_SIZE];
            char chapter_name_utf8[MAX_NAME_SIZE * 3];
            int index;
            int length;

            void initUnCompressChapter();
            
        public:
            UnCompressChapter();
            UnCompressChapter(char *chapter_name, int index, int length);

            char *getChapterName(bool origin_name);
            int getIndex();
            int getLength();
                            
            ~UnCompressChapter();
    };

    class Chapters
    {
        private:
            int offset, length, chapter_count;
            const char *buf;
            int uncompr_chr_data_size;
            char *uncompr_chr_data = NULL;
            CompressChapter comprchr = CompressChapter(offset, length, chapter_count);
            list<UnCompressChapter> uncomprchrlist;

            void uncompressCompressChapters();
            bool addUnCompressChapter();
            
        public:
            Chapters();
            Chapters(int offset, int length, int chapter_count, const char *buf);

            void displayChapters();

            ~Chapters();
    };
}

#endif

