#include <iostream>

#include <string>
#include <list>

#include <fstream>

#include <string.h>


using namespace std;


class BookItems
{
    private:
        string name;
        int index;
        int length;

    public:
        void setName(string name)
        {
            this->name = name;
        }
        string getName()
        {
            return this->name;
        }

        void setIndex(int index)
        {
            this->index = index;
        }
        int getIndex()
        {
            return this->index;
        }

        void setLength(int length)
        {
            this->length = length;
        }
        int getLength()
        {
            return this->length;
        }

        BookItems()
        {
            this->name = "";
            this->index = 0;
            this->length = 0;
        }
        
        BookItems(string name, int index, int length)
        {
            this->name = name;
            this->index = index;
            this->length = length;
        }
};


class BookInfo
{
    private:
        list<BookItems> chapterlist;
        string text;
        char pic[1048576];
        string bookname;

    public:
        void setText(string text)
        {
            this->text = text;
        }
        string getText()
        {
            return this->text;
        }

        void setBookname(string bookname)
        {
            this->bookname = bookname;
        }
        string getBookname()
        {
            return this->bookname;
        }

        BookInfo()
        {
            this->text = "";
            this->bookname = "";
            memset(this->pic, 0, sizeof(this->pic));
        }
};


class BytesToStruct
{


};


class CATHYEBK_MEDIA_DATA_T
{
    public:
        int media_type;
        int offset;
        int data_offset;
        int length;

        CATHYEBK_MEDIA_DATA_T()
        {
            this->media_type = 0;
            this->offset = 0;
            this->data_offset = 0;
            this->length = 0;
        }
};


class ChapterCompress
{
    public:
        int offset;
        int length;

        ChapterCompress()
        {
            this->offset = 0;
            this->length = 0;
        }
};


class ChapterStruct
{
    public:
        char chapter_name[64];
        int offset;
        int length;

        ChapterStruct()
        {
            memset(this->chapter_name, 0 , sizeof(this->chapter_name));
        }
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

            memset(this->bookbuf, 0 , sizeof(this->bookbuf));
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

        TextStruct()
        {
            this->book_id = 0;
            this->head_data_size = 0;
            this->ebk_version = 0;
            this->ebk_size = 0;
            this->file_size = 0;
            this->head_compress_size = 0;
            this->first_compress_block_size = 0;
            this->chapter_count = 0;
            this->compress_block_count = 0;
            this->media_count = 0;
            this->media_data_length = 0;

            memset(this->book_name, 0, sizeof(this->book_name));
        }
};


int main(int argc, char * argv[])
{
    char       *file_path;
    long        file_size;
    char        buffer[1048576];    

    file_path = argv[1];
    file_size = 0;
    memset(buffer, 0, sizeof(buffer));

    ifstream fin;
    fin.open(file_path, ios::in|ios::binary);
    fin.read(buffer, sizeof(buffer));

    //file_size = strlen(buffer);

    return 0;
}


