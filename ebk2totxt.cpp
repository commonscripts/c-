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
    public:
        static void copyMove(void *dst, void *src, size_t n)
        {
            if(dst)
            {
                memcpy(dst, src, n);

                src = (char *)src + n;
            }
        }

        static void *bigToLittleEndian(void *dst, const void *src, size_t n)
        {
            char *d, *s;

            d = (char *)dst;
            s = (char *)src + n - 1;

            while(s >= (char *)src)
            {
                *d++ = *s--; 
            }
        
            return dst;
        }
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
            this->txt_compress_size = 0;

            memset(this->book_name, 0, sizeof(this->book_name));
        }

        TextStruct(char * buffer)
        {
            char *p = buffer;

            //BytesToStruct.copyMove(&(this->book_id), p, 4);
            //BytesToStruct.copyMove(&(this->head_data_size), p, 2); 
            //BytesToStruct.copyMove(&(this->ebk_version), p, 2);
            //BytesToStruct.copyMove(&(this->ebk_size), p, 4);
            //BytesToStruct.copyMove(&(this->book_name), p, 64);
            //BytesToStruct.copyMove(&(this->file_size), p, 4);
            //BytesToStruct.copyMove(&(this->head_compress_size), p, 4);
            //BytesToStruct.copyMove(&(this->first_compress_block_size), p, 4);
            //BytesToStruct.copyMove(&(this->chapter_count), p, 2);
            //BytesToStruct.copyMove(&(this->compress_block_count), p, 2);
            //BytesToStruct.copyMove(&(this->media_count), p, 4);
            //BytesToStruct.copyMove(&(this->media_data_length), p, 4);
            //BytesToStruct.copyMove(&(this->txt_compress_size), p, 4);
        }

        void displayHead()
        {
            cout<<"book info:"<<endl;
            cout<<"book_id: "<<this->book_id<<endl;
            cout<<"head_data_size: "<<this->head_data_size<<endl;
            cout<<"ebk_version: "<<this->ebk_version<<endl;
            cout<<"ebk_size: "<<this->ebk_size<<endl;
            cout<<"book_name: "<<this->book_name<<endl;
            cout<<"file_size: "<<this->file_size<<endl;
            cout<<"head_compress_size: "<<this->head_compress_size<<endl;
            cout<<"first_compress_block_size: "<<this->first_compress_block_size<<endl;
            cout<<"chapter_count: "<<this->chapter_count<<endl;
            cout<<"compress_block_count: "<<this->compress_block_count<<endl;
            cout<<"media_count: "<<this->media_count<<endl;
            cout<<"media_data_length: "<<this->media_data_length<<endl;
            cout<<"txt_compress_size: "<<this->txt_compress_size<<endl;
        }
};


int main(int argc, char * argv[])
{
    char       *file_path;
    long        file_size;
    char       *buffer; 
    streampos   pos;

    file_path = argv[1];
    file_size = 0;
    pos = 0;

    ifstream fin;
    fin.open(file_path, ios::in|ios::binary);

    fin.seekg(0, ios::end);
    pos = fin.tellg();
    file_size = pos;
    fin.seekg(0, ios::beg);
    
    buffer = new char[file_size];
    memset(buffer, 0, file_size);
        
    fin.read(buffer, file_size);

    TextStruct tst(buffer);
    tst.displayHead();


    return 0;
}


