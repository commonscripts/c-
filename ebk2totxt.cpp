#include <iostream>
#include <fstream>
#include <list>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <iconv.h>
#include <zlib.h>

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

        void initBookItems()
        {
            name = "";
            index = 0;
            length = 0;
        }

        BookItems()
        {
            initBookItems();
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

        void initBookInfo()
        {
            text = "";
            bookname = "";
            memset(pic, 0, sizeof(pic));
        }

        BookInfo()
        {
            initBookInfo();
        }
};


class BytesToStruct
{
    public:
        static void copyMove(void *dst, char **src, size_t n)
        {
            assert(dst != NULL and src != NULL and *src != NULL);

            memcpy(dst, *src, n);
            *src += n;
        }

        static void *bigToLittleEndian(void *dst, const void *src, size_t n)
        {
            char *d, *s;

            assert(dst != NULL and src != NULL);

            d = (char *)dst;
            s = (char *)src + n - 1;

            while(s >= (char *)src)
            {
                *d++ = *s--; 
            }
        
            return dst;
        }

        static void *codeConvert(const char *from_charset, const char *to_charset,
                                 char *in, size_t inlen, char *out, size_t outlen)
        {
            assert(from_charset && to_charset && in && out);

            int rc;
            iconv_t cd;
            char **pin = &in;
            char **pout = &out;

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
                cout<<"convert faild!"<<endl;
                exit(EXIT_FAILURE);
            }    
                
            iconv_close(cd);
        }
 
        static void unCompress(const char *src, long src_len, char *dst)
        {
            int   rc;
            long  dst_len;

            dst = NULL;
            dst_len = compressBound(src_len);
            dst = (char *)malloc(dst_len);
            if(dst = NULL)
            {
                cout<<"no enough memory!"<<endl;
            }

            memset(dst, 0, dst_len);

            rc = uncompress((Bytef *)dst, (uLongf *)&dst_len, (Bytef *)src, (uLong)src_len);
            if(rc != Z_OK)
            {
                cout<<"uncompress failed!"<<endl;
                exit(EXIT_FAILURE);
            }
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
            media_type = 0;
            offset = 0;
            data_offset = 0;
            length = 0;
        }
};


class ChapterCompress
{
    public:
        int offset;
        int length;

        ChapterCompress()
        {
            offset = 0;
            length = 0;
        }

        ChapterCompress(int offset, int length)
        {
            this->offset = offset;
            this->length = length;
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
            offset = 0;
            length = 0;
            memset(chapter_name, 0 , sizeof(chapter_name));
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
            CATHY_LZ77_WINDOW_SIZE = 65536;
            CATHYEBK_CHAPTER_NAME_MAX_SIZE = 64;
            CATHYEBK_TXT_FILE_MAX_SIZE = 10485760;
            CATHYEBK_VERSION = 2;
            CATHYEBK_NAME_MAX_SIZE = 64;

            memset(bookbuf, 0 , sizeof(bookbuf));
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

        char book_name_utf8[256];

        void initTextStruct()
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

        TextStruct()
        {
            initTextStruct();
        }

        TextStruct(char * buffer)
        {
            char **p = &buffer;

            initTextStruct();

            BytesToStruct::copyMove(&book_id, p, 4);
            BytesToStruct::copyMove(&head_data_size, p, 2); 
            BytesToStruct::copyMove(&ebk_version, p, 2);
            BytesToStruct::copyMove(&ebk_size, p, 4);
            BytesToStruct::copyMove(&book_name, p, 64);
            BytesToStruct::copyMove(&file_size, p, 4);
            BytesToStruct::copyMove(&head_compress_size, p, 4);
            BytesToStruct::copyMove(&first_compress_block_size, p, 4);
            BytesToStruct::copyMove(&chapter_count, p, 2);
            BytesToStruct::copyMove(&compress_block_count, p, 2);
            BytesToStruct::copyMove(&media_count, p, 4);
            BytesToStruct::copyMove(&media_data_length, p, 4);
            BytesToStruct::copyMove(&txt_compress_size, p, 4);

            BytesToStruct::codeConvert("UTF16LE", "UTF8", book_name, (size_t)(strlen(book_name)), book_name_utf8, (size_t)(sizeof(book_name_utf8)));
        }

        void displayHead()
        {
            cout<<"book info:"<<endl;
            cout<<"book_id: "<<book_id<<endl;
            cout<<"head_data_size: "<<head_data_size<<endl;
            cout<<"ebk_version: "<<ebk_version<<endl;
            cout<<"ebk_size: "<<ebk_size<<endl;
            cout<<"book_name: "<<book_name_utf8<<endl;
            cout<<"file_size: "<<file_size<<endl;
            cout<<"head_compress_size: "<<head_compress_size<<endl;
            cout<<"first_compress_block_size: "<<first_compress_block_size<<endl;
            cout<<"chapter_count: "<<chapter_count<<endl;
            cout<<"compress_block_count: "<<compress_block_count<<endl;
            cout<<"media_count: "<<media_count<<endl;
            cout<<"media_data_length: "<<media_data_length<<endl;
            cout<<"txt_compress_size: "<<txt_compress_size<<endl;
        }
};


int main(int argc, char * argv[])
{
    char       *file_path;
    long        file_size;
    char       *buffer, *uncompressed_chapter; 
    streampos   posStart, posEnd;

    file_path = argv[1];
    file_size = 0;
    posStart = 0;
    posEnd = 0;

    assert(file_path);
    ifstream fin;
    fin.open(file_path, ios::in|ios::binary);

    fin.seekg(0, ios::end);
    posEnd = fin.tellg();
    fin.seekg(0, ios::beg);
    posStart = fin.tellg();

    file_size = posEnd - posStart;
    buffer = new char[file_size];
    memset(buffer, 0, file_size);
        
    fin.read(buffer, file_size);
    fin.close();

    TextStruct tst(buffer);
    tst.displayHead();

    ChapterCompress chaptercompress(144, tst.head_compress_size);
    //BytesToStruct::unCompress(buffer + chaptercompress.offset, chaptercompress.length, uncompressed_chapter);


    return EXIT_SUCCESS;
}


