#include <iostream>
#include "Ebk2Limits.h"
#include "Chapters.h"
#include "CommonTools.h"

namespace ebk2totxt_v1_hjf
{
    void CompressChapter::initCompressChapter()
    {
        offset = 0;
        length = 0;
        chapter_count = 0;
    }

    CompressChapter::CompressChapter()
    {
        CompressChapter::initCompressChapter();
    }

    CompressChapter::CompressChapter(int offset, int length, int chapter_count)
    {
        this->offset = offset;
        this->length = length;
        this->chapter_count = chapter_count;
    }

    int CompressChapter::getOffset()
    {
        return offset;
    }

    int  CompressChapter::getLength()
    {
        return length;
    }

    int CompressChapter::getChapter_count()
    {
        return chapter_count;
    }

    CompressChapter::~CompressChapter()
    {

    }


    void UnCompressChapter::initUnCompressChapter()
    {
        index = 0;
        length = 0;

        memset(chapter_name, 0, sizeof(chapter_name));
        memset(chapter_name_utf8, 0, sizeof(chapter_name_utf8));
    }

    UnCompressChapter::UnCompressChapter()
    {
        UnCompressChapter::initUnCompressChapter();
    }

    UnCompressChapter::UnCompressChapter(char *chapter_name, int index, int length)
    {
        this->index = index;
        this->length = length;
        memcpy(this->chapter_name, chapter_name, strlen(chapter_name));
       
        ebk2totxt_v1_hjf::CommonTools::codeConvert("UTF16LE", "UTF8",
                                                   this->chapter_name, (size_t)(strlen(chapter_name)),
                                                   chapter_name_utf8, (size_t)(sizeof(chapter_name_utf8)));
    }

    char *UnCompressChapter::getChapterName(bool origin_name)
    {
        return origin_name ? chapter_name : chapter_name_utf8;
    }

    int UnCompressChapter::getIndex()
    {
        return index;
    }

    int UnCompressChapter::getLength()
    {
        return length;
    }

    UnCompressChapter::~UnCompressChapter()
    {

    }


    Chapters::Chapters()
    {
    
    }

    Chapters::Chapters(int offset, int length, int chapter_count, const char *buf)
    {
        this->offset = offset;
        this->length = length;
        this->chapter_count = chapter_count;
        this->buf = buf;
        this->uncompr_chr_data_size = 0;
        this->uncompr_chr_data = new char[TEMP_BUFFER_SIZE];

        uncompressCompressChapters();
        addUnCompressChapter();
    }

    void Chapters::uncompressCompressChapters()
    {   
        ebk2totxt_v1_hjf::CommonTools::unCompress((const char *)(buf + offset), length,
                                                  uncompr_chr_data, &uncompr_chr_data_size);
    }

    bool Chapters::addUnCompressChapter()
    {
        int i;
        char *p = uncompr_chr_data;
        for(i = 0; i < chapter_count; i++)
        {
            UnCompressChapter uncomprchr("adf", 1, 1);
            
            uncomprchrlist.push_back(uncomprchr);                
        }               
    }

    void Chapters::displayChapters()
    {
        list<UnCompressChapter>::iterator uncompr_itr;
        uncompr_itr = uncomprchrlist.begin();

        cout<<"chapters info: "<<endl;

        for(/* void */; uncompr_itr != uncomprchrlist.end(); uncompr_itr++)
        {
            cout<<"  chapter name: "<<uncompr_itr->getChapterName(false)<<endl;
            cout<<"  chapter index: "<<uncompr_itr->getIndex()<< endl;
            cout<<"  chapter length: "<<uncompr_itr->getLength()<< endl;
        }
    }

    Chapters::~Chapters()
    {
        delete(uncompr_chr_data);
    }
}

