#include <cassert>
#include "Ebk2FileHeader.h"

using namespace std;

namespace ebk2totxt_v1_hjf
{
    void Ebk2FileHeader::initEbk2FileHeader()
    {
        book_id = 0;
        head_data_size = 0;
        ebk_version = 0;
        ebk_size = 0;
        file_size = 0;
        head_compress_size = 0;
        first_compress_block_size = 0;
        chapter_count = 0;
        compress_block_count = 0;
        media_count = 0;
        media_data_length = 0;
        txt_compress_size = 0;

        memset(book_name, 0, sizeof(book_name));
        memset(book_name_utf8, 0, sizeof(book_name_utf8));
    }

    Ebk2FileHeader::Ebk2FileHeader()
    {
        Ebk2FileHeader::initEbk2FileHeader();
    }

    Ebk2FileHeader::Ebk2FileHeader(const char *buf)
    {
        assert(buf);
        const char **p = &buf;
        Ebk2FileHeader::initEbk2FileHeader();

        ebk2totxt_v1_hjf::CommonTools::copyMove(&book_id, p, 4);
        ebk2totxt_v1_hjf::CommonTools::copyMove(&head_data_size, p, 2);
        ebk2totxt_v1_hjf::CommonTools::copyMove(&ebk_version, p, 2);
        ebk2totxt_v1_hjf::CommonTools::copyMove(&ebk_size, p, 4);
        ebk2totxt_v1_hjf::CommonTools::copyMove(&book_name, p, 64);
        ebk2totxt_v1_hjf::CommonTools::copyMove(&file_size, p, 4);
        ebk2totxt_v1_hjf::CommonTools::copyMove(&head_compress_size, p, 4);
        ebk2totxt_v1_hjf::CommonTools::copyMove(&first_compress_block_size, p, 4);
        ebk2totxt_v1_hjf::CommonTools::copyMove(&chapter_count, p, 2);
        ebk2totxt_v1_hjf::CommonTools::copyMove(&compress_block_count, p, 2);
        ebk2totxt_v1_hjf::CommonTools::copyMove(&media_count, p, 4);
        ebk2totxt_v1_hjf::CommonTools::copyMove(&media_data_length, p, 4);
        ebk2totxt_v1_hjf::CommonTools::copyMove(&txt_compress_size, p, 4);
        
        ebk2totxt_v1_hjf::CommonTools::codeConvert("UTF16LE", "UTF8",
                                                   book_name, (size_t)(strlen(book_name)),
                                                   book_name_utf8, (size_t)(sizeof(book_name_utf8)));
    }

    int Ebk2FileHeader::getBook_id()
    {
        return book_id;
    }

    int Ebk2FileHeader::getHead_data_size()
    {
        return head_data_size;
    }

    int Ebk2FileHeader::getEbk_version()
    {
        return ebk_version;
    }

    int Ebk2FileHeader::getEbk_size()
    {
        return ebk_size;
    }

    char *Ebk2FileHeader::getBook_name(bool origin_name)
    {
        return origin_name ? book_name : book_name_utf8;
    }

    int Ebk2FileHeader::getFile_size()
    {
        return file_size;
    }

    int Ebk2FileHeader::getHead_compress_size()
    {
        return head_compress_size;
    }

    int Ebk2FileHeader::getFirst_compress_block_size()
    {
        return first_compress_block_size;
    }

    int Ebk2FileHeader::getChapter_count()
    {
        return chapter_count;
    }

    int Ebk2FileHeader::getCompress_block_count()
    {
        return compress_block_count;
    }

    int Ebk2FileHeader::getMedia_count()
    {
        return media_count;
    }

    int Ebk2FileHeader::getMedia_data_length()
    {
        return media_data_length;
    }

    int Ebk2FileHeader::getTxt_compress_size()
    {
        return txt_compress_size;    
    }

    void Ebk2FileHeader::displayEbk2FileHeader(bool origin_name)
    {
        cout<<"book info: "<<endl;
        cout<<"book_id: "<<book_id<<endl;
        cout<<"head_data_size: "<<head_data_size<<endl;
        cout<<"ebk_version: "<<ebk_version<<endl;
        cout<<"ebk_size: "<<ebk_size<<endl;
        cout<<"book_name: "<<(origin_name ? book_name : book_name_utf8)<<endl;
        cout<<"file_size: "<<file_size<<endl;
        cout<<"head_compress_size: "<<head_compress_size<<endl;
        cout<<"first_compress_block_size: "<<first_compress_block_size<<endl;
        cout<<"chapter_count: "<<chapter_count<<endl;
        cout<<"compress_block_count: "<<compress_block_count<<endl;
        cout<<"media_count: "<<media_count<<endl;
        cout<<"media_data_length: "<<media_data_length<<endl;
        cout<<"txt_compress_size: "<<txt_compress_size<<endl;
    }

    Ebk2FileHeader::~Ebk2FileHeader()
    {
    
    }
}
 
