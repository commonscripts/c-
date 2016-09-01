#include <iostream>
#include <string>
#include <list>

using namespace std;


class BookInfo
{


};


class BookItems
{


};


class BytesToStruct
{


};


class CATHYEBK_MEDIA_DATA_T
{

};


class ChapterCompress
{


};


class ChapterStruct
{
    public:
        char chapter_name[64];
        int offset;
        int length;
};


class Ebk2Open
{


};


class Model
{
    public:
        int CATHY_LZ77_WINDOW_SIZE;
        list<string> correctchapterlist;
        char bookbuf[1048576];
        int CATHYEBK_CHAPTER_NAME_MAX_SIZE;
        int CATHYEBK_TXT_FILE_MAX_SIZE;
        int CATHYEBK_VERSION;
        int CATHYEBK_NAME_MAX_SIZE;

        Model()
        {
            this->CATHY_LZ77_WINDOW_SIZE = 65536;
            this->CATHYEBK_CHAPTER_NAME_MAX_SIZE = 64;
            this->CATHYEBK_TXT_FILE_MAX_SIZE = 10485760;
            this->CATHYEBK_VERSION = 2;
            this->CATHYEBK_NAME_MAX_SIZE = 64;
        }
};


class TextStruct
{
    public:
        int book_id;
        int head_data_size;
        int ebk_version;
        int ebk_size;
        char book_name[64];
        int file_size;
        int head_compress_size;
        int first_compress_block_size;
        int chapter_count;
        int compress_block_count;
        int media_count;
        int media_data_length;
        int txt_compress_size;
};


int main(int argc, char * argv[])
{


    return 0;
}


